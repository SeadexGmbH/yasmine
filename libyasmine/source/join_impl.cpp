//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "join_impl.hpp"

#include "essentials/base.hpp"

#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "pseudostate_visitor.hpp"
#include "complex_state.hpp"
#include "transition.hpp"
#include "check_if_all_incoming_transitions_sources_are_active_visitor.hpp"
#include "state_machine_defect.hpp"
#include "composite_state.hpp"


namespace sxy
{


join_impl::join_impl( const std::string& _name )
	: region_pseudostate_impl( _name )
{
	// Nothing to do...
}


join_impl::~join_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


bool join_impl::check_if_all_source_states_of_incoming_transitions_are_active() const
{
	bool all_incoming_transitions_srouces_are_active = true;
	const raw_transitions& incoming_transitions = get_incoming_transitions();

	SX_FOR( const transition* const transition, incoming_transitions )
	{
		const vertex& source = transition->get_source();
		const complex_state* const l_complex_state = dynamic_cast< const complex_state* >( &source );
		SX_ASSERT( l_complex_state, "Incoming transitions into join must originate from complex_state!" );
		check_if_all_incoming_transitions_sources_are_active_visitor check_if_all_incoming_transitions_sources_are_active_visitor;
		l_complex_state->accept_complex_state_visitor( check_if_all_incoming_transitions_sources_are_active_visitor );
		all_incoming_transitions_srouces_are_active =
			check_if_all_incoming_transitions_sources_are_active_visitor.get_result();
		if( !all_incoming_transitions_srouces_are_active )
		{
			break;
		}
	}

	return( all_incoming_transitions_srouces_are_active );
}


void join_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void join_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void join_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


bool join_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [3]: A join vertex must have at least two incoming transitions and exactly one
	// outgoing transition.
	if( get_incoming_transitions().size() < 2 )
	{
		_defects.push_back( state_machine_defect( *this,
			"Join has too few incoming transitions!" ) );
		check_ok = false;
	}

	if( get_outgoing_transitions().size() != 1 )
	{
		_defects.push_back( state_machine_defect( *this,
			"Join does not have exactly 1 outgoing transition!" ) );
		check_ok = false;
	}

	// 15.3.8 Pseudostate -> Constraint [4]: All transitions incoming a join vertex must originate in (math formula
	// contains no "different") regions of an orthogonal state.
	// 2 incoming transitions cannot leave the same region
	std::set< const composite_state* > lca_composite_states;
	const raw_transitions& transitions = get_incoming_transitions();

	for(raw_transitions::const_iterator iterator_1 = transitions.begin(); iterator_1 < transitions.end(); ++iterator_1 )
	{
		for(raw_transitions::const_iterator iterator_2 = iterator_1 + 1; iterator_2 < transitions.end(); ++iterator_2 )
		{
			const vertex& source_1 = ( *iterator_1 )->get_source();
			const vertex& source_2 = ( *iterator_2 )->get_source();
			const composite_state* const lca = source_1.LCA_composite_state( source_2 );
			const region* const lca_region = source_1.LCA_region( source_2 );			
			if( lca_region != lca->get_parent_region() )
			{
				_defects.push_back( state_machine_defect( *this,
					"Join '%' has incoming transitions that originate in same region of a composite state!", get_name() ) );
				check_ok = false;
				break;
			}
		}
	}

	// 15.3.14 Transition -> Constraint [2]: A join segment must not have guards or triggers.
	SX_FOR( const transition* const transition, get_incoming_transitions() )
	{
		if( transition->get_guard() )
		{
			_defects.push_back( state_machine_defect( *this, "Join has guard!" ) );
			check_ok = false;
		}
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !pseudostate_impl::check( _defects ) )
	{
		check_ok = false;
	}

	// 15.3.14 Transition -> Contraint [4]: A join segment must always originate from a state.
	SX_FOR( const transition* const transition, get_incoming_transitions() )
	{
		const state* const source_vertex = dynamic_cast< const state* >( &transition->get_source() );
		if( !source_vertex )
		{
			_defects.push_back( state_machine_defect( *this,
				"Join segment does not originate from a state!" ) );
			check_ok = false;
		}
		else
		{
			source_vertex->check( _defects );
		}
	}

	return( check_ok );
}


void join_impl::add_outgoing_transition( transition& _outgoing_transition )
{
	SX_ASSERT( vertex_impl::get_outgoing_transitions().size() < 1, "Join cannot have more than 1 outgoing transition!" );
	vertex_impl::add_outgoing_transition( _outgoing_transition );
}


}
