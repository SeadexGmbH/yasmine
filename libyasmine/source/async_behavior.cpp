//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "async_behavior.hpp"

#include "log.hpp"
#include "behavior_exception.hpp"
#include "simple_state_base.hpp"
#include "async_event_handler.hpp"
#include "event.hpp"


namespace sxy
{


async_behavior::async_behavior()
	: worker_(),
		mutex_(),
		run_(false)	
{
	// Nothing to do...
}


async_behavior::~async_behavior() Y_NOEXCEPT
{
	Y_ASSERT( !run_, "Thread is still running! It was not stopped." );
	Y_ASSERT( !worker_, "The thread still exists!" );
}


void async_behavior::run( const event& _event, event_collector& _event_collector, 
	const simple_state_base& _simple_state, async_event_handler& _async_event_handler )
{	
	run_ = true;

	worker_ = Y_MAKE_UNIQUE< sxy::thread >( sxy::bind( &async_behavior::work, this, sxy::ref( _event ), 
		sxy::ref( _event_collector ), sxy::ref( _simple_state ), sxy::ref( _async_event_handler ) ) );
}


void async_behavior::halt_and_join()
{		
	{
		sxy::lock_guard< sxy::mutex > lock( mutex_ );
		run_ = false;
		notify_should_stop();		
	}
	
	join();	
}


bool async_behavior::should_stop() const 
{
	sxy::lock_guard< sxy::mutex > lock( mutex_ );
	return( !run_ );
}


void async_behavior::notify_should_stop()
{
	// Nothing to do...
}


void async_behavior::work( const event& _event, event_collector& _event_collector, 
	const simple_state_base& _simple_state, async_event_handler& _async_event_handler )
{		
	try
	{																					 				
		run_impl( _event, _event_collector, _async_event_handler );
	}
	catch( const sxy::behavior_exception& exception )
	{			
		Y_LOG( log_level::LL_DEBUG, "behavior_exception while running async_behavior: %", exception.what() );
		_async_event_handler.on_event( exception.get_error_event() );
	}
	catch( const std::exception& exception )
	{
		Y_LOG( log_level::LL_DEBUG, "std::exception while running async_behavior: %", exception.what() );	
		if( _simple_state.has_error_event() )
		{						
			_async_event_handler.on_event( _simple_state.get_error_event() );
		}
		else
		{
			Y_LOG( log_level::LL_FATAL, "Unknown exception while running async_behavior!" );
			throw;
		}
	}
	catch( ... )
	{
		Y_LOG( log_level::LL_FATAL, "Unknown exception while running async_behavior!" );
		throw;
	}
}


void async_behavior::join()
{
	Y_ASSERT( worker_->joinable(), "Async behavior thread is not joinable!" );
	worker_->join();
	worker_.reset();
}


}
