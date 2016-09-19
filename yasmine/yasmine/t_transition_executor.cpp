//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_transition_executor.h"

#include "log.h"

#include "t_transition_executor_impl.h"
#include "i_choice_fwd.h"
#include "i_execution_step.h"
#include "i_execution_step_fwd.h"
#include "i_region_fwd.h"
#include "t_compound_transition.h"
#include "i_event_processing_callback.h"
#include "i_event.h"


namespace sxy
{


t_transition_executor::t_transition_executor()
	: m_transition_executor_impl()
{
	// Nothing to do...
}


t_transition_executor::~t_transition_executor() = default;


bool t_transition_executor::check_sort_and_execute_transitions( const t_compound_transitions& p_compound_transitions,
	t_raw_const_choices& p_vertices, i_event_processing_callback* const p_event_processing_callback, 
	const i_event& p_event )
{
	auto l_terminate_pseudostate_has_been_reached = false;
	Y_LOG( t_log_level::LL_TRACE, "Check for transitions conflicts." );
	m_transition_executor_impl->conflict_check( p_compound_transitions );
	Y_LOG( t_log_level::LL_TRACE, "Sorting compound transitions." );
	const auto& sorted_compound_transitions = m_transition_executor_impl->sort_compound_transitions(
		p_compound_transitions );
	Y_LOG( t_log_level::LL_TRACE, "Compound transitions sorted." );
	Y_LOG( t_log_level::LL_TRACE, "Start calculating execution step(s) for all compound transitions." );

	for( auto & compound_transition : sorted_compound_transitions )
	{
		if( p_event_processing_callback )
		{
			p_event_processing_callback->before_compound_transition();
		}

		t_execution_steps l_execution_steps;
		t_raw_const_region_set l_entered_regions = {};
		Y_LOG( t_log_level::LL_TRACE, "Calculate execution step(s) for one compound transition." );
		m_transition_executor_impl->find_states_to_enter_and_to_exit_and_calculate_execution_steps( *compound_transition,
			l_execution_steps,
			l_entered_regions,
			p_event );
		Y_LOG( t_log_level::LL_TRACE, "Found % execution step(s).", l_execution_steps.size() );
		Y_LOG( t_log_level::LL_INFO, "Start running execution step(s)." );
		l_terminate_pseudostate_has_been_reached = m_transition_executor_impl->run_execution_steps( l_execution_steps,
			p_event_processing_callback,
			p_event );
		Y_LOG( t_log_level::LL_INFO, "Finished running execution step(s)." );
		if( l_terminate_pseudostate_has_been_reached )
		{
			Y_LOG( t_log_level::LL_INFO, "Terminate pseudostate has been reached." );
			break;
		}

		if( p_event_processing_callback )
		{
			p_event_processing_callback->after_compound_transition();
		}
	}

	Y_LOG( t_log_level::LL_TRACE, "End calculating execution step(s) for all compound transitions." );
	Y_LOG( t_log_level::LL_TRACE, "Search for choices." );
	m_transition_executor_impl->fill_vector_of_choices( p_vertices, p_compound_transitions );
	Y_LOG( t_log_level::LL_INFO, "Found % choice(s).", p_vertices.size() );
	return( l_terminate_pseudostate_has_been_reached );
}


}
