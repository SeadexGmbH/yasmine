//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_initial_pseudostate.h"

#include "base.h"
#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_pseudostate_visitor.h"
#include "i_transition.h"
#include "t_state_machine_defects.h"


namespace sxy
{


t_initial_pseudostate::t_initial_pseudostate( const std::string& p_name )
	: t_region_pseudostate( p_name )
{
	// Nothing to do...
}


t_initial_pseudostate::~t_initial_pseudostate() = default;


bool t_initial_pseudostate::check( t_state_machine_defects& p_defects ) const
{
	auto l_check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [1]: An initial vertex can have at most one outgoing transition.
	if( get_outgoing_transitions().size() > 1 )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
				"Initial pseudostate '%' has more then 1 outgoing transition! It has '%' transitions.", get_name(),
				get_outgoing_transitions().size() ) );
		l_check_ok = false;
	}

	// check exactly 1 outgoing transition
	if( get_outgoing_transitions().size() != 1 )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
				"Initial pseudostate '%' doesn't have exactly 1 outgoing transition! It has % transition(s).", get_name(),
				get_outgoing_transitions().size() ) );
		l_check_ok = false;
	}

	// 15.3.8 Pseudostate -> Constraint [9]: Outgoing transition from an initial vertex may have a behavior, but not a
	// trigger or guard.
	for( const auto & l_transition : get_outgoing_transitions() )
	{
		if( l_transition->get_guard() )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
					"Outgoing transition '%' of initial pseudostate '%' has a guard!", l_transition->get_name(), get_name() ) );
			l_check_ok = false;
		}
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !t_pseudostate::check( p_defects ) )
	{
		l_check_ok = false;
	}

	return( l_check_ok );
}


void t_initial_pseudostate::accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_initial_pseudostate::accept_vertex_visitor( i_vertex_visitor& p_visitor )
{
	p_visitor.visit( *this );
}


void t_initial_pseudostate::accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


i_transition* t_initial_pseudostate::get_transition() const
{
	const auto& l_transitions = get_outgoing_transitions();
	Y_ASSERT( !l_transitions.empty(), "There are no transitions!" );
	return( l_transitions.front() );
}


void t_initial_pseudostate::add_incoming_transition( i_transition& p_incoming_transition )
{
	Y_UNUSED_PARAMETER( p_incoming_transition );
	Y_ASSERT( t_vertex::get_incoming_transitions().empty(), "Initial pseudostate cannot have incoming transitions!" );
}


}
