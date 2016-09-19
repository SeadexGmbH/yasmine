//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "junction_impl.h"

#include "const_vertex_visitor.h"
#include "vertex_visitor.h"
#include "pseudostate_visitor.h"
#include "state_machine_defect.h"
#include "transition.h"


namespace sxy
{


junction_impl::junction_impl( const std::string& _name )
	: region_pseudostate_impl( _name )
{
	// Nothing to do...
}


junction_impl::~junction_impl() = default;


bool junction_impl::check( state_machine_defects& _defects ) const
{
	auto check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [7]: A junction vertex must have at least one incoming and one outgoing
	// transition.
	Y_LOG( log_level::LL_SPAM, "Checking if junction '%' have incoming transition(s).", get_name() );
	if( get_incoming_transitions().empty() )
	{
		_defects.push_back( std::make_unique< state_machine_defect >( *this,
			"Junction has too few incoming transitions!" ) );
		check_ok = false;
	}

	Y_LOG( log_level::LL_SPAM, "Junction '%' have % incoming transition(s).", get_name(),
		get_incoming_transitions().size() );
	Y_LOG( log_level::LL_SPAM, "Checking if junction '%' have outgoing transition(s).", get_name() );
	if( get_outgoing_transitions().empty() )
	{
		_defects.push_back( std::make_unique< state_machine_defect >( *this,
			"Junction '%' has too few outgoing transitions! It has no transition.", get_name() ) );
		check_ok = false;
	}
	else
	{
		Y_LOG( log_level::LL_SPAM, "Junction '%' have % outgoing transition(s).", get_name(),
			get_incoming_transitions().size() );
		Y_LOG( log_level::LL_SPAM, "Checking if junction '%' have more then one outgoing transition with no guard.",
			get_name() );
		auto number_of_transitions_with_no_guards = 0;

		for( const auto transition : get_outgoing_transitions() )
		{
			if( !transition->get_guard() )
			{
				++number_of_transitions_with_no_guards;
			}
		}

		if( number_of_transitions_with_no_guards > 1 )
		{
			_defects.push_back( std::make_unique< state_machine_defect >( *this,
				"Junction '%' has more then one outgoing transition with no guard! It has '%' transitions with no guards.",
				get_name(), number_of_transitions_with_no_guards ) );
			check_ok = false;
		}

		Y_LOG( log_level::LL_SPAM, "Junction '%' have % outgoing transition(s) with no guard.",	get_name(), 
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
