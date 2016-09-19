//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_composite_state.h"

#include <algorithm>

#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_state_visitor.h"
#include "i_complex_state_visitor.h"
#include "t_region.h"
#include "t_deep_history.h"
#include "t_shallow_history.h"
#include "t_exit_point.h"
#include "t_entry_point.h"
#include "i_behavior.h"
#include "t_state_machine_defects.h"
#include "t_uri.h"
#include "t_log_and_throw.h"


namespace sxy
{


t_composite_state::t_composite_state( const std::string& p_name, i_behavior_uptr p_entry_action, 
	i_behavior_uptr p_exit_action, const t_event_ids& p_deferred_events )
	: t_complex_state( p_name, std::move( p_entry_action ), std::move( p_exit_action ), p_deferred_events ),
		m_regions(),
		m_deep_history( nullptr ),
		m_shallow_history( nullptr ),
		m_entry_points(),
		m_exit_points()
{
	// Nothing to do...
}


t_composite_state::~t_composite_state() = default;


// cppcheck-suppress unusedFunction
i_region& t_composite_state::add_region( i_region_uptr p_region )
{
	p_region->set_parent_state( this );
	auto& new_region = *p_region;
	m_regions.push_back( std::move( p_region ) );
	return( new_region );
}


i_region& t_composite_state::add_region( const std::string& p_region_name )
{
	auto l_region = std::make_unique< sxy::t_region >( p_region_name );
	l_region->set_parent_state( this );
	auto& l_new_region = *l_region;
	m_regions.push_back( std::move( l_region ) );
	return( l_new_region );
}


const t_regions& t_composite_state::get_regions() const
{
	return( m_regions );
}


t_regions& t_composite_state::get_regions()
{
	return( m_regions );
}


// cppcheck-suppress unusedFunction
i_region* t_composite_state::get_region( const std::string& p_region_name ) const
{
	i_region* l_found_region = nullptr;

	for( const auto & l_region : get_regions() )
	{
		if( l_region->get_name() == p_region_name )
		{
			l_found_region = l_region.get();
			break;
		}
	}

	return( l_found_region );
}


bool t_composite_state::is_complete() const
{
	return( check_if_regions_are_completed() );
}


const i_deep_history* t_composite_state::get_deep_history() const
{
	return( m_deep_history.get() );
}


// cppcheck-suppress unusedFunction
i_deep_history& t_composite_state::add_deep_history( i_deep_history_uptr p_deep_history )
{
	if( m_deep_history )
	{
		LOG_AND_THROW( t_log_level::LL_FATAL, "There is already a deep history in the composite state '%'!", get_name() );
	}

	p_deep_history->set_parent_state( this );
	m_deep_history = std::move( p_deep_history );
	return( *m_deep_history );
}


i_deep_history& t_composite_state::add_deep_history( const std::string& p_deep_history_name )
{
	if( m_deep_history )
	{
		LOG_AND_THROW( t_log_level::LL_FATAL, "There is already a deep history in the composite state '%'!", get_name() );
	}

	auto l_deep_history = std::make_unique< sxy::t_deep_history >( p_deep_history_name );
	l_deep_history->set_parent_state( this );
	m_deep_history = std::move( l_deep_history );
	return( *m_deep_history );
}


i_shallow_history* t_composite_state::get_shallow_history() const
{
	return( m_shallow_history.get() );
}


// cppcheck-suppress unusedFunction
i_shallow_history& t_composite_state::add_shallow_history( i_shallow_history_uptr p_shallow_history )
{
	if( m_shallow_history )
	{
		LOG_AND_THROW( t_log_level::LL_FATAL, "There is already a shallow history in the composite state '%'!",	get_name() );
	}

	p_shallow_history->set_parent_state( this );
	m_shallow_history = std::move( p_shallow_history );
	return( *m_shallow_history );
}


i_shallow_history& t_composite_state::add_shallow_history( const std::string& p_shallow_history_name )
{
	if( m_shallow_history )
	{
		LOG_AND_THROW( t_log_level::LL_FATAL, "There is already a shallow history in the composite state '%'!",
			get_name() );
	}

	auto l_shallow_history = std::make_unique< sxy::t_shallow_history >( p_shallow_history_name );
	l_shallow_history->set_parent_state( this );
	m_shallow_history = std::move( l_shallow_history );
	return( *m_shallow_history );
}


const t_raw_const_entry_points t_composite_state::get_entry_points() const
{
	t_raw_const_entry_points l_entry_points = {};

	for( const auto & l_entry_point : m_entry_points )
	{
		l_entry_points.push_back( l_entry_point.get() );
	}

	return( l_entry_points );
}


// cppcheck-suppress unusedFunction
i_entry_point& t_composite_state::add_entry_point( i_entry_point_uptr p_entry_point )
{
	p_entry_point->set_parent_state( this );
	m_entry_points.push_back( std::move( p_entry_point ) );
	return( *m_entry_points.back() );
}


i_entry_point& t_composite_state::add_entry_point( const std::string& p_entry_point_name )
{
	auto l_entry_point = std::make_unique< sxy::t_entry_point >( p_entry_point_name );
	l_entry_point->set_parent_state( this );
	m_entry_points.push_back( std::move( l_entry_point ) );
	return( *m_entry_points.back() );
}


const t_raw_const_exit_points t_composite_state::get_exit_points() const
{
	t_raw_const_exit_points l_exit_points = {};

	for( const auto & l_exit_point : m_exit_points )
	{
		l_exit_points.push_back( l_exit_point.get() );
	}

	return( l_exit_points );
}


// cppcheck-suppress unusedFunction
i_exit_point& t_composite_state::add_exit_point( i_exit_point_uptr p_exit_point )
{
	p_exit_point->set_parent_state( this );
	m_exit_points.push_back( std::move( p_exit_point ) );
	return( *m_exit_points.back() );
}


i_exit_point& t_composite_state::add_exit_point( const std::string& p_exit_point_name )
{
	auto l_exit_point = std::make_unique< sxy::t_exit_point >( p_exit_point_name );
	l_exit_point->set_parent_state( this );
	m_exit_points.push_back( std::move( l_exit_point ) );
	return( *m_exit_points.back() );
}


// cppcheck-suppress unusedFunction
i_vertex* t_composite_state::get_pseudostate( const std::string& p_name_of_pseudostate ) const
{
	i_vertex* l_found_vertex = nullptr;
	if( m_deep_history && ( m_deep_history->get_name() == p_name_of_pseudostate ) )
	{
		l_found_vertex = m_deep_history.get();
	}
	else
	if( m_shallow_history && ( m_shallow_history->get_name() == p_name_of_pseudostate ) )
	{
		l_found_vertex = m_shallow_history.get();
	}
	else
	{
		for( auto & l_entry_point : m_entry_points )
		{
			if( l_entry_point->get_name() == p_name_of_pseudostate )
			{
				l_found_vertex = l_entry_point.get();
				break;
			}
		}

		if( !l_found_vertex )
		{
			for( auto & l_exit_point : m_exit_points )
			{
				if( l_exit_point->get_name() == p_name_of_pseudostate )
				{
					l_found_vertex = l_exit_point.get();
					break;
				}
			}
		}
	}

	return( l_found_vertex );
}


size_t t_composite_state::get_region_index( const i_region* const p_region ) const
{
	auto l_element =
		std::find_if( m_regions.begin(), m_regions.end(), [ p_region ] ( const i_region_uptr& p_vector_element_region )
		{
			return( p_region == p_vector_element_region.get() );
		}
			);
	const auto l_index = l_element - m_regions.begin();
	return( l_index );
}


size_t t_composite_state::get_parent_region_index() const
{
	size_t l_index = 0;
	const auto l_parent_region = get_parent_region();
	if( l_parent_region )
	{
		const auto& l_parent_state = l_parent_region->get_parent_state();
		l_index = l_parent_state.get_region_index( l_parent_region );
	}

	return( l_index );
}


bool t_composite_state::check( t_state_machine_defects& p_defects ) const
{
	auto l_check_ok = true;

	// 15.3.11 State -> Constraint [5]: A composite state is a state with at least one region.
	if( get_regions().empty() )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this, "Composite state '%' has no regions!",
				get_name() ) );
		l_check_ok = false;
	}

	// 15.3.11 State -> Constraint [5]: An orthogonal state is a composite state with at least 2 regions.
	// Not reason to check this. We don't care.
	for( const auto & region : get_regions() )
	{
		if( !region->check( p_defects ) )
		{
			l_check_ok = false;
		}
	}

	for( const auto l_entry_point : get_entry_points() )
	{
		if( !l_entry_point->check( p_defects ) )
		{
			l_check_ok = false;
		}
	}

	for( const auto l_exit_point : get_exit_points() )
	{
		if( !l_exit_point->check( p_defects ) )
		{
			l_check_ok = false;
		}
	}

	const auto l_deep_history = get_deep_history();
	if( l_deep_history )
	{
		if( !l_deep_history->check( p_defects ) )
		{
			l_check_ok = false;
		}
	}

	const auto l_shallow_history = get_shallow_history();
	if( l_shallow_history )
	{
		if( !l_shallow_history->check( p_defects ) )
		{
			l_check_ok = false;
		}
	}

	// a state cannot defer an event that triggers a transition
	if( t_complex_state::check_if_one_of_the_deferred_events_triggers_a_transition() )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
				"Simple state '%' defer event that triggers a outgoing transition!", get_name() ) );
		l_check_ok = false;
	}

	return( l_check_ok );
}


void t_composite_state::accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_composite_state::accept_vertex_visitor( i_vertex_visitor& p_visitor )
{
	p_visitor.visit( *this );
}


void t_composite_state::accept_complex_state_visitor( i_complex_state_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


// cppcheck-suppress unusedFunction
void t_composite_state::accept_state_visitor( i_state_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


bool t_composite_state::is_orthogonal() const
{
	auto l_is_orthogonal = false;
	const auto& l_regions = get_regions();
	if( l_regions.size() > 1 )
	{
		l_is_orthogonal = true;
	}

	return( l_is_orthogonal );
}


bool t_composite_state::check_if_regions_are_completed() const
{
	auto l_regions_are_completed = true;
	const auto& l_regions = get_regions();

	for( const auto & region : l_regions )
	{
		if( !region->is_active_state_final() )
		{
			l_regions_are_completed = false;
			Y_LOG( t_log_level::LL_SPAM, "Region '%' is not completed.", region->get_name() );
			break;
		}

		Y_LOG( t_log_level::LL_SPAM, "Region '%' is completed.", region->get_name() );
	}

	return( l_regions_are_completed );
}


}
