//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "timed_event_creator.hpp"

#include <algorithm>

#include "make_unique.hpp"
#include "event_creation_request.hpp"
#include "async_state_machine.hpp"
#include "base.hpp"
#include "event_impl.hpp"
#include "log_and_throw.hpp"
#include "event_with_parameters.hpp"


namespace sxy
{


timed_event_creator::timed_event_creator( async_state_machine& _async_state_machine )
	: state_machine_( _async_state_machine ),
		event_creation_requests_(),
		worker_(),
		mutex_(),
		condition_variable_(),
		run_( true ),
		maximum_handle_ ( 0 )
{
	// Nothing to do...
}


timed_event_creator::~timed_event_creator() noexcept
{
	Y_ASSERT( !run_, "Thread is still running! It was not stopped." );
	Y_ASSERT( !worker_, "The thread still exists!" );
}


event_creation_request::handle_type timed_event_creator::create_event_creation_request(
	const std::chrono::time_point< std::chrono::system_clock >& _time, const event_sptr _event )
{
	auto handle = 0;
	{
		std::unique_lock< std::mutex > lock( mutex_ );
		if( run_ )
		{
			handle = generate_handle();			
			event_creation_requests_.insert( event_creation_request( _time, _event, handle ) );
		}
		else
		{
			LOG_AND_THROW( log_level::LL_FATAL,
				"Time based event creator is not running. Event creation requests cannot be created!" );
		}
	}
	condition_variable_.notify_one();
	return( handle );
}


event_creation_request::handle_type timed_event_creator::create_event_creation_request(
	const std::chrono::milliseconds& _time_till_event_is_fired, const event_sptr& _event )
{
	const auto handle = create_event_creation_request(
		std::chrono::system_clock::now() + _time_till_event_is_fired, _event );
	return( handle );
}


// cppcheck-suppress unusedFunction
bool timed_event_creator::cancel( const event_creation_request::handle_type _handle )
{
	auto cancelled = false;
	{
		std::unique_lock< std::mutex > lock( mutex_ );
		const auto found_element_iterator = find_element_by_handle( _handle );
		if( found_element_iterator != event_creation_requests_.end() )
		{
			event_creation_requests_.erase( found_element_iterator );
			cancelled = true;
			Y_LOG( log_level::LL_TRACE, "Event with handle '%' was cancelled.", _handle );
		}
		else
		{
			Y_LOG( log_level::LL_WARN, "Event with handle '%' was NOT found.", _handle );
		}
	}
	return( cancelled );
}


void timed_event_creator::start()
{
	Y_LOG( log_level::LL_TRACE, "Event creator is starting." );
	run_ = true;
	worker_ = sxy::make_unique< std::thread >([ this ] ()
		{
			generate_event();
		}
		);
	Y_LOG( log_level::LL_TRACE, "Event creator started." );
}


void timed_event_creator::stop()
{
	Y_LOG( log_level::LL_TRACE, "Event creator is stopping." );
	{
		std::lock_guard< std::mutex > lock( mutex_ );
		run_ = false;
	}
	condition_variable_.notify_all();
	Y_ASSERT( worker_->joinable(), "Time event generator thread is not joinable!" );
	worker_->join();
	worker_.reset();
	Y_LOG( log_level::LL_TRACE, "Event creator stopped." );
}


event_creation_request::handle_type timed_event_creator::generate_handle()
{
	event_creation_request::handle_type handle = 0;

	do
	{
		handle = maximum_handle_++;
		if( maximum_handle_ == std::numeric_limits< event_creation_request::handle_type >::max() )
		{
			maximum_handle_ = 0;
		}			
	}
	while( check_if_handle_exists( handle ) );

	return( handle );
}


bool timed_event_creator::check_if_handle_exists( const event_creation_request::handle_type _handle ) const
{
	auto found = false;
	auto found_element_iterator = find_element_by_handle( _handle );
	if( found_element_iterator != event_creation_requests_.end() )
	{
		found = true;
	}

	return( found );
}


void timed_event_creator::generate_event()
{
	try
	{
		std::unique_lock< std::mutex > lock( mutex_ );
		while( run_ )
		{
			if( event_creation_requests_.empty() )
			{
				condition_variable_.wait( lock, [ this ] ()
					{
						return( !( run_ && event_creation_requests_.empty() ) );
					}
					);
			}
			else
			{
				const auto& event_creation_request = *event_creation_requests_.begin();
				condition_variable_.wait_until( lock, event_creation_request.get_time() );
				if( run_ )
				{
					auto event_iterator = event_creation_requests_.begin();
					while( event_iterator != event_creation_requests_.end() )
					{
						const auto now = std::chrono::system_clock::now();
						Y_LOG( log_level::LL_TRACE, "Checking for event @ %.", now.time_since_epoch().count() );
						if( ( *event_iterator ).get_time() <= now )
						{
							const auto event = ( *event_iterator ).get_event();
							Y_LOG( log_level::LL_TRACE, "Try to fire event '%' (%) with handle '%'.", event->get_name(), event->get_id(),
								( *event_iterator ).get_handle() );
							if( !state_machine_.fire_event( event ) )
							{
								Y_LOG( log_level::LL_ERROR, "Event '%' (%) and handle was not fired!", event->get_name(), event->get_id(),
									( *event_iterator ).get_handle() );
								run_ = false;
								break;
							}

							Y_LOG( log_level::LL_DEBUG, "Event '%' (%) with handle '%' was fired.", event->get_name(), event->get_id(),
								( *event_iterator ).get_handle() );
							event_creation_requests_.erase( event_iterator );
							event_iterator = event_creation_requests_.begin();
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
	catch ( const std::exception& exception )
	{
		Y_LOG( log_level::LL_FATAL, "Unhandled std::exception when generating time based event: %", exception.what() );
	}
	catch ( ... )
	{
		Y_LOG( log_level::LL_FATAL, "Unknown exception when generating time based event!" );
	}
}


event_queue::const_iterator timed_event_creator::find_element_by_handle( 
	const event_creation_request::handle_type _handle ) const
{
	return( std::find_if( event_creation_requests_.begin(), event_creation_requests_.end(),
						[ &_handle ] ( const event_creation_request& _event_creation_request )
						{ 
							return ( _event_creation_request.get_handle() == _handle );
						}	) );
}


}
