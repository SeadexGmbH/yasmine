//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "async_state_machine.hpp"

#include <exception>
#include <algorithm>

#include "essentials/base.hpp"
#include "hermes/log_and_throw.hpp"

#include "event_impl.hpp"


namespace sxy
{


async_state_machine::async_state_machine( const std::string& _name, 
	event_processing_callback* const _event_processing_callback )
	: state_machine_base( _name, _event_processing_callback ),
		status_( state_machine_status::NEW ),
		run_and_event_mutex_(),
		run_and_event_condition_(),
		terminated_condition_(),
		worker_thread_(),		
		event_list_()
{
	SX_LOG( hermes::log_level::LL_TRACE, "Creating async state_machine '%'.", _name );
	// Nothing to do...
	SX_LOG( hermes::log_level::LL_TRACE, "Created async state_machine '%'.", _name );
}


async_state_machine::~async_state_machine() SX_NOEXCEPT
{
	SX_LOG( hermes::log_level::LL_TRACE, "Destroying async state_machine '%'.", get_name() );

	SX_ASSERT( ( state_machine_status::NEW == status_ ) || ( state_machine_status::STOPPED == status_ ),
		"Status is neither 'NEW' nor 'STOPPED' on destruction!" );

	SX_LOG( hermes::log_level::LL_TRACE, "Destroyed async state_machine '%'.", get_name() );
}


bool async_state_machine::fire_event( const event_sptr& _event )
{
	bool event_fired = false;
	if( !is_interrupted() )
	{
		event_fired = insert( _event );
	}
	return( event_fired );
}


bool async_state_machine::run()
{
	SX_LOG( hermes::log_level::LL_INFO, "Starting async state machine '%'.", get_name() );

	const bool state_machine_started = state_machine_base::run( this );
	if( state_machine_started )
	{
		start_state_machine();
	}
	else
	{
		SX_LOG( hermes::log_level::LL_INFO, "Terminate pseudostate was reached in %.", get_name() );
		status_ = state_machine_status::STOPPED;		
	}

	SX_LOG( hermes::log_level::LL_INFO, "Started async state machine '%'.", get_name() );

	return( state_machine_started );
}


void async_state_machine::halt_and_join()
{	
	SX_LOG( hermes::log_level::LL_INFO, "Stopping and joining async state machine '%'.", get_name() );

	halt();
	join();

	SX_LOG( hermes::log_level::LL_INFO, "Stopped and joined async state machine '%'.", get_name() );
}


void async_state_machine::halt()
{
	SX_LOG( hermes::log_level::LL_TRACE, "Stopping async state machine '%'.", get_name() );

	{
		sxe::lock_guard< sxe::mutex > lock( run_and_event_mutex_ );
		SX_ASSERT( ( state_machine_status::STARTED == status_ ) || ( state_machine_status::TERMINATED == status_ ),
			"Status is not 'STARTED' or 'TERMINATED' on stop!" );
		status_ = state_machine_status::STOP_REQUESTED;
	}
	run_and_event_condition_.notify_one();

	SX_LOG( hermes::log_level::LL_TRACE, "Stopped state machine '%'.", get_name() );
}


void async_state_machine::join()
{
	SX_LOG( hermes::log_level::LL_TRACE, "Joining state machine '%'.", get_name() );

	{
		sxe::lock_guard< sxe::mutex > lock( run_and_event_mutex_ );
		SX_ASSERT( ( state_machine_status::STOP_REQUESTED == status_ ) || ( state_machine_status::TERMINATED == status_ ), 
			"Status is not 'STOP_REQUESTED' or 'TERMNINATED' when joining!" );
	}
		
	worker_thread_->join();
	worker_thread_.reset();
	status_ = state_machine_status::STOPPED;
	state_machine_base::halt();

	SX_LOG( hermes::log_level::LL_TRACE, "Joined state machine '%'.", get_name() );
}


bool async_state_machine::wait( const sxe::milliseconds _timeoutInMs ) const
{
	SX_LOG( hermes::log_level::LL_INFO, "Waiting for async state machine '%' to terminate. Timeout: %ms", get_name(), _timeoutInMs.count() );
	{
		sxe::unique_lock<sxe::mutex> lock( run_and_event_mutex_ );
		terminated_condition_.wait_for( lock, _timeoutInMs, sxe::bind( &async_state_machine::wait_stop_condition, this ) );
	}
	SX_LOG( hermes::log_level::LL_INFO, "Waited for async state machine '%' to terminate.", get_name() );
	return( terminated() );
}


void async_state_machine::wait() const 
{
	SX_LOG( hermes::log_level::LL_INFO, "Waiting for async state machine '%' to terminate.", get_name() );
	{
		sxe::unique_lock<sxe::mutex> lock( run_and_event_mutex_ );
		terminated_condition_.wait( lock, sxe::bind( &async_state_machine::wait_stop_condition, this ) );
	}
	SX_LOG( hermes::log_level::LL_INFO, "Waited for async state machine '%' to terminate.", get_name() );
}


bool async_state_machine::terminated() const 
{
	sxe::lock_guard< sxe::mutex > lock( run_and_event_mutex_ );
	return( ( state_machine_status::TERMINATED == status_ ) || ( state_machine_status::STOPPED == status_ ) );
}



bool async_state_machine::push( const event_sptr& _event )
{
	return( fire_event( _event ) );
}


void async_state_machine::start_state_machine()
{
	SX_ASSERT( ( state_machine_status::NEW == status_ ) || ( state_machine_status::STOPPED == status_ ),
		"Status is neither 'NEW' nor 'STOPPED' on start!" );
	
	status_ = state_machine_status::STARTED;
	worker_thread_ = SX_MAKE_UNIQUE< sxe::thread >( &async_state_machine::work, this );
}


bool async_state_machine::insert( const event_sptr& _event )
{
	SX_ASSERT( _event, "_event is nullptr!" );

	bool event_added = false;
	{
		sxe::lock_guard< sxe::mutex > lock( run_and_event_mutex_ );
		if( status_  == state_machine_status::STARTED )
		{
			insert_impl( _event );
			event_added = true;
		}
		else
		{
			SX_LOG( hermes::log_level::LL_WARN, "Event '%' was not inserted in the queue of events! State machine is not running.", _event->get_name() );
		}
	}
	if( event_added )
	{
		run_and_event_condition_.notify_one();
	}

	return( event_added );
}


void async_state_machine::insert_impl( const event_sptr& _event )
{
	if( event_list_.empty() )
	{
		event_list_.push_back( _event );	
	}
	else
		if( event_list_.back()->get_priority() >= _event->get_priority() )
		{
			event_list_.push_back( _event );
		}
		else
		{
			std::list< event_sptr >::iterator position = event_list_.begin();
			while( position != event_list_.end() )
			{					
				if (_event->operator>(**position))
				{
						break;
				}
				++position;
			}
			SX_ASSERT( position != event_list_.end(), "No element found before which to insert!" );
			event_list_.insert( position, _event );
		}
}


bool async_state_machine::wait_predicate() const
{
	return( !( status_ == state_machine_status::STARTED ) || !event_list_.empty() );	
}


bool async_state_machine::wait_stop_condition() const
{
	return( ( state_machine_status::TERMINATED == status_ ) || ( state_machine_status::STOPPED == status_ ) );
}


void async_state_machine::work()
{
	try
	{
		while( true )
		{
			event_sptr event;
			{
				sxe::unique_lock< sxe::mutex > lock( run_and_event_mutex_ );
				run_and_event_condition_.wait( lock, sxe::bind( &async_state_machine::wait_predicate, this ) );				
				if( !( status_ == state_machine_status::STARTED ) && ( event_list_.empty() || is_interrupted() ) )
				{
					break;
				}
				SX_ASSERT( !event_list_.empty(), "Event list is empty!" );
				event = event_list_.front();
				event_list_.pop_front();
			}
			if( process_event( event, this ) )
			{
				break;
			}
		}
	}
	catch ( const std::exception& exception )
	{
		SX_LOG( hermes::log_level::LL_FATAL, "Unhandled exception: '%'.", exception.what() );		
		status_ = state_machine_status::STOPPED;
	}
	catch ( ... )
	{
		SX_LOG( hermes::log_level::LL_FATAL, "Unknown exception!" );		
		status_ = state_machine_status::STOPPED;
	}

	{
		sxe::lock_guard< sxe::mutex > lock( run_and_event_mutex_ );
		status_ = state_machine_status::TERMINATED;
	}

	terminated_condition_.notify_all();
	SX_LOG( hermes::log_level::LL_INFO, "Async state machine '%' terminated.", get_name() );
}


void async_state_machine::on_event( const event_sptr& _event )
{
	insert( _event );
}


void async_state_machine::interrupt_impl()
{
	halt();
}


}
