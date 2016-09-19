//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_try_to_build_compound_transition_visitor.h"

#include "base.h"

#include "i_join.h"
#include "t_compound_transition.h"
#include "t_compound_transition_builder.h"
#include "i_event.h"


namespace sxy
{


t_try_to_build_compound_transition_visitor::t_try_to_build_compound_transition_visitor(	
	i_transition& p_enabled_transition,	t_compound_transitions& p_enabled_compound_transitions,	bool& p_is_built,	
	const i_event& p_event )
	: m_enabled_transition( p_enabled_transition ),
		m_enabled_compound_transitions( p_enabled_compound_transitions ),
		m_is_built( p_is_built ),
		m_event( p_event )
{
	m_is_built = false;
}


t_try_to_build_compound_transition_visitor::~t_try_to_build_compound_transition_visitor() = default; 


void t_try_to_build_compound_transition_visitor::visit( const i_composite_state& p_composite_state )
{
	Y_UNUSED_PARAMETER( p_composite_state );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit(	const i_simple_state& p_simple_state )
{
	Y_UNUSED_PARAMETER( p_simple_state );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit(	const i_final_state& p_final_state )
{
	Y_UNUSED_PARAMETER( p_final_state );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit(	const i_initial_pseudostate& p_initial_pseudostate )
{
	Y_UNUSED_PARAMETER( p_initial_pseudostate );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit(	const i_choice& p_choice )
{
	Y_UNUSED_PARAMETER( p_choice );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit(	const i_junction& p_junction )
{
	Y_UNUSED_PARAMETER( p_junction );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit( const i_join& p_join )
{
	check_if_join_is_active_and_was_not_processed_yet( p_join );
}


void t_try_to_build_compound_transition_visitor::visit(	const i_fork& p_fork )
{
	Y_UNUSED_PARAMETER( p_fork );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit(	const i_entry_point& p_entry_point )
{
	Y_UNUSED_PARAMETER( p_entry_point );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit(	const i_exit_point& p_exit_point )
{
	Y_UNUSED_PARAMETER( p_exit_point );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit(	const i_deep_history& p_deep_history )
{
	Y_UNUSED_PARAMETER( p_deep_history );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::visit(	const i_shallow_history& p_shallow_history )
{
	Y_UNUSED_PARAMETER( p_shallow_history );
	build_compound_transition_and_insert_in_container();
}
																					

void t_try_to_build_compound_transition_visitor::visit(	const i_terminate_pseudostate& p_terminate_pseudostate )
{
	Y_UNUSED_PARAMETER( p_terminate_pseudostate );
	build_compound_transition_and_insert_in_container();
}


void t_try_to_build_compound_transition_visitor::build_compound_transition_and_insert_in_container()
{
	auto compound_transition = sxy::build_compound_transition( m_enabled_transition, m_event );
	if( compound_transition )
	{
		m_enabled_compound_transitions.push_back( std::move( compound_transition ) );
		m_is_built = true;
	}
}


void t_try_to_build_compound_transition_visitor::check_if_join_is_active_and_was_not_processed_yet( 
	const i_join& p_join )
{
	const auto& transition_was_already_used = 
		check_if_transition_was_already_used( m_enabled_transition, m_enabled_compound_transitions );

	if( !transition_was_already_used )
	{
		const auto& all_incoming_transitions_enabled 
			= p_join.check_if_all_source_states_of_incoming_transitions_are_active();
		if( all_incoming_transitions_enabled )
		{
			build_compound_transition_and_insert_in_container( );
		}
	}
	else
	{
		// The compound transition for this join was already built somewhere else. So the transition search has to end in
		// this branch.
		m_is_built = true;
	}
}


bool t_try_to_build_compound_transition_visitor::check_if_transition_was_already_used(	
	const i_transition& p_transition,	t_compound_transitions& p_compound_transitions )
{
	auto already_used = false;
	for( const auto& compound_transition : p_compound_transitions )
	{
		already_used = compound_transition->check_if_starts_with( p_transition );
		if( already_used )
		{
			break;
		}
	}

	return( already_used );
}


}
