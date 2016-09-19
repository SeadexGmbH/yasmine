//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_fork.h"

#include  <algorithm>

#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_pseudostate_visitor.h"
#include "t_transition.h"
#include "i_state.h"
#include "t_state_machine_defects.h"
#include "i_region.h"


namespace sxy
{


t_fork::t_fork
(
	const std::string& p_name
): t_region_pseudostate( p_name )
{
	// Nothing to do...
}
	

t_fork::~t_fork
(
) = default;


bool
t_fork::check
(
	t_state_machine_defects& p_defects
) const
{	
	auto l_check_ok = true;

	// 15.3.8 Pseudostate -> Constraint [5]: Fork must have at least 2 outgoing transitions and exactly 1 incoming transition.
	if( get_outgoing_transitions().size() < 2 )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Fork '%' has too few outgoing transitions! It has % transition(s).", get_name(), get_outgoing_transitions().size() ) );
		l_check_ok = false;
	}

	if( get_incoming_transitions().size() != 1 )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Fork '%' does not have exactly 1 incoming transition! It has % transition(s),", get_name(), get_outgoing_transitions().size() ) );
		l_check_ok = false;
	}			 

	// 15.3.8 Pseudostate -> Constraint [6]: All transitions outgoing a fork vertex must target states in different regions of an state.
	// This check is not mandatory. The last LCA is the state machine itself. -> Jira[104] / Jira[103]
	 
	// 15.3.14 Transition -> Constraint [1]: A fork segment must not have guards or triggers.	
	for( const auto& l_transition : get_outgoing_transitions() )
	{
		if( l_transition->get_guard() )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Outgoing transition '%' of fork '%' has guard!", l_transition->get_name(), get_name() ) );
			l_check_ok = false;
		}		
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !t_pseudostate::check( p_defects ) )
	{
		l_check_ok = false;
	}

	// 15.3.14 Transition -> Constraint [3]: A fork segment must always target a state.
	for( const auto& l_transition : get_outgoing_transitions() )
	{
		const auto target_vertex = dynamic_cast<const i_state* >( &l_transition->get_target() );
		if( !target_vertex )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Fork '%' has outgoing transition ('%') that hasn't a state as target! Target vertex is '%'.", get_name(), l_transition->get_name(), target_vertex->get_name() ) );
			l_check_ok = false;
		}
		else
		{
			target_vertex->check( p_defects );
		}
	}

	// 2 outgoing transitions cannot enter the same region
	std::set<const i_region*> l_target_regions;
	for( const auto l_transition : get_outgoing_transitions() )
	{
		auto l_target_region = l_transition->get_target().get_parent();
		const auto l_region = dynamic_cast< const i_region* >( l_target_region );
		if( l_region )
		{
			auto l_result = l_target_regions.insert( l_region );
			if( !l_result.second )
			{
				p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Fork '%' has outgoing transition(s) that has the same target region '%'.", get_name(), l_region->get_name() ) );
				l_check_ok = false;
				break;
			}
		}
	}

	auto l_transitions_kind = get_outgoing_transitions().front()->get_kind();
	for( const auto l_transition : get_outgoing_transitions() )
	{
		if(l_transitions_kind != l_transition->get_kind() )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Outgoing transitions of fork '%' have different kinds!", get_name() ) );
			l_check_ok = false;
			break;
		}
	}

	return( l_check_ok );
}


void
t_fork::accept_vertex_visitor
(
	i_const_vertex_visitor& p_visitor
)	const 
{
	p_visitor.visit( *this );
}


void
t_fork::accept_vertex_visitor
(
	i_vertex_visitor& p_visitor
)
{
	p_visitor.visit( *this );
}


void
t_fork::accept_pseudostate_visitor
(
	i_pseudostate_visitor& p_visitor
) const
{
	p_visitor.visit( *this );
}								 


void
t_fork::add_incoming_transition
(
	i_transition& p_incoming_transition
)
{			
	Y_ASSERT( t_vertex::get_incoming_transitions().size() < 1, "Fork cannot have more than 1 incoming transition!" );
	t_vertex::add_incoming_transition( p_incoming_transition );
}


}
