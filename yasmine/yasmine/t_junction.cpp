//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_junction.h"

#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_pseudostate_visitor.h"
#include "t_state_machine_defects.h"
#include "i_transition.h"


namespace sxy
{


t_junction::t_junction( const std::string& p_name )
	: t_region_pseudostate( p_name )
{
	// Nothing to do...
}


t_junction::~t_junction() = default;


bool t_junction::check( t_state_machine_defects& p_defects ) const
{
	auto l_check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [7]: A junction vertex must have at least one incoming and one outgoing
	// transition.
	Y_LOG( t_log_level::LL_SPAM, "Checking if junction '%' have incoming transition(s).", get_name() );
	if( get_incoming_transitions().empty() )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
			"Junction has too few incoming transitions!" ) );
		l_check_ok = false;
	}

	Y_LOG( t_log_level::LL_SPAM, "Junction '%' have % incoming transition(s).", get_name(),
		get_incoming_transitions().size() );
	Y_LOG( t_log_level::LL_SPAM, "Checking if junction '%' have outgoing transition(s).", get_name() );
	if( get_outgoing_transitions().empty() )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
			"Junction '%' has too few outgoing transitions! It has no transition.", get_name() ) );
		l_check_ok = false;
	}
	else
	{
		Y_LOG( t_log_level::LL_SPAM, "Junction '%' have % outgoing transition(s).", get_name(),
			get_incoming_transitions().size() );
		Y_LOG( t_log_level::LL_SPAM, "Checking if junction '%' have more then one outgoing transition with no guard.",
			get_name() );
		auto l_number_of_transitions_with_no_guards = 0;

		for( const auto l_transition : get_outgoing_transitions() )
		{
			if( !l_transition->get_guard() )
			{
				++l_number_of_transitions_with_no_guards;
			}
		}

		if( l_number_of_transitions_with_no_guards > 1 )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
				"Junction '%' has more then one outgoing transition with no guard! It has '%' transitions with no guards.",
				get_name(), l_number_of_transitions_with_no_guards ) );
			l_check_ok = false;
		}

		Y_LOG( t_log_level::LL_SPAM, "Junction '%' have % outgoing transition(s) with no guard.",	get_name(), 
			l_number_of_transitions_with_no_guards );
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !t_pseudostate::check( p_defects ) )
	{
		l_check_ok = false;
	}

	return( l_check_ok );
}


void t_junction::accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_junction::accept_vertex_visitor( i_vertex_visitor& p_visitor )
{
	p_visitor.visit( *this );
}


void t_junction::accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


}
