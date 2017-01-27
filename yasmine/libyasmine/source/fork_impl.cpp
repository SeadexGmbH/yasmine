//////////////////////////////////////////////////////////////////////////////////////////////////////

//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "fork_impl.hpp"

#include <algorithm>

#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "pseudostate_visitor.hpp"
#include "transition_impl.hpp"
#include "state.hpp"
#include "state_machine_defect.hpp"
#include "region.hpp"
#include "base.hpp"


namespace sxy
{


fork_impl::fork_impl( const std::string& _name )
	: region_pseudostate_impl( _name )
{
	// Nothing to do...
}


fork_impl::~fork_impl() Y_NOEXCEPT
{
	// Nothing to do...
}


bool fork_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [5]: Fork must have at least 2 outgoing transitions and exactly 1 incoming
	// transition.
	if( get_outgoing_transitions().size() < 2 )
	{
		_defects.push_back( state_machine_defect( *this,
				"Fork '%' has too few outgoing transitions! It has % transition(s).", get_name(),
				get_outgoing_transitions().size() ) );
		check_ok = false;
	}

	if( get_incoming_transitions().size() != 1 )
	{
		_defects.push_back( state_machine_defect( *this,
				"Fork '%' does not have exactly 1 incoming transition! It has % transition(s),", get_name(),
				get_outgoing_transitions().size() ) );
		check_ok = false;
	}

	// 15.3.8 Pseudostate -> Constraint [6]: All transitions outgoing a fork vertex must target states in different
	// regions of an state.
	// This check is not mandatory. The last LCA is the state machine itself. -> Jira[104] / Jira[103]
	// 15.3.14 Transition -> Constraint [1]: A fork segment must not have guards or triggers.
	Y_FOR( const transition * const transition, get_outgoing_transitions() )
	{
		if( transition->get_guard() )
		{
			_defects.push_back( state_machine_defect( *this, "Outgoing transition '%' of fork '%' has guard!",
					transition->get_name(), get_name() ) );
			check_ok = false;
		}
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !pseudostate_impl::check( _defects ) )
	{
		check_ok = false;
	}

	// 15.3.14 Transition -> Constraint [3]: A fork segment must always target a state.
	Y_FOR( const transition * const transition, get_outgoing_transitions() )
	{
		const state* const target_vertex = dynamic_cast< const state* >( &transition->get_target() );
		if( !target_vertex )
		{				
			_defects.push_back( state_machine_defect( *this,
					"Fork '%' has outgoing transition ('%') that hasn't a state as target! Target vertex is '%'.", get_name(),
					transition->get_name(), transition->get_target().get_name()) );
			check_ok = false;
		}
		else
		{
			target_vertex->check( _defects );
		}
	}

	// 2 outgoing transitions cannot enter the same region
	std::set< const region* > target_regions;
	Y_FOR( const transition * const transition, get_outgoing_transitions() )
	{
		const state_machine_element* const target_region = transition->get_target().get_parent();
		const region* const l_region = dynamic_cast< const region* >( target_region );
		if( l_region )
		{
			std::pair< std::set< const region* >::const_iterator, bool > result = target_regions.insert( l_region );
			if( !result.second )
			{
				_defects.push_back( state_machine_defect( *this,
						"Fork '%' has outgoing transition(s) that has(have) the same target region '%'.", get_name(),
						l_region->get_name() ) );
				check_ok = false;
				break;
			}
		}
	}
	const transition_kind transitions_kind = get_outgoing_transitions().front()->get_kind();
	Y_FOR( const transition * const transition, get_outgoing_transitions() )
	{
		if( !(transitions_kind == transition->get_kind()) )
		{
			_defects.push_back( state_machine_defect( *this, "Outgoing transitions of fork '%' have different kinds!",
					get_name() ) );
			check_ok = false;
			break;
		}
	}
	return( check_ok );
}


void fork_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void fork_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void fork_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void fork_impl::add_incoming_transition( transition& _incoming_transition )
{
	Y_ASSERT( vertex_impl::get_incoming_transitions().size() < 1, "Fork cannot have more than 1 incoming transition!" );
	vertex_impl::add_incoming_transition( _incoming_transition );
}


}
