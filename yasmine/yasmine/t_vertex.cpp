//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_vertex.h"

#include <algorithm>
#include <iostream>

#include "i_composite_state.h"
#include "i_region.h"
#include "i_transition.h"
#include "t_uri.h"
#include "log.h"
#include "i_event.h"


namespace sxy
{


t_vertex::t_vertex
(		
	const std::string& p_name
): t_state_machine_element(p_name),	
	 m_outgoing_transitions(),
	 m_incoming_transitions()	 
{
	// Nothing to do...
}


t_vertex::~t_vertex
(
) = default;


void
t_vertex::add_outgoing_transition
(
	i_transition& p_outgoing_transition
) 
{
	m_outgoing_transitions.push_back( &p_outgoing_transition);
}


void
t_vertex::add_incoming_transition
(
	i_transition& p_incoming_transition
)
{
	m_incoming_transitions.push_back( &p_incoming_transition );
}


void
t_vertex::remove_outgoing_transition
(
	const i_transition& p_outgoing_transition
)
{
	auto outgoing_transition = std::find( m_outgoing_transitions.begin(), m_outgoing_transitions.end(), &p_outgoing_transition );

	m_outgoing_transitions.erase( outgoing_transition );
}


void
t_vertex::remove_incoming_transition
(
	const i_transition& p_incoming_transition
)
{
	auto incoming_transition = std::find( m_incoming_transitions.begin(), m_incoming_transitions.end(), &p_incoming_transition );

	m_incoming_transitions.erase( incoming_transition );
}


const t_raw_transitions&
t_vertex::get_outgoing_transitions
(
) const
{
	return( m_outgoing_transitions );
}


const t_raw_transitions&
t_vertex::get_incoming_transitions
(
) const
{
	return( m_incoming_transitions );
}


t_uri
t_vertex::get_uri
(		
) const
{	
	t_uri l_uri( get_name() );	
	add_ancestor_uri( l_uri );
									 	
	return ( l_uri );
}


i_transition*
t_vertex::search_transition
(
	const i_event& p_event
) const
{
	const auto& transitions = get_outgoing_transitions();
	i_transition* found_transition = nullptr;

	for( const auto& transition : transitions )
	{																		 
		if( transition->can_accept_event( p_event.get_id() ) )
		{
			const auto is_checked = transition->check_guard( p_event );
			if( is_checked )
			{
				found_transition = transition ;
				break;
			}
		}
	}

	return( found_transition );
}


i_region*
t_vertex::LCA_region
(
	const i_vertex& p_rhs
) const
{	
	Y_LOG( t_log_level::LL_SPAM, "Start calculating LCA_region for '%' and '%'.", get_name(), p_rhs.get_name() );
	i_region* lca = nullptr;	

	const auto ancestors_of_lhs = get_ancestors_as_regions();
	const auto ancestors_of_rhs = p_rhs.get_ancestors_as_regions();

	Y_ASSERT( ancestors_of_lhs.size() >= 1 && ancestors_of_rhs.size() >= 1, "One of the ancestor region lists is empty!" );

	auto l_r_idx = ancestors_of_rhs.size() - 1;
	auto l_l_idx = ancestors_of_lhs.size() - 1;


	while( ancestors_of_rhs[ l_r_idx ] == ancestors_of_lhs[ l_l_idx ] )
	{
		lca = ancestors_of_lhs[ l_l_idx ];

		if( ( l_l_idx == 0 ) || ( l_r_idx == 0 ) )
		{
			break;
		}

		--l_r_idx;
		--l_l_idx;
	}

	Y_ASSERT( lca, "No LCA_region has been found!" );
	Y_LOG( t_log_level::LL_SPAM, "LCA_region found: '%'.", lca->get_name() );	

	return( lca );
}




i_composite_state*
t_vertex::LCA_composite_state
(
	const i_vertex& p_rhs
) const
{
	Y_LOG( t_log_level::LL_SPAM, "Start calculating LCA_composite_state for '%' and '%'.", get_name(), p_rhs.get_name() );
	i_composite_state* lca = nullptr;
	const auto ancestors_of_lhs = get_ancestors( nullptr );
	const auto ancestors_of_rhs = p_rhs.get_ancestors( nullptr );

	Y_ASSERT( ancestors_of_lhs.size() >= 1 && ancestors_of_rhs.size() >= 1, "One of the ancestor region lists is empty!" );

	auto l_r_idx = ancestors_of_rhs.size() - 1;
	auto l_l_idx = ancestors_of_lhs.size() - 1;

	while( ancestors_of_rhs[ l_r_idx ] == ancestors_of_lhs[ l_l_idx ] )
	{
		lca = ancestors_of_lhs[ l_l_idx ];

		if( ( l_l_idx == 0 ) || ( l_r_idx == 0 ) )
		{
			break;
		}

		--l_r_idx;
		--l_l_idx;
	}

	if( lca )
	{
		Y_LOG( t_log_level::LL_SPAM, "LCA_composite_state found: '%'.", lca->get_name() );
	}
	else
	{
		Y_LOG( t_log_level::LL_ERROR, "No LCA_composite_state has been found. LCA is nullptr." );
	}
	return( lca );
}


void
t_vertex::add_ancestor_uri
(
	t_uri& p_uri
)	const
{
	auto l_parent = get_parent();		

	while( l_parent )
	{
		p_uri.push_front( l_parent->get_name() );
		l_parent = l_parent->get_parent();
	}
}


}
