//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "execution_state_exit_step.hpp"

#include "log.hpp"
#include "state.hpp"
#include "event_processing_callback.hpp"
#include "execution_step_visitor.hpp"


namespace sxy
{


execution_state_exit_step::execution_state_exit_step( state& _state )
	: execution_step(),
		state_( _state )
{
	// Nothing to do...
}


execution_state_exit_step::~execution_state_exit_step() Y_NOEXCEPT
{
	// Nothing to do...
}


bool execution_state_exit_step::execute_behaviour( event_processing_callback* const _event_processing_callback,
	const event& _event, events& _exception_events, async_event_handler* const _async_event_handler ) const
{
	Y_UNUSED_PARAMETER( _exception_events );
	Y_UNUSED_PARAMETER( _async_event_handler );
	Y_LOG( sxy::log_level::LL_TRACE, "Exiting state '%'.", state_.get_name() );
	if( _event_processing_callback )
	{
		_event_processing_callback->before_exit( state_ );
	}

	state_.exit_state( _event );

	if( _event_processing_callback )
	{
		_event_processing_callback->after_exit( state_ );
	}

	Y_LOG( sxy::log_level::LL_TRACE, "Exited state '%'.", state_.get_name() );
	return( false );
}


void execution_state_exit_step::accept( execution_step_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


const state& execution_state_exit_step::get_state() const
{
	return( state_ );
}


}
