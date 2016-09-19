//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_transition_controller.h"

#include "log.h"
#include "i_composite_state.h"
#include "t_transition_finder.h"
#include "t_transition_executor.h"
#include "t_event.h"
#include "i_event_processing_callback.h"

#include "t_compound_transition.h"


namespace sxy
{


t_transition_controller::t_transition_controller
(
) = default;


t_transition_controller::~t_transition_controller
(
) = default;


bool
t_transition_controller::process_event
(
	const i_event& p_event,
	const i_composite_state& p_main_composite_state,
	i_event_processing_callback* const p_event_processing_callback,
	bool& p_event_is_deferred
)
{
	Y_LOG( sxy::t_log_level::LL_INFO, "Processing event '%'.", p_event.get_id() );

	auto l_reached_terminate_pseudostate = false;
	
	t_compound_transitions enabled_compound_transitions;


	Y_LOG( t_log_level::LL_SPAM, "Search for enabled transition(s) for event '%'.", p_event.get_id() );
	t_transition_finder transition_finder;
	transition_finder.search_for_enabled_transitions_in_all_regions
	(
		p_main_composite_state,
		p_event,
		enabled_compound_transitions,
		p_event_is_deferred
	);
	
	if( enabled_compound_transitions.empty() )
	{
		Y_LOG( sxy::t_log_level::LL_TRACE, "There are no compound transition to execute for the event '%'.", p_event.get_id());
 	}
	else
	{	
		Y_LOG( t_log_level::LL_TRACE, "Found % enabled transition(s) for event '%'.", enabled_compound_transitions.size(), p_event.get_id() );

		Y_LOG( t_log_level::LL_SPAM, "Start executing transition(s) for event '%'.", p_event.get_id() );
		l_reached_terminate_pseudostate = 
		execute_transitions
		( 
			p_main_composite_state, 
			enabled_compound_transitions, 
			p_event_processing_callback,
			p_event
		);		

		p_event_is_deferred = false;
	}

	Y_LOG( sxy::t_log_level::LL_INFO, "Processed event '%'.", p_event.get_id() );

	return( l_reached_terminate_pseudostate );
}


bool
t_transition_controller::start_state_machine
(
	const i_composite_state& p_main_composite_state,
	i_event_processing_callback* const p_event_processing_callback
)
{
	auto l_terminate_pseudostate_has_been_reached = false;
	t_compound_transitions enabled_compound_transitions;

	t_transition_finder transition_finder;
	Y_LOG( t_log_level::LL_TRACE, "Searching for initial transitions." );
	transition_finder.search_initial_transitions( p_main_composite_state, enabled_compound_transitions);
	 
	if( enabled_compound_transitions.empty() )
	{
		Y_LOG( sxy::t_log_level::LL_TRACE, "No initial transitions found." );
	}
	else
	{
		Y_LOG( t_log_level::LL_TRACE, "Found % compound transition(s) after searching for initial transitions.", enabled_compound_transitions.size() );

		t_event event(COMPLETION_EVENT);		
		Y_LOG( t_log_level::LL_TRACE, "Executing transitions." );
		if( execute_transitions( p_main_composite_state, enabled_compound_transitions, p_event_processing_callback, event ) )
		{
			Y_LOG( t_log_level::LL_INFO, "Terminate pseudostate has been reached." );
			l_terminate_pseudostate_has_been_reached = true;
		}
	}
	
	return ( l_terminate_pseudostate_has_been_reached );
}


bool
t_transition_controller::execute_transitions
(
	const i_composite_state& p_main_composite_state,
	t_compound_transitions& compound_transitions,
	i_event_processing_callback* const p_event_processing_callback,
	const i_event& p_event
)
{
	auto l_terminate_pseudostate_has_been_reached = false;

	t_transition_executor transition_executor;
	
	while( !compound_transitions.empty() )
	{	
		t_raw_const_choices l_choices;
		
		if( p_event_processing_callback )
		{
			p_event_processing_callback->before_event_processings_stage();
		}

		Y_LOG( t_log_level::LL_TRACE, "Check sort and execute transitions." );
		l_terminate_pseudostate_has_been_reached = 
		transition_executor.check_sort_and_execute_transitions
		(
			compound_transitions,
			l_choices, 
			p_event_processing_callback,
			p_event
		);


		if( l_terminate_pseudostate_has_been_reached )
		{
			Y_LOG( t_log_level::LL_INFO, "Terminate pseudostate has been reached. The execution is stopping." );
			break;
		}

		compound_transitions.clear();

		Y_LOG( t_log_level::LL_SPAM, "Search for choice transitions." );		
		search_choice_transitions( l_choices, compound_transitions, p_event );
		Y_LOG( t_log_level::LL_TRACE, "Found % transition(s) after searched for choice transitions.", compound_transitions.size() );
		
		if( compound_transitions.empty() )
		{
			Y_LOG( t_log_level::LL_TRACE, "Searching for completion event transition." );
			search_completion_event_transitions( p_main_composite_state, compound_transitions );	
		}	

		if( p_event_processing_callback )
		{
			p_event_processing_callback->after_event_processings_stage( l_choices );
		}
	}

	return( l_terminate_pseudostate_has_been_reached );
}


void
t_transition_controller::search_choice_transitions
(		
	const t_raw_const_choices& p_choices,
	t_compound_transitions& compound_transitions,
	const i_event& p_event
)
{		
	t_transition_finder transition_finder;																					
	transition_finder.search_choice_transitions( p_choices, compound_transitions, p_event );
}


void
t_transition_controller::search_completion_event_transitions
(
	const i_composite_state& p_main_composite_state,
	t_compound_transitions& compound_transitions	
)
{	
	auto l_event_is_deferred = false;
	t_transition_finder transition_finder;
	transition_finder.search_for_enabled_completion_transitions_in_all_regions
	(
		p_main_composite_state,
		compound_transitions,
		l_event_is_deferred
	);

	Y_ASSERT( !l_event_is_deferred, "An completion transition was deferred!" );
}


}
