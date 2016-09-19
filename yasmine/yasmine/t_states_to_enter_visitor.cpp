//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_states_to_enter_visitor.h"

#include "base.h"
#include "i_simple_state.h"
#include "i_composite_state.h"
#include "i_final_state.h"
#include "i_region.h"
#include "i_deep_history.h"
#include "i_shallow_history.h"


namespace sxy
{


t_states_to_enter_visitor::t_states_to_enter_visitor( t_raw_states_by_nesting_level& p_states_to_enter,
	t_raw_const_region_set& p_regions_to_enter, i_composite_state& p_LCA_of_compound_transition )
	: m_states_to_enter( p_states_to_enter ),
		m_regions_to_enter( p_regions_to_enter ),
		m_LCA_of_compound_transition( p_LCA_of_compound_transition )
{
	// Nothing to do...
}


t_states_to_enter_visitor::~t_states_to_enter_visitor() = default;


void t_states_to_enter_visitor::visit( i_composite_state& p_composite_state )
{
	insert_states_to_enter( p_composite_state );
}


void t_states_to_enter_visitor::visit( i_simple_state& p_simple_state )
{
	insert_states_to_enter( p_simple_state );
}


void t_states_to_enter_visitor::visit( i_final_state& p_final_state )
{
	insert_states_to_enter( p_final_state );
}


void t_states_to_enter_visitor::visit( i_initial_pseudostate& p_initial_pseudostate )
{
	Y_UNUSED_PARAMETER( p_initial_pseudostate );
	Y_ASSERT( false, "A pseudostate cannot be entered!" );
}


void t_states_to_enter_visitor::visit( i_choice& p_choice )
{
	Y_UNUSED_PARAMETER( p_choice );	
}


void t_states_to_enter_visitor::visit( i_junction& p_junction )
{
	Y_UNUSED_PARAMETER( p_junction );
	Y_ASSERT( false, "A pseudostate cannot be entered!" );
}


void t_states_to_enter_visitor::visit( i_join& p_join )
{
	Y_UNUSED_PARAMETER( p_join );
	Y_ASSERT( false, "A pseudostate cannot be entered!" );
}


void t_states_to_enter_visitor::visit( i_fork& p_fork )
{
	Y_UNUSED_PARAMETER( p_fork );
	Y_ASSERT( false, "A pseudostate cannot be entered!" );
}


void t_states_to_enter_visitor::visit( i_entry_point& p_entry_point )
{
	Y_UNUSED_PARAMETER( p_entry_point );
	Y_ASSERT( false, "A pseudostate cannot be entered!" );
}


void t_states_to_enter_visitor::visit( i_exit_point& p_exit_point )
{
	Y_UNUSED_PARAMETER( p_exit_point );
	Y_ASSERT( false, "A pseudostate cannot be entered!" );
}


void t_states_to_enter_visitor::visit( i_deep_history& p_deep_history )
{
	auto& l_parent_state = p_deep_history.get_parent_state();
	m_states_to_enter.insert( &l_parent_state );
	add_last_active_child_states_to_enter( l_parent_state );
}


void t_states_to_enter_visitor::visit( i_shallow_history& p_shallow_history )
{
	auto& l_parent_state = p_shallow_history.get_parent_state();
	m_states_to_enter.insert( &l_parent_state );

	for( const auto & l_region : l_parent_state.get_regions() )
	{
		const auto l_last_active_state_of_region = l_region->get_last_active_state();
		if( l_last_active_state_of_region )
		{
			m_states_to_enter.insert( l_last_active_state_of_region );
		}

		m_regions_to_enter.insert( l_last_active_state_of_region->get_parent_region() );
	}
}


void t_states_to_enter_visitor::visit( i_terminate_pseudostate& p_terminate_pseudostate )
{
	Y_UNUSED_PARAMETER( p_terminate_pseudostate );
}


void t_states_to_enter_visitor::get_states_up_to_LCA( i_state& p_state )
{
	auto l_ancestors = p_state.get_ancestors( &m_LCA_of_compound_transition );

	for( auto l_ancestor : l_ancestors )
	{
		if( l_ancestor != &m_LCA_of_compound_transition )
		{
			m_states_to_enter.insert( l_ancestor );
		}
	}

	m_states_to_enter.insert( &p_state );
}


void t_states_to_enter_visitor::get_regions_up_to_LCA( const i_state& p_state )
{
	auto l_ancestors_as_regions = p_state.get_ancestors_as_regions();

	for( auto l_ancestor_as_region : l_ancestors_as_regions )
	{
		if( &l_ancestor_as_region->get_parent_state() != &m_LCA_of_compound_transition )
		{
			m_regions_to_enter.insert( l_ancestor_as_region );
		}
	}
}


void t_states_to_enter_visitor::add_last_active_child_states_to_enter( const i_state& p_state )
{
	for( auto & l_region : p_state.get_regions() )
	{
		const auto l_state = l_region->get_last_active_state();
		m_states_to_enter.insert( l_state );
		m_regions_to_enter.insert( l_state->get_parent_region() );
		add_last_active_child_states_to_enter( *l_state );
	}
}


void t_states_to_enter_visitor::insert_states_to_enter( i_state& p_state )
{
	m_states_to_enter.insert( &p_state );
	m_regions_to_enter.insert( p_state.get_parent_region() );
	get_states_up_to_LCA( p_state );
	get_regions_up_to_LCA( p_state );
}


}
