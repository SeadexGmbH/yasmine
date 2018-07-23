//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "initial_pseudostate_impl.hpp"

#include "essentials/base.hpp"

#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "pseudostate_visitor.hpp"
#include "transition.hpp"
#include "state_machine_defect.hpp"


namespace sxy
{


initial_pseudostate_impl::initial_pseudostate_impl( const std::string& _name )
	: region_pseudostate_impl( _name )
{
	// Nothing to do...
}


initial_pseudostate_impl::~initial_pseudostate_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


bool initial_pseudostate_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [1]: An initial vertex can have at most one outgoing transition.
	if( get_outgoing_transitions().size() > 1 )
	{
		_defects.push_back( state_machine_defect( *this,
				"Initial pseudostate '%' has more than 1 outgoing transition! It has '%' transitions.", get_name(),
				get_outgoing_transitions().size() ) );
		check_ok = false;
	}

	// check exactly 1 outgoing transition
	if( get_outgoing_transitions().size() != 1 )
	{
		_defects.push_back( state_machine_defect( *this,
				"Initial pseudostate '%' doesn't have exactly 1 outgoing transition! It has % transition(s).", get_name(),
				get_outgoing_transitions().size() ) );
		check_ok = false;
	}

	// 15.3.8 Pseudostate -> Constraint [9]: Outgoing transition from an initial vertex may have a behavior, but not a
	// trigger or guard.
	SX_FOR( const transition* const transition, get_outgoing_transitions() )
	{
		if( transition->get_guard() )
		{
			_defects.push_back( state_machine_defect( *this,
					"Outgoing transition '%' of initial pseudostate '%' has a guard!", transition->get_name(), get_name() ) );
			check_ok = false;
		}
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !pseudostate_impl::check( _defects ) )
	{
		check_ok = false;
	}
		

	return( check_ok );
}


void initial_pseudostate_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void initial_pseudostate_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void initial_pseudostate_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


transition* initial_pseudostate_impl::get_transition() const
{
	const raw_transitions& transitions = get_outgoing_transitions();
	SX_ASSERT( !transitions.empty(), "There are no transitions!" );
	return( transitions.front() );
}


void initial_pseudostate_impl::add_incoming_transition( transition& _incoming_transition )
{
	SX_UNUSED_PARAMETER( _incoming_transition );
	SX_ASSERT( vertex_impl::get_incoming_transitions().empty(), "Initial pseudostate cannot have incoming transitions!" );
}


}
