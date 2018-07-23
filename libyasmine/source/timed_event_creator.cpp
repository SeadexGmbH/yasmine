//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "timed_event_creator.hpp"

#include <algorithm>

#include "essentials/base.hpp"
#include "hermes/log_and_throw.hpp"

#include "event_creation_request.hpp"
#include "async_state_machine.hpp"
#include "event_impl.hpp"


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


timed_event_creator::~timed_event_creator() SX_NOEXCEPT
{		
	SX_ASSERT( !run_, "Thread is still running! It was not stopped." );
	SX_ASSERT( !worker_, "The thread still exists!" );
}


handle_type timed_event_creator::create_event_creation_request(
	const sxe::time_point< sxe::system_clock >& _time, const event_sptr _event )
{
	handle_type handle = Y_DEFAULT_HANDLE;
	{
		sxe::unique_lock< sxe::mutex > lock( mutex_ );
		if( run_ )
		{
			handle = generate_handle();
			event_creation_requests_.insert( event_creation_request( _time, _event, handle ) );
		}
		else
		{
			LOG_AND_THROW( hermes::log_level::LL_FATAL,
				"Time based event creator is not running. Event creation requests cannot be created!" );
		}
	}
	condition_variable_.notify_one();
	return( handle );
}


handle_type timed_event_creator::create_event_creation_request(
	const sxe::milliseconds& _time_till_event_is_fired, const event_sptr& _event )
{
	const handle_type handle = create_event_creation_request(
		sxe::system_clock::now() + _time_till_event_is_fired, _event );
	return( handle );
}


bool timed_event_creator::cancel( const handle_type _handle )
{
	bool cancelled = false;
	{
		sxe::unique_lock< sxe::mutex > lock( mutex_ );
		const event_queue::iterator found_element_iterator = find_element_by_handle( _handle );
		if( found_element_iterator != event_creation_requests_.end() )
		{
			event_creation_requests_.erase( found_element_iterator );
			cancelled = true;
			SX_LOG( hermes::log_level::LL_TRACE, "Event with handle '%' was cancelled.", _handle );
		}
		else
		{
			SX_LOG( hermes::log_level::LL_WARN, "Event with handle '%' was NOT found.", _handle );
		}
	}
	return( cancelled );
}


void timed_event_creator::run()
{
	SX_LOG( hermes::log_level::LL_TRACE, "Event creator is starting." );
	run_ = true;
	worker_ = SX_MAKE_UNIQUE< sxe::thread >( sxe::bind( &timed_event_creator::generate_event, this ) );
	SX_LOG( hermes::log_level::LL_TRACE, "Event creator started." );
}


void timed_event_creator::halt()
{
	SX_LOG( hermes::log_level::LL_TRACE, "Event creator is stopping." );
	{
		sxe::lock_guard< sxe::mutex > lock( mutex_ );
		run_ = false;
	}
	condition_variable_.notify_all();
}


void timed_event_creator::join()
{
	SX_ASSERT( worker_->joinable(), "Time event generator thread is not joinable!" );
	worker_->join();
	worker_.reset();
	SX_LOG( hermes::log_level::LL_TRACE, "Event creator stopped." );
}


void timed_event_creator::halt_and_join()
{
	SX_LOG( hermes::log_level::LL_TRACE, "Event creator is stopping." );
	{
		sxe::lock_guard< sxe::mutex > lock( mutex_ );
		run_ = false;
	}
	condition_variable_.notify_all();
	SX_ASSERT( worker_->joinable(), "Time event generator thread is not joinable!" );
	worker_->join();
	worker_.reset();
	SX_LOG( hermes::log_level::LL_TRACE, "Event creator stopped." );
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
		sxe::unique_lock< sxe::mutex > lock( mutex_ );
		while( run_ )
		{
			if( event_creation_requests_.empty() )
			{
				condition_variable_.wait( lock, sxe::bind( &timed_event_creator::check_wait_condition, this ) );
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
						const sxe::time_point< sxe::system_clock > now = sxe::system_clock::now();						
						SX_LOG( hermes::log_level::LL_TRACE, "Checking for event @ %.", now.time_since_epoch().count() );
						if( ( *event_iterator ).get_time() <= now )
						{
							const event_sptr event = ( *event_iterator ).get_event();
							SX_LOG( hermes::log_level::LL_TRACE, "Try to fire event '%' (%) with handle '%'.", event->get_name(), event->get_id(),
								( *event_iterator ).get_handle() );
							if( !state_machine_.fire_event( event ) )
							{
								SX_LOG( hermes::log_level::LL_ERROR, "Event '%' (%) and handle was not fired!", event->get_name(), event->get_id(),
									( *event_iterator ).get_handle() );
								run_ = false;
								break;
							}

							SX_LOG( hermes::log_level::LL_DEBUG, "Event '%' (%) with handle '%' was fired.", event->get_name(), event->get_id(),
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
		SX_LOG( hermes::log_level::LL_FATAL, "Unhandled std::exception when generating time based event: %", exception.what() );
	}
	catch ( ... )
	{
		SX_LOG( hermes::log_level::LL_FATAL, "Unknown exception when generating time based event!" );
	}
}


event_queue::const_iterator timed_event_creator::find_element_by_handle( const handle_type _handle ) const
{
	return( std::find_if(event_creation_requests_.begin(), event_creation_requests_.end(),
		sxe::bind( &timed_event_creator::compare_handles, _handle, sxe::_1 ) ) );
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
