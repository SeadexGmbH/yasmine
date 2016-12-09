//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "async_state_machine.hpp"

#include <exception>
#include <algorithm>

#include "base.hpp"
#include "event_impl.hpp"
#include "log_and_throw.hpp"


namespace sxy
{


async_state_machine::async_state_machine( const std::string& _name, 
	event_processing_callback* const _event_processing_callback )
	: state_machine( _name, _event_processing_callback ),
		status_( status::NEW ),
		run_and_event_mutex_(),
		run_and_event_condition_(),
		worker_thread_(),
		run_( false ),
		event_list_()
{
	Y_LOG( sxy::log_level::LL_TRACE, "Creating async state_machine '%'.", _name );
	// Nothing to do...
	Y_LOG( sxy::log_level::LL_TRACE, "Created async state_machine '%'.", _name );
}


async_state_machine::~async_state_machine() Y_NOEXCEPT
{
	Y_LOG( sxy::log_level::LL_TRACE, "Destroying async state_machine '%'.", get_name() );

	Y_ASSERT( ( status::NEW == status_ ) || ( status::STOPPED == status_ ),
		"Status is neither 'NEW' nor 'STOPPED' on destruction!" );

	Y_LOG( sxy::log_level::LL_TRACE, "Destroyed async state_machine '%'.", get_name() );
}


bool async_state_machine::fire_event( const event_sptr& _event )
{
	return( insert( _event ) );
}


bool async_state_machine::start_state_machine()
{
	Y_LOG( log_level::LL_INFO, "Starting async state machine '%'.", get_name() );

	const bool state_machine_started = state_machine::start_state_machine( this );
	if( state_machine_started )
	{
		start();
	}
	else
	{
		Y_LOG( log_level::LL_INFO, "Terminate pseudostate was reached in %.", get_name() );
		status_ = status::STOPPED;
	}

	Y_LOG( log_level::LL_INFO, "Started async state machine '%'.", get_name() );

	return( state_machine_started );
}


void async_state_machine::stop_state_machine()
{	
	Y_LOG( log_level::LL_INFO, "Stopping async state machine '%'.", get_name() );

	stop();	
	join();	
	state_machine::stop_state_machine();

	Y_LOG( log_level::LL_INFO, "Stopped async state machine '%'.", get_name() );
}


void async_state_machine::on_event( const event_sptr& _event )
{
	insert( _event );
}


void async_state_machine::start()
{
	Y_ASSERT( ( status::NEW == status_ ) || ( status::STOPPED == status_ ),
		"Status is neither 'NEW' nor 'STOPPED' on start!" );
	run_ = true;
	worker_thread_ = Y_MAKE_UNIQUE< sxy::thread >( &async_state_machine::work, this );
	status_ = status::STARTED;
}


void async_state_machine::stop()
{
	Y_LOG( log_level::LL_TRACE, "Stopping async state machine '%'.", get_name() );

	Y_ASSERT( ( status::STARTED == status_ ) || ( status::STOP_REQUESTED == status_ ),
		"Status is not 'STARTED' or 'STOP_REQUESTED' on stop!" );
	{
		sxy::lock_guard< sxy::mutex > lock( run_and_event_mutex_ );
		run_ = false;
	}
	run_and_event_condition_.notify_one();
	status_ = status::STOP_REQUESTED;

	Y_LOG( log_level::LL_TRACE, "Stopped state machine ''%'.", get_name() );
}


void async_state_machine::join()
{
	Y_LOG( log_level::LL_TRACE, "Joining state machine '%'.", get_name() );

	Y_ASSERT( status::STOP_REQUESTED == status_, "Status is not 'STOP_REQUESTED' when joining!" );
	worker_thread_->join();
	worker_thread_.reset();
	status_ = status::STOPPED;

	Y_LOG( log_level::LL_TRACE, "Joined state machine '%'.", get_name() );
}


bool async_state_machine::insert( const event_sptr& _event )
{
	Y_ASSERT( _event, "_event is nullptr!" );

	bool event_added = false;
	{
		sxy::lock_guard< sxy::mutex > lock( run_and_event_mutex_ );
		if( run_ )
		{				
			insert_impl( _event );
			event_added = true;
		}
		else
		{
			Y_LOG( log_level::LL_WARN, "Event '%' was not inserted in the queue of events! State machine is not running.", _event->get_name() );
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
#ifndef Y_CPP03_BOOST
			while ( position != std::end( event_list_ ) )
#else
			while ( position != event_list_.end() )
#endif
			{					
				if (_event->operator>(**position))
				{
						break;
				}
				++position;
			}
#ifndef Y_CPP03_BOOST
			Y_ASSERT( position != std::end( event_list_ ), "No element found before which to insert!" );			
#else
			Y_ASSERT( position != event_list_.end(), "No element found before which to insert!" );
#endif
			event_list_.insert( position, _event );
			
		}
}
	 

bool async_state_machine::wait_predicate() const
{
	return( !run_ || !event_list_.empty() );
}


void async_state_machine::work()
{
	try
	{
		while( true )
		{
			event_sptr event;
			{
				sxy::unique_lock< sxy::mutex > lock( run_and_event_mutex_ );
				run_and_event_condition_.wait( lock, sxy::bind( &async_state_machine::wait_predicate, this ) );
					
				if( !run_ && event_list_.empty() )
				{
					break;
				}

				Y_ASSERT( !event_list_.empty(), "Event list is empty!" );
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
		Y_LOG( sxy::log_level::LL_FATAL, "Unhandled exception: '%'.", exception.what() );
		run_ = false;
	}
	catch ( ... )
	{
		Y_LOG( sxy::log_level::LL_FATAL, "Unknown exception!" );
		run_ = false;
	}
}

}
