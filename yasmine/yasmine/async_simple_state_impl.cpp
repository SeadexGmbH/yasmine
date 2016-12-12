//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "async_simple_state_impl.hpp"

#include "base.hpp"


namespace sxy
{


async_simple_state_impl::async_simple_state_impl( const std::string& _name, async_behavior_uptr _do_action,
	behavior_uptr _entry_action, behavior_uptr _exit_action, const event_ids& _deferred_events,
	event_sptr _error_event )
	: simple_state_base( _name, sxy::move( _entry_action ), sxy::move( _exit_action ), _deferred_events, 
			_error_event ),
	do_( sxy::move( _do_action ) )
{		
	Y_ASSERT( do_, "Async simple state must have an 'async do behavior' asigned!" );
}


async_simple_state_impl::~async_simple_state_impl() Y_NOEXCEPT
{
	// Nothing to do...
}
																												 

void async_simple_state_impl::execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler ) const
{
	const async_behavior* const behavior = do_.get();
	if( behavior )
	{
		do_->start( _event, *this, *_async_event_handler );
	}
}


void async_simple_state_impl::execute_exit_behavior( const event& _event ) const
{
	stop_do_behavior();

	complex_state_impl::execute_exit_behavior( _event );
}


void async_simple_state_impl::stop_do_behavior() const
{
	const async_behavior* const behavior = do_.get();
	if( behavior )
	{
		do_->stop();		
	}
}


}
