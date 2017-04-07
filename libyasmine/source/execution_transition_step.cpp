//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "execution_transition_step.hpp"

#include "essentials/base.hpp"

#include "terminate_pseudostate.hpp"
#include "transition.hpp"
#include "transition_step.hpp"
#include "event_processing_callback.hpp"
#include "execution_step_visitor.hpp"


namespace sxy
{


execution_transition_step::execution_transition_step( transition_step& _transition_step )
	: execution_step(),
		transition_step_( _transition_step )
{
	// Nothing to do...
}


execution_transition_step::~execution_transition_step() SX_NOEXCEPT
{
	// Nothing to do...
}


bool execution_transition_step::execute_behavior(	event_processing_callback* const _event_processing_callback,
	const event& _event, events& _exception_events,	async_event_handler* const _async_event_handler,
	event_collector& _event_collector ) const
{		
	SX_UNUSED_PARAMETER( _exception_events );
	SX_UNUSED_PARAMETER( _async_event_handler );	
	bool reached_terminate_pseudostate = false;
	const raw_transitions& transitions = transition_step_.get_transitions();

	SX_FOR(const transition* transition, transitions)
	{
		if( _event_processing_callback )
		{
			_event_processing_callback->before_transition( *transition );
		}

		transition->on_transition_behavior( _event, _event_collector );

		if( _event_processing_callback )
		{
			_event_processing_callback->after_transition( *transition );
		}

		if( dynamic_cast< const terminate_pseudostate* >( &transition->get_target() ) )
		{
			reached_terminate_pseudostate = true;
			break;
		}
	}

	return( reached_terminate_pseudostate );
}


void execution_transition_step::accept( execution_step_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


const transition_step& execution_transition_step::get_transition_step() const
{
	return( transition_step_ );
}


}
