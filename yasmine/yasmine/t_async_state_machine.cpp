//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "t_async_state_machine.h"

#include <exception>

#include "base.h"


namespace sxy
{


t_async_state_machine::t_async_state_machine( const std::string& p_name, 
	i_event_processing_callback* const p_event_processing_callback )
	: t_state_machine( p_name, p_event_processing_callback ),
		m_status( t_status::NEW ),
		m_run_and_event_mutex(),
		m_run_and_event_condition(),
		m_worker_thread(),
		m_run( false ),
		m_event_queue()
{
	// Nothing to do...
}


t_async_state_machine::~t_async_state_machine()
{
	Y_ASSERT( ( t_status::NEW == m_status ) || ( t_status::STOPPED == m_status ),
		"Status is neither 'NEW' nor 'STOPPED' on destruction!" );
}


bool t_async_state_machine::fire_event( const t_event_sptr& p_event )
{
	return( enqueue( p_event ) );
}


// cppcheck-suppress unusedFunction
bool t_async_state_machine::run()
{
	Y_LOG( t_log_level::LL_INFO, "Starting state machine." );
	const auto l_start_state_machine = start_state_machine();
	if( !l_start_state_machine )
	{
		start();
	}
	else
	{
		Y_LOG( t_log_level::LL_DEBUG, "Terminate pseudostate was reached." );
		m_status = t_status::STOPPED;
	}

	return( l_start_state_machine );
}


// cppcheck-suppress unusedFunction
void t_async_state_machine::halt()
{
	stop();
	join();
}


bool t_async_state_machine::enqueue( const t_event_sptr p_event )
{
	Y_ASSERT( p_event, "Event is nullptr!" );
	auto event_enqueued = false;
	{
		std::lock_guard< std::mutex > lock( m_run_and_event_mutex );
		if( m_run )
		{
			m_event_queue.push_back( p_event );
			event_enqueued = true;
		}
	}
	if( event_enqueued )
	{
		m_run_and_event_condition.notify_one();
	}

	return( event_enqueued );
}


void t_async_state_machine::start()
{
	Y_ASSERT( ( t_status::NEW == m_status ) || ( t_status::STOPPED == m_status ),
		"Status is neither 'NEW' nor 'STOPPED' on start!" );
	m_run = true;
	m_worker_thread = std::make_unique< std::thread >( &t_async_state_machine::work, this );
	m_status = t_status::STARTED;
}


void t_async_state_machine::stop()
{
	Y_LOG( t_log_level::LL_DEBUG, "Stopping state machine from run." );
	Y_ASSERT( ( t_status::STARTED == m_status ) || ( t_status::STOP_REQUESTED == m_status ),
		"Status is not 'STARTED' or 'STOP_REQUESTED' on stop!" );
	{
		std::lock_guard< std::mutex > lock( m_run_and_event_mutex );
		m_run = false;
	}
	m_run_and_event_condition.notify_one();
	m_status = t_status::STOP_REQUESTED;
	Y_LOG( t_log_level::LL_DEBUG, "State machine stopped." );
}


void t_async_state_machine::join()
{
	Y_ASSERT( t_status::STOP_REQUESTED == m_status, "Status is not 'STOP_REQUESTED' when joining!" );
	m_worker_thread->join();
	m_worker_thread.reset();
	m_status = t_status::STOPPED;
}


bool t_async_state_machine::wait_predicate() const
{
	return( !m_run || !m_event_queue.empty() );
}


void t_async_state_machine::work()
{
	try
	{
		while( true )
		{
			t_event_sptr l_event;
			{
				std::unique_lock< std::mutex > lock( m_run_and_event_mutex );
				m_run_and_event_condition.wait( lock, [ this ] ()
					{
						return( this->wait_predicate() );
					}
					);
				if( !m_run && m_event_queue.empty() )
				{
					break;
				}

				Y_ASSERT( !m_event_queue.empty(), "Event queue is empty!" );
				l_event = m_event_queue.front();
				m_event_queue.pop_front();
			}
			if( process_event( l_event ) )
			{
				break;
			}
		}
	}
	catch ( const std::exception& p_exception )
	{
		Y_LOG( sxy::t_log_level::LL_FATAL, "Unhandled exception: '%'.", p_exception.what() );
		m_run = false;
	}
	catch ( ... )
	{
		Y_LOG( sxy::t_log_level::LL_FATAL, "Unknown exception!" );
		m_run = false;
	}
}


}
