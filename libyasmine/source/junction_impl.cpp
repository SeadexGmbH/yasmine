//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "junction_impl.hpp"

#include "log.hpp"
#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "pseudostate_visitor.hpp"
#include "state_machine_defect.hpp"
#include "transition.hpp"


namespace sxy
{


junction_impl::junction_impl( const std::string& _name )
	: region_pseudostate_impl( _name )
{
	// Nothing to do...
}


junction_impl::~junction_impl() Y_NOEXCEPT
{
	// Nothing to do...
}


bool junction_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [7]: A junction vertex must have at least one incoming and one outgoing
	// transition.
	Y_LOG( log_level::LL_SPAM, "Checking if junction '%' has incoming transition(s).", get_name() );
	if( get_incoming_transitions().empty() )
	{
		_defects.push_back( state_machine_defect( *this,
			"Junction has too few incoming transitions!" ) );
		check_ok = false;
	}

	Y_LOG( log_level::LL_SPAM, "Junction '%' has % incoming transition(s).", get_name(),
		get_incoming_transitions().size() );
	Y_LOG( log_level::LL_SPAM, "Checking if junction '%' has outgoing transition(s).", get_name() );
	if( get_outgoing_transitions().empty() )
	{
		_defects.push_back( state_machine_defect( *this,
			"Junction '%' has no outgoing transitions!", get_name() ) );
		check_ok = false;
	}
	else
	{
		Y_LOG( log_level::LL_SPAM, "Junction '%' has % outgoing transition(s).", get_name(),
			get_incoming_transitions().size() );
		Y_LOG( log_level::LL_SPAM, "Checking if junction '%' has more than one outgoing transition with no guard.",
			get_name() );
		sxy::uint8_t number_of_transitions_with_no_guards = 0;

		Y_FOR( const transition* const transition, get_outgoing_transitions() )
		{
			if( !transition->get_guard() )
			{
				++number_of_transitions_with_no_guards;
			}
		}

		if( number_of_transitions_with_no_guards > 1 )
		{
			_defects.push_back( state_machine_defect( *this,
				"Junction '%' has more than one outgoing transition with no guard! It has '%' transitions with no guards.",
				get_name(), number_of_transitions_with_no_guards ) );
			check_ok = false;
		}

		Y_LOG( log_level::LL_SPAM, "Junction '%' has % outgoing transition(s) with no guard.",	get_name(), 
			number_of_transitions_with_no_guards );
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !pseudostate_impl::check( _defects ) )
	{
		check_ok = false;
	}

	return( check_ok );
}


void junction_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void junction_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void junction_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


}
