//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_transition_finder.h"

#include "t_log_and_throw.h"
#include "i_composite_state.h"
#include "i_region.h"
#include "i_initial_pseudostate.h"
#include "i_choice.h"
#include "i_transition.h"
#include "t_compound_transition_builder.h"
#include "t_event.h"


namespace sxy
{


t_transition_finder::t_transition_finder
(
) = default;


t_transition_finder::~t_transition_finder
(
) = default;


void
t_transition_finder::search_for_enabled_transitions_in_all_regions
(
	const i_state& p_current_state,
	const i_event& p_event,
	t_compound_transitions& p_enabled_compound_transitions,
	bool& p_event_is_deferred
) const
{
	search_for_transition( p_current_state, p_enabled_compound_transitions, p_event, p_event_is_deferred );
}


void
t_transition_finder::search_for_enabled_completion_transitions_in_all_regions
(
	const i_state& p_current_state,
	t_compound_transitions& p_enabled_compound_transitions,
	bool& p_event_is_deferred
) const
{
	const auto l_completion_event = std::make_shared< t_event >( COMPLETION_EVENT );
	search_for_transition( p_current_state, p_enabled_compound_transitions, *l_completion_event, p_event_is_deferred );
}


void
t_transition_finder::search_initial_transitions
(
	const i_composite_state& p_state,
	t_compound_transitions& p_compound_transitions	
)
{
	for( const auto& l_region : p_state.get_regions() )
	{
		Y_LOG( t_log_level::LL_TRACE, "Searching for initial state in region '%'.", l_region->get_name() );
		const auto l_initial_pseudostate = l_region->get_initial_pseudostate();
		if( l_initial_pseudostate )
		{
			Y_LOG( t_log_level::LL_TRACE, "Initial state '%' found in region '%'.", l_initial_pseudostate->get_name(), l_region->get_name() );
			const auto l_transition = l_initial_pseudostate->get_transition();			
			const auto l_complition_event = std::make_shared<t_event>( COMPLETION_EVENT );
			if(!try_to_build_compound_transition( *l_transition, p_compound_transitions, *l_complition_event ))
			{	
				LOG_AND_THROW( t_log_level::LL_FATAL, "A compound transition could not be built after an initial pseudostate!" );				
			}			
		}
	}
}	 


void
t_transition_finder::search_choice_transitions
(
	const t_raw_const_choices& p_choices,
	t_compound_transitions& p_compound_transitions,
	const i_event& p_event
)
{
	for( const auto l_choice : p_choices )
	{
		Y_ASSERT( l_choice, "Choice pointer is null. This cannot be a nullptr." );

		Y_LOG( t_log_level::LL_SPAM, "Checking outgoing transition(s) of choice '%'.", l_choice->get_name() );
		Y_LOG( t_log_level::LL_SPAM, "Choice '%' has % outgoing transition(s).", l_choice->get_name(), l_choice->get_outgoing_transitions().size() );
		auto l_at_least_one_transition_is_enabled = false;
		for( auto& l_transition : l_choice->get_outgoing_transitions() )
		{
			Y_ASSERT( l_transition->can_accept_event( COMPLETION_EVENT ), "Transition leaving choice is not a completion transition!" );

			Y_LOG( t_log_level::LL_SPAM, "Checking outgoing transition '%' of choice '%' for guard.", l_transition->get_name(), l_choice->get_name() );
			const auto guard_evaluated_to_true = l_transition->check_guard( p_event );
			if( guard_evaluated_to_true )
			{
				Y_LOG( t_log_level::LL_SPAM, "Guard of outgoing transition '%' of choice '%' evaluates to true.", l_transition->get_name(), l_choice->get_name() );
				if( !try_to_build_compound_transition( *l_transition, p_compound_transitions, p_event ) )
				{
					LOG_AND_THROW( t_log_level::LL_FATAL, "Transition following choice '%' could not be built in compound transition!", l_choice->get_name() );					
				}
				else
				{
					l_at_least_one_transition_is_enabled = true;
				}
				break;
			}
			else
			{
				Y_LOG( t_log_level::LL_SPAM, "Guard of outgoing transition '%' of choice '%' evaluates to false.", l_transition->get_name(), l_choice->get_name() );
			}
		}

		if( !l_at_least_one_transition_is_enabled )
		{
			LOG_AND_THROW( t_log_level::LL_FATAL, "No transition was enabled for choice '%'!", l_choice->get_name() );			
		}																																									
	}
}
	 

i_transition*
t_transition_finder::search_completion_transition
(
	const i_state& p_state
)
{
	i_transition* completion_transition = nullptr;

	if( p_state.is_complete() )
	{			
		Y_LOG( t_log_level::LL_SPAM, "State '%' is complete.", p_state.get_name() );
		const auto l_completion_event = std::make_shared< t_event >( COMPLETION_EVENT );
		completion_transition = p_state.search_transition( *l_completion_event );
	}

	return( completion_transition );
}


bool
t_transition_finder::search_for_transition
(
	const i_state& p_current_state,
	t_compound_transitions& p_enabled_compound_transitions,
	const i_event& p_event,
	bool& p_event_is_deferred
) const
{
	Y_LOG( t_log_level::LL_INFO, "Search for transition in state '%'.", p_current_state.get_name() );
	auto found = false;

	const auto& regions = p_current_state.get_regions();
	for( const auto& region : regions )
	{
		Y_LOG( t_log_level::LL_TRACE, "Search for active state in region '%'.", region->get_name() );
		const auto active_state = region->get_active_state();
		if( active_state )
		{
			Y_LOG( t_log_level::LL_TRACE, "Found active state '%' in region '%'.", active_state->get_name(), region->get_name() );
			auto l_found = search_for_transition( *active_state, p_enabled_compound_transitions, p_event, p_event_is_deferred );
			if( l_found )
			{
				Y_LOG( t_log_level::LL_TRACE, "Transition found in the active state '%'.", active_state->get_name() );
				found = l_found;
			}
			else
			{
				Y_LOG( t_log_level::LL_TRACE, "Transition not found in the active state '%'.", active_state->get_name() );
			}			
		}
	}

	if( !found )
	{
		i_transition* transition = nullptr;
		if( COMPLETION_EVENT == p_event.get_id() )
		{
			Y_LOG( t_log_level::LL_TRACE, "Search completion transition in state '%'.", p_current_state.get_name() );
			transition = search_completion_transition( p_current_state );
		}
		else
		{
			Y_LOG( t_log_level::LL_TRACE, "Search transition with event id % in state '%'.", p_event.get_id(), p_current_state.get_name() );
			transition = p_current_state.search_transition( p_event );
		}

		if( transition )
		{
			Y_LOG( t_log_level::LL_TRACE, "Transition '%' found in the current state '%'.", transition->get_name(), p_current_state.get_name() );
			
			found = try_to_build_compound_transition( *transition, p_enabled_compound_transitions, p_event );
			if( found )
			{
				Y_LOG( t_log_level::LL_SPAM, "Transition '%' was built in compound transition.", transition->get_name() );
			}
			else
			{
				Y_LOG( t_log_level::LL_SPAM, "Transition '%' was not built in compound transition.", transition->get_name() );
			}
		}
		else
		{
			Y_LOG( t_log_level::LL_TRACE, "Transition not found in current state '%'.", p_current_state.get_name() );
						
			if( p_current_state.is_event_deferred( p_event.get_id() ) )
			{
				p_event_is_deferred = true;
				found = true;
			}
		}
	}

	return( found );
}


}
