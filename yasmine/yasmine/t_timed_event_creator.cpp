//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_timed_event_creator.h"

#include <algorithm>

#include "t_event_creation_request.h"
#include "t_state_machine.h"
#include "base.h"
#include "t_event.h"
#include "t_log_and_throw.h"
#include "t_event_with_parameters.h"


#include <random>


namespace sxy
{


t_timed_event_creator::t_timed_event_creator( t_state_machine& p_state_machine )
	: m_state_machine( p_state_machine ),
		m_event_creation_requests(),
		m_worker(),
		m_mutex(),
		m_condition_variable(),
		m_run( true )
{
	// Nothing to do...
}


t_timed_event_creator::~t_timed_event_creator()
{
	Y_ASSERT( !m_run, "Thread is still running! It was not stopped." );
	Y_ASSERT( !m_worker, "The thread still exists!" );
}


int t_timed_event_creator::create_event_creation_request(
	const std::chrono::time_point< std::chrono::system_clock >& p_time, const t_event_sptr p_event )
{
	auto l_handle = 0;
	{
		std::unique_lock< std::mutex > l_lock( m_mutex );
		if( m_run )
		{
			l_handle = generate_handle();
			m_event_creation_requests.insert( std::make_unique< t_event_creation_request >( p_time, p_event, l_handle ) );
		}
		else
		{
			LOG_AND_THROW( t_log_level::LL_FATAL,
				"Time based event creator is not running. Event creation requests cannot be created!" );
		}
	}
	m_condition_variable.notify_one();
	return( l_handle );
}


int t_timed_event_creator::create_event_creation_request(
	const std::chrono::milliseconds& p_time_till_event_is_fired, const t_event_sptr& p_event )
{
	const auto l_handle = create_event_creation_request(
		std::chrono::system_clock::now() + p_time_till_event_is_fired, p_event );
	return( l_handle );
}


// cppcheck-suppress unusedFunction
bool t_timed_event_creator::cancel( const int p_handle )
{
	auto l_cancelled = false;
	{
		std::unique_lock< std::mutex > l_lock( m_mutex );
		const auto l_found_element_iterator = find_element_by_handle( p_handle );
		if( l_found_element_iterator != m_event_creation_requests.end() )
		{
			m_event_creation_requests.erase( l_found_element_iterator );
			l_cancelled = true;
			Y_LOG( t_log_level::LL_TRACE, "Event with handle '%' was cancelled.", p_handle );
		}
		else
		{
			Y_LOG( t_log_level::LL_ERROR, "Event with handle '%' was NOT found.", p_handle );
		}
	}
	return( l_cancelled );
}


void t_timed_event_creator::start()
{
	Y_LOG( t_log_level::LL_DEBUG, "Event creator is starting." );
	m_run = true;
	m_worker = std::make_unique< std::thread >([ this ] ()
		{
			generate_event();
		}
		);
	Y_LOG( t_log_level::LL_DEBUG, "Event creator is started." );
}


void t_timed_event_creator::stop()
{
	Y_LOG( t_log_level::LL_DEBUG, "Event creator is stopping." );
	{
		std::lock_guard< std::mutex > l_lock( m_mutex );
		m_run = false;
	}
	m_condition_variable.notify_all();
	Y_ASSERT( m_worker->joinable(), "Time event generator thread is not joinable!" );
	m_worker->join();
	m_worker.reset();
	Y_LOG( t_log_level::LL_DEBUG, "Event creator is stopped." );
}


int t_timed_event_creator::generate_handle() const
{
	int l_handle = 0;

	do
	{
		std::random_device r;
		std::default_random_engine e1( r() );
		std::uniform_int_distribution< int > uniform_dist( 1, RAND_MAX );
		l_handle = uniform_dist( e1 );
	}
	while( check_if_handle_exists( l_handle ) );

	return( l_handle );
}


bool t_timed_event_creator::check_if_handle_exists( const int p_handle ) const
{
	auto l_found = false;
	auto l_found_element_iterator = find_element_by_handle( p_handle );
	if( l_found_element_iterator != m_event_creation_requests.end() )
	{
		l_found = true;
	}

	return( l_found );
}


void t_timed_event_creator::generate_event()
{
	try
	{
		std::unique_lock< std::mutex > l_lock( m_mutex );
		while( m_run )
		{
			if( m_event_creation_requests.empty() )
			{
				m_condition_variable.wait( l_lock, [ this ] ()
					{
						return( !( m_run && m_event_creation_requests.empty() ) );
					}
					);
			}
			else
			{
				const auto& l_event_creation_request = *m_event_creation_requests.begin();
				m_condition_variable.wait_until( l_lock, l_event_creation_request->get_time() );
				if( m_run )
				{
					auto l_event_iterator = m_event_creation_requests.begin();
					while( l_event_iterator != m_event_creation_requests.end() )
					{
						const auto now = std::chrono::system_clock::now();
						Y_LOG( t_log_level::LL_TRACE, "Checking for event @ %.", now.time_since_epoch().count() );
						if( ( *l_event_iterator )->get_time() <= now )
						{
							const auto l_event = ( *l_event_iterator )->get_event();
							Y_LOG( t_log_level::LL_DEBUG, "Try to fire event '%' with handle '%'.", l_event->get_id(),
								( *l_event_iterator )->get_handle() );
							if( !m_state_machine.fire_event( l_event ) )
							{
								Y_LOG( t_log_level::LL_ERROR, "Event with id '%' and handle was not fired!", l_event->get_id(),
									( *l_event_iterator )->get_handle() );
								m_run = false;
								break;
							}

							Y_LOG( t_log_level::LL_DEBUG, "Event '%' with handle '%' was fired.", l_event->get_id(),
								( *l_event_iterator )->get_handle() );
							m_event_creation_requests.erase( l_event_iterator );
							l_event_iterator = m_event_creation_requests.begin();
						}
						else
						{
							break;
						}
					}
				}
			}
		}
	}
	catch ( const std::exception& p_exception )
	{
		Y_LOG( t_log_level::LL_FATAL, p_exception.what() );
	}
	catch ( ... )
	{
		Y_LOG( t_log_level::LL_FATAL, "An error occured when generating time based event!" );
	}
}


t_event_queue::const_iterator t_timed_event_creator::find_element_by_handle( const int p_handle ) const
{
	return( std::find_if( m_event_creation_requests.begin(), m_event_creation_requests.end(),
						[ &p_handle ] ( const std::unique_ptr< t_event_creation_request >& p_event_creation_request )
						{ 
							return ( p_event_creation_request->get_handle() == p_handle );
						}	) );
}


}
