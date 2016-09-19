//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_state.h"

#include "base.h"
#include "i_region.h"
#include "t_exception.h"
#include "i_composite_state.h"
#include "i_behavior.h"
#include "t_log_and_throw.h"


namespace sxy
{


t_state::t_state( const std::string& p_name )
	: t_vertex( p_name ),
		m_was_active( false ),
		m_parent()
{
	// Nothing to do...
}


t_state::~t_state() = default;


const i_state_machine_element* t_state::get_parent() const
{
	return( get_parent_region() );
}


void t_state::set_parent_region( i_region* const p_parent_region )
{
	m_parent = p_parent_region;
}


i_region* t_state::get_parent_region() const
{
	return( m_parent );
}


size_t t_state::get_parent_region_index() const
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


i_region* t_state::get_region( const std::string& p_region_name ) const
{
	Y_UNUSED_PARAMETER( p_region_name );
	return( nullptr );
}


i_vertex* t_state::get_pseudostate( const std::string& p_name_of_pseudostate ) const
{
	Y_UNUSED_PARAMETER( p_name_of_pseudostate );
	return( nullptr );
}


// Gets ancestors in ascending order (from child to parent) up to the given composite state.
t_raw_composite_states t_state::get_ancestors( i_composite_state* const p_final_ancestor ) const
{
	t_raw_composite_states l_ascending_path;
	if( get_parent_region() != nullptr )
	{
		const i_state* l_current_vertex = this;
		while( p_final_ancestor != l_current_vertex )
		{
			const auto& l_parent_region = l_current_vertex->get_parent_region();
			if( l_parent_region != nullptr )
			{
				auto& l_parent_state = l_parent_region->get_parent_state();
				l_ascending_path.push_back( &l_parent_state );
				l_current_vertex = &l_parent_state;
			}
			else
			{
				Y_ASSERT( !p_final_ancestor, "The given composite state '%' was not reached in the child-parent chain!" );
				break;
			}
		}
	}

	if( p_final_ancestor )
	{
		l_ascending_path.push_back( p_final_ancestor );
	}

	return( l_ascending_path );
}


t_raw_regions t_state::get_ancestors_as_regions() const
{
	const i_state* source_state = this;
	t_raw_regions l_regions;
	while( true )
	{
		const auto& parent_region = source_state->get_parent_region();
		if( parent_region != nullptr )
		{
			l_regions.push_back( parent_region );
			const auto& previous_state = parent_region->get_parent_state();
			source_state = &previous_state;
		}
		else
		{
			break;
		}
	}

	return( l_regions );
}


std::size_t t_state::get_nesting_level() const
{
	const auto ancestors = get_ancestors( nullptr );

	// Add one for the state itself.
	return( ancestors.size() + 1 );
}


void t_state::set_was_active()
{
	m_was_active = true;
}


bool t_state::was_active() const
{
	return( m_was_active );
}


void t_state::set_active()
{
	auto parent_region = get_parent_region();
	parent_region->set_active_state( this );
	parent_region->set_state_was_active( this );
	Y_LOG( t_log_level::LL_DEBUG, "State '%' is now active.", get_name() );
}


void t_state::set_inactive()
{
	auto parent_region = get_parent_region();
	parent_region->set_active_state( nullptr );
	set_was_active();
	Y_LOG( t_log_level::LL_DEBUG, "State '%' is now inactive.", get_name() );
}


bool t_state::is_active() const
{
	bool l_is_active = false;
	const auto parent_region = get_parent_region();
	if( parent_region )
	{
		l_is_active = parent_region->get_active_state() == this;
	}
	else
	{
		l_is_active = true;
	}

	return( l_is_active );
}


bool t_state::is_complete() const
{
	return( true );
}


void t_state::execute_do_behavior( const i_event& p_event ) const
{
	Y_UNUSED_PARAMETER( p_event );
}


void t_state::execute_enter_behavior( const i_event& p_event ) const
{
	const auto behavior = get_entry_behavior();
	if( behavior )
	{
		Y_LOG( sxy::t_log_level::LL_INFO, "Executing state '%' enter behavior.", get_name() );
		( *behavior )( p_event );
	}
}


void t_state::execute_exit_behavior( const i_event& p_event ) const
{
	const auto behavior = get_exit_behavior();
	if( behavior )
	{
		Y_LOG( sxy::t_log_level::LL_INFO, "Executing state '%' exit behavior.", get_name().c_str() );
		( *behavior )( p_event );
	}
}


void t_state::enter_state( const i_event& p_event )
{
	execute_enter_behavior( p_event );
	set_active();
	set_was_active();
}


void t_state::exit_state( const i_event& p_event )
{
	execute_exit_behavior( p_event );
	set_inactive();
}


}
