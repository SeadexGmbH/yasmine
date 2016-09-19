//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_transition.h"

#include <algorithm>

#include "base.h"
#include "i_vertex.h"
#include "i_behavior.h"
#include "i_constraint.h"
#include "i_event.h"
#include "t_uri.h"
#include "t_state_machine_defects.h"
#include "i_region.h"
#include "i_state.h"
#include "i_pseudostate.h"
#include "i_composite_state.h"


namespace sxy
{


// cppcheck-suppress uninitMemberVar
t_transition::t_transition( const t_event_id p_event_id, i_vertex& p_source, i_vertex& p_target, 
	const sxy::t_transition_kind p_kind, const std::string& p_name,	i_constraint_uptr p_guard, 
	i_behavior_uptr p_behavior )
	: t_transition( t_event_ids {   p_event_id  }, p_source, p_target, p_kind, p_name, std::move( p_guard ), 
										std::move( p_behavior ) ) 
{
	// Nothing to do...
}


t_transition::t_transition( const t_event_ids p_event_ids, i_vertex& p_source, i_vertex& p_target, 
	const sxy::t_transition_kind p_kind, const std::string& p_name,	i_constraint_uptr p_guard, 
	i_behavior_uptr p_behavior )
	: t_state_machine_element( p_name ),
		m_events( p_event_ids ),
		m_source( p_source ),
		m_target( p_target ),
		m_guard( std::move( p_guard ) ),
		m_behavior( std::move( p_behavior ) ),
		m_kind( p_kind )
{
	m_source.add_outgoing_transition( *this );
	m_target.add_incoming_transition( *this );
}


t_transition::~t_transition()
{
	m_source.remove_outgoing_transition( *this );
	m_target.remove_incoming_transition( *this );
}


const i_vertex& t_transition::get_source() const
{
	return( m_source );
}


const i_vertex& t_transition::get_target() const
{
	return( m_target );
}


i_vertex& t_transition::get_target()
{
	return( m_target );
}


const i_constraint* t_transition::get_guard() const
{
	return( m_guard.get() );
}


const i_behavior* t_transition::get_behavior() const
{
	return( m_behavior.get() );
}


t_uri t_transition::get_uri() const
{
	t_uri l_uri( get_name() );
	add_ancestor_uri( l_uri );
	return( l_uri );
}


sxy::t_transition_kind t_transition::get_kind() const
{
	return( m_kind );
}


void t_transition::add_ancestor_uri( t_uri& p_uri ) const
{
	Y_UNUSED_PARAMETER( p_uri );

	// Nothing to do...
}


void t_transition::on_transition_behavior( const i_event& p_event ) const
{
	Y_LOG( sxy::t_log_level::LL_INFO, "Executing transition '%' from '%' to '%'.", get_name().c_str(),
		get_source().get_name(), get_target().get_name() );
	auto behavior = get_behavior();
	if( behavior != nullptr )
	{
		( *behavior )( p_event );
	}

	Y_LOG( sxy::t_log_level::LL_INFO, "Executed transition '%' from '%' to '%'.", get_name().c_str(),
		get_source().get_name(), get_target().get_name() );
}


bool t_transition::check_guard( const i_event& p_event ) const
{
	auto is_checked = true;
	if( m_guard != nullptr )
	{
		is_checked = ( *m_guard )( p_event );
	}

	return( is_checked );
}


bool t_transition::check( t_state_machine_defects& p_defects ) const
{
	Y_UNUSED_PARAMETER( p_defects );
	auto l_check_ok = true;
	const auto& l_source = get_source();
	auto l_source_ancestors = l_source.get_ancestors_as_regions();
	const auto& l_target = get_target();
	auto l_target_ancestors = l_target.get_ancestors_as_regions();
	const auto l_lca_of_source_target = l_source.LCA_region( l_target );
	auto found_source_itr = std::find( l_source_ancestors.begin(), l_source_ancestors.end(), l_lca_of_source_target );
	if( found_source_itr != l_source_ancestors.begin() )
	{
		--found_source_itr;
	}

	auto found_target_itr = std::find( l_target_ancestors.begin(), l_target_ancestors.end(), l_lca_of_source_target );
	if( found_target_itr != l_target_ancestors.begin() )
	{
		--found_target_itr;
	}

	if( ( ( **found_source_itr ).get_uri().to_string() == l_lca_of_source_target->get_uri().to_string() ) ||
			( ( **found_target_itr ).get_uri().to_string() == l_lca_of_source_target->get_uri().to_string() ) )
	{
	}
	else
	if( ( **found_source_itr ).get_uri().to_string() != ( **found_target_itr ).get_uri().to_string() )
	{
		auto& l_source_composite_state = ( **found_source_itr ).get_parent_state();
		auto& l_target_composite_state = ( **found_target_itr ).get_parent_state();
		if( l_source_composite_state.get_uri().to_string() == l_target_composite_state.get_uri().to_string() )
		{
			const std::string l_message =
				"Transition '%' has source ('%') and target ('%') in different regions of the same composite state.";
			p_defects.push_back( std::make_unique< t_state_machine_defect >( *this, l_message, get_name(),
					l_source.get_name(), l_target.get_name() ) );
			l_check_ok = false;
		}
	}

	if( sxy::t_transition_kind::INTERNAL == get_kind() )
	{
		const auto l_source_state = dynamic_cast< const i_state* >( &get_source() );
		if( l_source_state )
		{
			if( get_source().get_uri().to_string() != get_target().get_uri().to_string() )
			{
				const std::string l_message =
					"Transition '%' has '%' kind, but it has different states as source and target! (source= '%', target = '%').";
				p_defects.push_back( std::make_unique< t_state_machine_defect >( *this, l_message, get_name(),
						to_string( get_kind() ), m_source.get_name(), m_target.get_name() ) );
				l_check_ok = false;
			}
		}
		else
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
					"Source '%' of transition '%' (kind: '%') is not a state!", get_source().get_name(), get_name(),
					to_string( get_kind() ) ) );
			l_check_ok = false;
		}
	}

	// Transition that enters a pseudostate cannot have a transition kind (it must be EXTERNAL).
	if( dynamic_cast< const i_pseudostate* >( &get_target() ) )
	{
		if( get_kind() != t_transition_kind::EXTERNAL )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
					"Transition '%' enters pseudostate '%' but have '%' kind! It is not possible!", get_name(),
					get_target().get_name(), to_string( get_kind() ) ) );
			l_check_ok = false;
		}
	}

	if( t_transition_kind::LOCAL == get_kind() )
	{
		if( !check_if_source_and_target_are_in_ancestor_relationship( get_source(), get_target() ) )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
					"Transition's '%' source '%' and target '%' are not in a ancestor relationship!", get_name(),
					get_source().get_name(), get_target().get_name() ) );
			l_check_ok = false;
		}
	}

	return( l_check_ok );
}


