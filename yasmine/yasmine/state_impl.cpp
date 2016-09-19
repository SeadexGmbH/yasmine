//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_impl.h"

#include "base.h"
#include "region.h"
#include "exception.h"
#include "composite_state.h"
#include "behavior.h"
#include "log_and_throw.h"
#include "behavior_exception.h"


namespace sxy
{


state_impl::state_impl( const std::string& _name )
	: vertex_impl( _name ),
		was_active_( false ),
		parent_()
{
	// Nothing to do...
}


state_impl::~state_impl() = default;


const state_machine_element* state_impl::get_parent() const
{
	return( get_parent_region() );
}


void state_impl::set_parent_region( region* const _parent_region )
{
	parent_ = _parent_region;
}


region* state_impl::get_parent_region() const
{
	return( parent_ );
}


size_t state_impl::get_parent_region_index() const
{
	size_t index = 0;
	const auto parent_region = get_parent_region();
	if( parent_region )
	{
		const auto& parent_state = parent_region->get_parent_state();
		index = parent_state.get_region_index( parent_region );
	}

	return( index );
}


region* state_impl::get_region( const std::string& _region_name ) const
{
	Y_UNUSED_PARAMETER( _region_name );
	return( nullptr );
}


vertex* state_impl::get_pseudostate( const std::string& _name_of_pseudostate ) const
{
	Y_UNUSED_PARAMETER( _name_of_pseudostate );
	return( nullptr );
}


// Gets ancestors in ascending order (from child to parent) up to the given composite state.
raw_composite_states state_impl::get_ancestors( composite_state* const _final_ancestor ) const
{
	raw_composite_states ascending_path;
	if( get_parent_region() != nullptr )
	{
		const state* current_vertex = this;
		while( _final_ancestor != current_vertex )
		{
			const auto& parent_region = current_vertex->get_parent_region();
			if( parent_region != nullptr )
			{
				auto& parent_state = parent_region->get_parent_state();
				ascending_path.push_back( &parent_state );
				current_vertex = &parent_state;
			}
			else
			{
				Y_ASSERT( !_final_ancestor, "The given composite state '%' was not reached in the child-parent chain!" );
				break;
			}
		}
	}

	if( _final_ancestor )
	{
		ascending_path.push_back( _final_ancestor );
	}

	return( ascending_path );
}


raw_regions state_impl::get_ancestors_as_regions() const
{
	const state* source_state = this;
	raw_regions regions;
	while( true )
	{
		const auto& parent_region = source_state->get_parent_region();
		if( parent_region != nullptr )
		{
			regions.push_back( parent_region );
			const auto& previous_state = parent_region->get_parent_state();
			source_state = &previous_state;
		}
		else
		{
			break;
		}
	}

	return( regions );
}


std::size_t state_impl::get_nesting_level() const
{
	const auto ancestors = get_ancestors( nullptr );

	// Add one for the state itself.
	return( ancestors.size() + 1 );
}


void state_impl::set_was_active()
{
	was_active_ = true;
}


bool state_impl::was_active() const
{
	return( was_active_ );
}


void state_impl::set_active()
{
	auto parent_region = get_parent_region();
	parent_region->set_active_state( this );
	parent_region->set_state_was_active( this );
	Y_LOG( log_level::LL_DEBUG, "State '%' is now active.", get_name() );
}


void state_impl::set_inactive()
{
	auto parent_region = get_parent_region();
	parent_region->set_active_state( nullptr );
	set_was_active();
	Y_LOG( log_level::LL_DEBUG, "State '%' is now inactive.", get_name() );
}


bool state_impl::is_active() const
{
	bool is_active = false;
	const auto parent_region = get_parent_region();
	if( parent_region )
	{
		is_active = parent_region->get_active_state() == this;
	}
	else
	{
		is_active = true;
	}

	return( is_active );
}


bool state_impl::is_complete() const
{
	return( true );
}


void state_impl::execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler ) const
{
	Y_UNUSED_PARAMETER( _event );
	Y_UNUSED_PARAMETER( _async_event_handler );
}


void state_impl::execute_enter_behavior( const event& _event ) const
{
	const auto behavior = get_entry_behavior();
	if( behavior )
	{
		Y_LOG( sxy::log_level::LL_INFO, "Executing state '%' enter behavior.", get_name() );
		( *behavior )( _event );
	}
}


void state_impl::execute_exit_behavior( const event& _event ) const
{
	const auto behavior = get_exit_behavior();
	if( behavior )
	{
		Y_LOG( sxy::log_level::LL_INFO, "Executing state '%' exit behavior.", get_name().c_str() );
		( *behavior )( _event );
	}
}


void state_impl::enter_state( const event& _event )
{
	execute_enter_behavior( _event );
	set_active();
	set_was_active();
}


void state_impl::exit_state( const event& _event )
{
	execute_exit_behavior( _event );
	set_inactive();
}


bool state_impl::has_error_event() const
{
	return( false );
}


const behavior_exception* const state_impl::get_error_event() const
{
	return( nullptr );
}


}
