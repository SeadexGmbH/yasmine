//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "execution_transition_step.h"

#include "terminate_pseudostate.h"
#include "transition.h"
#include "transition_step.h"
#include "event_processing_callback.h"
#include "execution_step_visitor.h"
#include "base.h"


namespace sxy
{


execution_transition_step::execution_transition_step( transition_step& _transition_step )
	: execution_step(),
		transition_step_( _transition_step )
{
	// Nothing to do...
}


execution_transition_step::~execution_transition_step() = default;


bool execution_transition_step::execute_behavior(	event_processing_callback* const _event_processing_callback,
	const event& _event, behavior_exceptions& _behavior_exceptions, 
	async_event_handler* const _async_event_handler ) const
{		
	Y_UNUSED_PARAMETER( _behavior_exceptions );
	Y_UNUSED_PARAMETER( _async_event_handler );
	auto reached_terminate_pseudostate = false;
	const auto& transitions = transition_step_.get_transitions();

	for( const auto & transition : transitions )
	{
		if( _event_processing_callback )
		{
			_event_processing_callback->before_transition( *transition );
		}

		transition->on_transition_behavior( _event );

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


// cppcheck-suppress unusedFunction
const transition_step& execution_transition_step::get_transition_step() const
{
	return( transition_step_ );
}


}
