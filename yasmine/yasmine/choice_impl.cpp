//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "choice_impl.h"

#include "const_vertex_visitor.h"
#include "vertex_visitor.h"
#include "pseudostate_visitor.h"
#include "state_machine_defect.h"
#include "region.h"
#include "transition.h"


namespace sxy
{


choice_impl::choice_impl( const std::string& _name )
	: region_pseudostate_impl( _name )
{
	// Nothing to do...
}


choice_impl::~choice_impl() = default;


bool choice_impl::check( state_machine_defects& _defects ) const
{
	auto check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [8]: Choice must have at least 1 incoming and 1 outgoing transition.
	Y_LOG( log_level::LL_SPAM, "Checking if choice '%' have incoming transition(s).", get_name() );
	if( get_incoming_transitions().empty() )
	{
		_defects.push_back( std::make_unique< state_machine_defect >( *this, "Choice '%' has no incoming transitions!",
				get_name() ) );
		check_ok = false;
	}

	Y_LOG( log_level::LL_SPAM, "Choice '%' have % incoming transition(s).", get_name(),
		get_incoming_transitions().size() );
	Y_LOG( log_level::LL_SPAM, "Checking if choice '%' have outgoing transition(s).", get_name() );
	if( get_outgoing_transitions().empty() )
	{
		_defects.push_back( std::make_unique< state_machine_defect >( *this, "Choice '%' has no outgoing transitions!",
				get_name() ) );
		check_ok = false;
	}
	else
	{
		Y_LOG( log_level::LL_SPAM, "Choice '%' have % outgoing transition(s).", get_name(),
			get_outgoing_transitions().size() );
		Y_LOG( log_level::LL_SPAM, "Checking if choice '%' have more then one outgoing transition with no guard.",
			get_name() );
		auto number_of_transitions_with_no_guard = 0;

		for( const auto transition : get_outgoing_transitions() )
		{
			if( !transition->get_guard() )
			{
				++number_of_transitions_with_no_guard;
			}
		}

		if( number_of_transitions_with_no_guard > 1 )
		{
			_defects.push_back( std::make_unique< state_machine_defect >( *this,
					"Choice '%' has more then one outgoing transition with no guard! It has % transitions with no guard.",
					get_name(), number_of_transitions_with_no_guard ) );
			check_ok = false;
		}

		Y_LOG( log_level::LL_SPAM, "Choice '%' have % outgoing transition(s) with no guard.",
			get_name(), number_of_transitions_with_no_guard );
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !pseudostate_impl::check( _defects ) )
	{
		check_ok = false;
	}

	return( check_ok );
}


void choice_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void choice_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


// cppcheck-suppress unusedFunction
void choice_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


}
