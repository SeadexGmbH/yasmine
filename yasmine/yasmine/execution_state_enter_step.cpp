//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "execution_state_enter_step.h"

#include "log.h"
#include "state.h"
#include "event_processing_callback.h"
#include "execution_step_visitor.h"


namespace sxy
{


execution_state_enter_step::execution_state_enter_step( state& _state )
	: execution_step(),
		state_( _state )
{
	// Nothing to do...
}


execution_state_enter_step::~execution_state_enter_step() = default;


bool execution_state_enter_step::execute_behavior( event_processing_callback* const _event_processing_callback,
	const event& _event, behavior_exceptions& _behavior_exceptions, 
	async_event_handler* const _async_event_handler ) const
{
	Y_UNUSED_PARAMETER( _behavior_exceptions );
	Y_UNUSED_PARAMETER( _async_event_handler );
	Y_LOG( sxy::log_level::LL_INFO, "Entering state '%'.", state_.get_name() );
	if( _event_processing_callback )
	{
		_event_processing_callback->before_enter( state_ );
	}

	state_.enter_state( _event );

	if( _event_processing_callback )
	{
		_event_processing_callback->after_enter( state_ );
	}

	Y_LOG( sxy::log_level::LL_INFO, "Entered state '%'.", state_.get_name() );
	return( false );
}


void execution_state_enter_step::accept( execution_step_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


const state& execution_state_enter_step::get_state() const
{
	return( state_ );
}


}
