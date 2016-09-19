//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_execution_transition_step.h"

#include "i_terminate_pseudostate.h"
#include "i_transition.h"
#include "i_transition_step.h"
#include "i_event_processing_callback.h"
#include "i_execution_step_visitor.h"


namespace sxy
{


t_execution_transition_step::t_execution_transition_step
(		
	i_transition_step& p_transition_step
): 
	i_execution_step(),	 
	m_transition_step( p_transition_step )
{
	// Nothing to do...
}


t_execution_transition_step::~t_execution_transition_step
(
) = default;


bool
t_execution_transition_step::execute_behavior
(
	i_event_processing_callback* const p_event_processing_callback,
	const i_event& p_event
) const
{
	auto l_reached_terminate_pseudostate = false;
	const auto& transitions = m_transition_step.get_transitions();
	for( const auto& transition : transitions )
	{
		if( p_event_processing_callback )
		{
			p_event_processing_callback->before_transition( *transition );
		}

		transition->on_transition_behavior( p_event );

		if( p_event_processing_callback )
		{
			p_event_processing_callback->after_transition( *transition );
		}

		if( dynamic_cast< const i_terminate_pseudostate* >( &transition->get_target() ) )
		{
			l_reached_terminate_pseudostate = true;
			break;
		}
	}

	return ( l_reached_terminate_pseudostate );
}



void
t_execution_transition_step::accept
(
	i_execution_step_visitor& p_visitor
) const
{
	p_visitor.visit( *this );
}


const i_transition_step&
// cppcheck-suppress unusedFunction
t_execution_transition_step::get_transition_step
(
) const
{
	return( m_transition_step );
}


}
