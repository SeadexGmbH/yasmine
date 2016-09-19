//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "async_state_machine.h"

#include <exception>

#include "base.h"
#include "event_impl.h"


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
		event_queue_()
{
	// Nothing to do...
}


async_state_machine::~async_state_machine()
{
	Y_ASSERT( ( status::NEW == status_ ) || ( status::STOPPED == status_ ),
		"Status is neither 'NEW' nor 'STOPPED' on destruction!" );
}


bool async_state_machine::fire_event( const event_sptr& _event )
{
	return( enqueue( _event ) );
}


bool async_state_machine::run()
{
	Y_LOG( log_level::LL_INFO, "Starting state machine." );
	const auto l_start_state_machine = start_state_machine( this );
	if( !l_start_state_machine )
	{
		start();
	}
	else
	{
		Y_LOG( log_level::LL_DEBUG, "Terminate pseudostate was reached." );
		status_ = status::STOPPED;
	}

	return( l_start_state_machine );
}


// cppcheck-suppress unusedFunction
void async_state_machine::halt()
{		
	stop();	
	join();	
	state_machine::stop_state_machine();
}


void async_state_machine::on_event( const event_sptr _event )
{
	enqueue_front( _event );
}


void async_state_machine::start()
{
	Y_ASSERT( ( status::NEW == status_ ) || ( status::STOPPED == status_ ),
		"Status is neither 'NEW' nor 'STOPPED' on start!" );
	run_ = true;
	worker_thread_ = std::make_unique< std::thread >( &async_state_machine::work, this );
	status_ = status::STARTED;
}


void async_state_machine::stop()
{
	Y_LOG( log_level::LL_DEBUG, "Stopping state machine from run." );
	Y_ASSERT( ( status::STARTED == status_ ) || ( status::STOP_REQUESTED == status_ ),
		"Status is not 'STARTED' or 'STOP_REQUESTED' on stop!" );
	{
		std::lock_guard< std::mutex > lock( run_and_event_mutex_ );
		run_ = false;
	}
	run_and_event_condition_.notify_one();
	status_ = status::STOP_REQUESTED;
	Y_LOG( log_level::LL_DEBUG, "State machine stopped." );
}


void async_state_machine::join()
{
	Y_ASSERT( status::STOP_REQUESTED == status_, "Status is not 'STOP_REQUESTED' when joining!" );
	worker_thread_->join();
	worker_thread_.reset();
	status_ = status::STOPPED;
}


bool async_state_machine::enqueue( const event_sptr _event )
{
	return( enqueue_impl( _event, [ this ] ( const event_sptr _event ) { event_queue_.push_back( _event ); } ) );
}


bool async_state_machine::enqueue_front( const event_sptr _event )
{		
	return( enqueue_impl( _event, [ this ] ( const event_sptr _event ) { event_queue_.push_front( _event ); } ) );
}


bool async_state_machine::enqueue_impl( const event_sptr _event, queue_inserter _queue_inserter )
{
	Y_ASSERT( _event, "Event is nullptr!" );
	auto event_enqueued = false;
	{
		std::lock_guard< std::mutex > lock( run_and_event_mutex_ );
		if( run_ )
		{
			_queue_inserter( _event );
			event_enqueued = true;
		}
	}
	if( event_enqueued )
	{
		run_and_event_condition_.notify_one();
	}

	return( event_enqueued );
}


bool async_state_machine::wait_predicate() const
{
	return( !run_ || !event_queue_.empty() );
}


void async_state_machine::work()
{
	try
	{
		while( true )
		{
			event_sptr event;
			{
				std::unique_lock< std::mutex > lock( run_and_event_mutex_ );
				run_and_event_condition_.wait( lock, [ this ] ()
					{
						return( this->wait_predicate() );
					}
					);
				if( !run_ && event_queue_.empty() )
				{
					break;
				}

				Y_ASSERT( !event_queue_.empty(), "Event queue is empty!" );
				event = event_queue_.front();
				event_queue_.pop_front();
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