bool t_transition::can_accept_event( const t_event_id p_event ) const
{
	bool l_accept = false;
	if( std::find( m_events.begin(), m_events.end(), p_event ) != m_events.end() )
	{
		l_accept = true;
	}

	return( l_accept );
}


bool t_transition::check_if_source_and_target_are_in_ancestor_relationship(	const i_vertex& p_source,	
	const i_vertex& p_target )
{
	auto l_are_in_ancestor_relationship = false;
	auto l_target_as_composite_state = dynamic_cast< const i_composite_state* >( &p_target );
	if( l_target_as_composite_state )
	{
		l_are_in_ancestor_relationship = check_relationship( p_source, l_target_as_composite_state );
	}

	if( !l_are_in_ancestor_relationship )
	{
		auto l_source_as_composite_state = dynamic_cast< const i_composite_state* >( &p_source );
		if( l_source_as_composite_state )
		{
			l_are_in_ancestor_relationship = check_relationship( p_target, l_source_as_composite_state );
		}
	}

	return( l_are_in_ancestor_relationship );
}



bool t_transition::check_relationship( const i_vertex& p_lhs, const i_composite_state* p_rhs )
{
	auto l_are_in_relationship = false;
	const auto l_lhs_ancestors = p_lhs.get_ancestors( nullptr );

	for( const auto l_ancestor : l_lhs_ancestors )
	{
		if( l_ancestor == p_rhs )
		{
			l_are_in_relationship = true;
			break;
		}
	}

	return( l_are_in_relationship );
}


}
