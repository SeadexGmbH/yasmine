//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "choice_impl.hpp"

#include "hermes/log.hpp"

#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "pseudostate_visitor.hpp"
#include "state_machine_defect.hpp"
#include "region.hpp"
#include "transition.hpp"


namespace sxy
{


choice_impl::choice_impl( const std::string& _name )
	: region_pseudostate_impl( _name )
{
	// Nothing to do...
}


choice_impl::~choice_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


bool choice_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [8]: Choice must have at least 1 incoming and 1 outgoing transition.
	SX_LOG( hermes::log_level::LL_SPAM, "Checking if choice '%' has incoming transition(s).", get_name() );
	if( get_incoming_transitions().empty() )
	{
		_defects.push_back( state_machine_defect( *this, "Choice '%' has no incoming transitions!",
			get_name() ) );
		check_ok = false;
	}

	SX_LOG( hermes::log_level::LL_SPAM, "Choice '%' has % incoming transition(s).", get_name(),
		get_incoming_transitions().size() );		
	SX_LOG( hermes::log_level::LL_SPAM, "Checking if choice '%' has outgoing transition(s).", get_name() );
	if( get_outgoing_transitions().empty() )
	{
		_defects.push_back( state_machine_defect( *this, "Choice '%' has no outgoing transitions!",
				get_name() ) );
		check_ok = false;
	}
	else
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Choice '%' has % outgoing transition(s).", get_name(),
			get_outgoing_transitions().size() );
		SX_LOG( hermes::log_level::LL_SPAM, "Checking if choice '%' has more than one outgoing transition with no guard.",
			get_name() );
		sxe::uint8_t number_of_transitions_with_no_guard = 0;

		SX_FOR( const transition* const transition, get_outgoing_transitions() )
		{
			if( !transition->get_guard() )
			{
				++number_of_transitions_with_no_guard;
			}
		}

		if( number_of_transitions_with_no_guard > 1 )
		{
			_defects.push_back( state_machine_defect( *this,
					"Choice '%' has more than one outgoing transition with no guard! It has % transitions with no guard.",
					get_name(), number_of_transitions_with_no_guard ) );
			check_ok = false;
		}

		SX_LOG( hermes::log_level::LL_SPAM, "Choice '%' has % outgoing transition(s) with no guard.",
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


void choice_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


}
