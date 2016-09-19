//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_join.h"

#include "base.h"
#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_pseudostate_visitor.h"
#include "i_complex_state.h"
#include "i_transition.h"
#include "t_check_if_all_incoming_transitions_sources_are_active_visitor.h"
#include "t_state_machine_defects.h"
#include "i_composite_state.h"


namespace sxy
{


t_join::t_join( const std::string& p_name )
	: t_region_pseudostate( p_name )
{
	// Nothing to do...
}


t_join::~t_join() = default;




bool t_join::check_if_all_source_states_of_incoming_transitions_are_active() const
{
	auto all_incoming_transitions_srouces_are_active = true;
	const auto& incoming_transitions = get_incoming_transitions();

	for( const auto & transition : incoming_transitions )
	{
		const auto& source = transition->get_source();
		const auto complex_state = dynamic_cast< const i_complex_state* >( &source );
		Y_ASSERT( complex_state, "Incoming transitions into join must originate from i_complex_state!" );
		t_check_if_all_incoming_transitions_sources_are_active_visitor check_if_all_incoming_transitions_sources_are_active_visitor;
		complex_state->accept_complex_state_visitor( check_if_all_incoming_transitions_sources_are_active_visitor );
		all_incoming_transitions_srouces_are_active =
			check_if_all_incoming_transitions_sources_are_active_visitor.get_result();
		if( !all_incoming_transitions_srouces_are_active )
		{
			break;
		}
	}

	return( all_incoming_transitions_srouces_are_active );
}


void t_join::accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_join::accept_vertex_visitor( i_vertex_visitor& p_visitor )
{
	p_visitor.visit( *this );
}


void t_join::accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


bool t_join::check( t_state_machine_defects& p_defects ) const
{
	auto l_check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [3]: A join vertex must have at least two incoming transitions and exactly one
	// outgoing transition.
	if( get_incoming_transitions().size() < 2 )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,	
			"Join has too few incoming transitions!" ) );
		l_check_ok = false;
	}

	if( get_outgoing_transitions().size() != 1 )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
			"Join does not have exactly 1 outgoing transition!" ) );
		l_check_ok = false;
	}

	// 15.3.8 Pseudostate -> Constraint [4]: All transitions incoming a join vertex must originate in (math formula
	// contains no "different") regions of an orthogonal state.
	// 2 incoming transitions cannot leave the same region
	std::set< const i_composite_state* > l_lca_composite_states = {};
	auto transitions = get_incoming_transitions();

	for( auto l_iterator_1 = transitions.begin(); l_iterator_1 < transitions.end(); ++l_iterator_1 )
	{
		for( auto l_iterator_2 = l_iterator_1 + 1; l_iterator_2 < transitions.end(); ++l_iterator_2 )
		{
			const auto& l_source_1 = ( *l_iterator_1 )->get_source();
			const auto& l_source_2 = ( *l_iterator_2 )->get_source();
			const auto l_lca = l_source_1.LCA_composite_state( l_source_2 );
			auto l_result = l_lca_composite_states.insert( l_lca );
			if( !l_result.second )
			{
				p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
					"Join '%' has incoming transitions that originate in same region of a composite state!", get_name() ) );
				l_check_ok = false;
				break;
			}
		}
	}

	// 15.3.14 Transition -> Constraint [2]: A join segment must not have guards or triggers.
	for( const auto & l_transition : get_incoming_transitions() )
	{
		if( l_transition->get_guard() )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect >( *this, "Join has guard!" ) );
			l_check_ok = false;
		}
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !t_pseudostate::check( p_defects ) )
	{
		l_check_ok = false;
	}

	// 15.3.14 Transition -> Contraint [4]: A join segment must always originate from a state.
	for( const auto & l_transition : get_incoming_transitions() )
	{
		const auto l_source_vertex = dynamic_cast< const i_state* >( &l_transition->get_source() );
		if( !l_source_vertex )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
				"Join segment does not originate from a state!" ) );
			l_check_ok = false;
		}
		else
		{
			l_source_vertex->check( p_defects );
		}
	}

	return( l_check_ok );
}


void t_join::add_outgoing_transition( i_transition& p_outgoing_transition )
{
	Y_ASSERT( t_vertex::get_outgoing_transitions().size() < 1, "Join cannot have more than 1 outgoing transition!" );
	t_vertex::add_outgoing_transition( p_outgoing_transition );
}


}
