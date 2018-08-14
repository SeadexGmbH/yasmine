//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "execution_state_exit_step.hpp"

#include "essentials/base.hpp"

#include "hermes/log.hpp"

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


execution_state_exit_step::~execution_state_exit_step() SX_NOEXCEPT
{
	// Nothing to do...
}


bool execution_state_exit_step::execute_behavior( event_processing_callback* const _event_processing_callback,
	const event& _event, events& _exception_events, async_event_handler* const _async_event_handler,
	event_collector& _event_collector ) const
{
	SX_UNUSED_PARAMETER( _exception_events );
	SX_UNUSED_PARAMETER( _async_event_handler );	
	SX_LOG( hermes::log_level::LL_TRACE, "Exiting state '%'.", state_.get_name() );
	if( _event_processing_callback )
	{
		_event_processing_callback->before_exit( state_ );
	}

	state_.exit_state( _event, _event_collector );

	if( _event_processing_callback )
	{
		_event_processing_callback->after_exit( state_ );
	}

	SX_LOG( hermes::log_level::LL_TRACE, "Exited state '%'.", state_.get_name() );
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
