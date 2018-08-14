//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "execution_state_do_step.hpp"

#include "essentials/base.hpp"

#include "hermes/log.hpp"

#include "state.hpp"
#include "event_processing_callback.hpp"
#include "execution_step_visitor.hpp"
#include "behavior_exception.hpp"



namespace sxy
{


execution_state_do_step::execution_state_do_step( const state& _state )
	: execution_step(),
		state_( _state )
{
	// Nothing to do...
}


execution_state_do_step::~execution_state_do_step() SX_NOEXCEPT
{
	// Nothing to do...
}


bool execution_state_do_step::execute_behavior( event_processing_callback* const _event_processing_callback,
	const event& _event, events& _exception_events, async_event_handler* const _async_event_handler, event_collector& _event_collector ) const
{
	SX_LOG( hermes::log_level::LL_TRACE, "Executing do behavior of state '%'.", state_.get_name() );
	if( _event_processing_callback )
	{
		_event_processing_callback->before_do( state_ );
	}

	try
	{
		state_.execute_do_behavior(_event, _async_event_handler, _event_collector );
	}
	catch (const sxy::behavior_exception& exception)
	{
		_exception_events.push_back(exception.get_error_event());
	}
	catch (const std::exception& exception)
	{
		SX_UNUSED_PARAMETER(exception);
		if (state_.has_error_event())
		{
			_exception_events.push_back(state_.get_error_event());
		}
		else
		{
			throw;
		}
	}
	

	if( _event_processing_callback )
	{
		_event_processing_callback->after_do( state_ );
	}

	SX_LOG( hermes::log_level::LL_TRACE, "'do behavior' of state '%' executed.", state_.get_name() );
	return( false );
}


void execution_state_do_step::accept( execution_step_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


const state& execution_state_do_step::get_state() const
{
	return( state_ );
}


}
