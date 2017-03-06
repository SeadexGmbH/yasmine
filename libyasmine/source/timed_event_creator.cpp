//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "timed_event_creator.hpp"

#include <algorithm>

#include "event_creation_request.hpp"
#include "async_state_machine.hpp"
#include "base.hpp"
#include "event_impl.hpp"
#include "log_and_throw.hpp"


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


timed_event_creator::~timed_event_creator() Y_NOEXCEPT
{		
	Y_ASSERT( !run_, "Thread is still running! It was not stopped." );
	Y_ASSERT( !worker_, "The thread still exists!" );
}


handle_type timed_event_creator::create_event_creation_request(
	const sxy::time_point< sxy::system_clock >& _time, const event_sptr _event )
{
	handle_type handle = Y_DEFAULT_HANDLE;
	{
		sxy::unique_lock< sxy::mutex > lock( mutex_ );
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


handle_type timed_event_creator::create_event_creation_request(
	const sxy::milliseconds& _time_till_event_is_fired, const event_sptr& _event )
{
	const handle_type handle = create_event_creation_request(
		sxy::system_clock::now() + _time_till_event_is_fired, _event );
	return( handle );
}


bool timed_event_creator::cancel( const handle_type _handle )
{
	bool cancelled = false;
	{
		sxy::unique_lock< sxy::mutex > lock( mutex_ );
		const event_queue::iterator found_element_iterator = find_element_by_handle( _handle );
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


void timed_event_creator::run()
{
	Y_LOG( log_level::LL_TRACE, "Event creator is starting." );
	run_ = true;
	worker_ = Y_MAKE_UNIQUE< sxy::thread >( sxy::bind( &timed_event_creator::generate_event, this ) );
	Y_LOG( log_level::LL_TRACE, "Event creator started." );
}


void timed_event_creator::halt()
{
	Y_LOG( log_level::LL_TRACE, "Event creator is stopping." );
	{
		sxy::lock_guard< sxy::mutex > lock( mutex_ );
		run_ = false;
	}
	condition_variable_.notify_all();
}


void timed_event_creator::join()
{
	Y_ASSERT( worker_->joinable(), "Time event generator thread is not joinable!" );
	worker_->join();
	worker_.reset();
	Y_LOG( log_level::LL_TRACE, "Event creator stopped." );
}


void timed_event_creator::halt_and_join()
{
	Y_LOG( log_level::LL_TRACE, "Event creator is stopping." );
	{
		sxy::lock_guard< sxy::mutex > lock( mutex_ );
		run_ = false;
	}
	condition_variable_.notify_all();
	Y_ASSERT( worker_->joinable(), "Time event generator thread is not joinable!" );
	worker_->join();
	worker_.reset();
	Y_LOG( log_level::LL_TRACE, "Event creator stopped." );
}


handle_type timed_event_creator::generate_handle()
{
	handle_type handle = Y_DEFAULT_HANDLE;

	do
	{
		handle = maximum_handle_++;
		if( maximum_handle_ == Y_INVALID_EVENT_CREATION_REQUEST_HANDLE )
		{
			maximum_handle_ = 0;
		}			
	}
	while( check_if_handle_exists( handle ) );

	return( handle );
}


bool timed_event_creator::check_if_handle_exists( const handle_type _handle ) const
{
	bool found = false;
	const event_queue::const_iterator found_element_iterator = find_element_by_handle( _handle );
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
		sxy::unique_lock< sxy::mutex > lock( mutex_ );
		while( run_ )
		{
			if( event_creation_requests_.empty() )
			{
				condition_variable_.wait( lock, sxy::bind( &timed_event_creator::check_wait_condition, this ) );
			}
			else
			{
				const event_creation_request& event_creation_request = *event_creation_requests_.begin();								
				condition_variable_.wait_until( lock, event_creation_request.get_time() );								
				if( run_ )
				{
					event_queue::const_iterator event_iterator = event_creation_requests_.begin();
					while( event_iterator != event_creation_requests_.end() )
					{
						const sxy::time_point< sxy::system_clock > now = sxy::system_clock::now();						
						Y_LOG( log_level::LL_TRACE, "Checking for event @ %.", now.time_since_epoch().count() );
						if( ( *event_iterator ).get_time() <= now )
						{
							const event_sptr event = ( *event_iterator ).get_event();
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


event_queue::const_iterator timed_event_creator::find_element_by_handle( const handle_type _handle ) const
{
	return( std::find_if(event_creation_requests_.begin(), event_creation_requests_.end(),
		sxy::bind( &timed_event_creator::compare_handles, _handle, sxy::_1 ) ) );
}


bool timed_event_creator::check_wait_condition() const
{
	return( !( run_ && event_creation_requests_.empty() ) );
}


bool timed_event_creator::compare_handles( const handle_type _handle, 
	const event_creation_request& _event_creation_request )
{
	return ( _event_creation_request.get_handle() == _handle );
}


}
