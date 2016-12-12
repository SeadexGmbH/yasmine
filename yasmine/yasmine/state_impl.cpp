//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_impl.hpp"

#include <algorithm>

#include "base.hpp"
#include "region.hpp"
#include "exception.hpp"
#include "composite_state.hpp"
#include "behavior.hpp"
#include "log_and_throw.hpp"
#include "behavior_exception.hpp"
#include "algorithm_parameters.hpp"


#include <iostream>


namespace sxy
{


state_impl::state_impl( const std::string& _name )
	: vertex_impl( _name ),
		was_active_( false ),
		parent_()
#ifdef Y_OPTIMIZE_4_SPEED
		, ancestors_(),
			ancestors_as_regions_()
#endif 												
{
#ifdef Y_OPTIMIZE_4_SPEED
	ancestors_as_regions_.reserve( ANCESTORS_VECTOR_SIZE );
	ancestors_.reserve( ANCESTORS_VECTOR_SIZE );
#endif	
}


state_impl::~state_impl() Y_NOEXCEPT
{
	// Nothing to do...
}


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
	const region* const parent_region = get_parent_region();
	if( parent_region )
	{
		const composite_state& parent_state = parent_region->get_parent_state();
		index = parent_state.get_region_index( parent_region );
	}

	return( index );
}


region* state_impl::get_region( const std::string& _region_name ) const
{
	Y_UNUSED_PARAMETER( _region_name );
	return( Y_NULLPTR );
}


vertex* state_impl::get_pseudostate( const std::string& _name_of_pseudostate ) const
{
	Y_UNUSED_PARAMETER( _name_of_pseudostate );
	return( Y_NULLPTR );
}


// Gets ancestors in ascending order (from child to parent) up to the given composite state.
raw_composite_states state_impl::get_ancestors( composite_state* const _final_ancestor ) const
{
#ifdef Y_OPTIMIZE_4_SPEED
	if( ancestors_.empty() )
	{
		collect_ancestors( ancestors_, Y_NULLPTR );
	}

	if( _final_ancestor == Y_NULLPTR )
	{
		return( ancestors_ );
	}
	else
	{
		const raw_composite_states::iterator final_ancestor = 
			std::find( ancestors_.begin(), ancestors_.end(), _final_ancestor );

		if( final_ancestor != ancestors_.end() )
		{
			raw_composite_states ancestors( ancestors_.begin(), final_ancestor + 1 );
			return( ancestors );
		}
		else
		{
			raw_composite_states ancestors;
			return( ancestors );
		}
	}
#else	
	raw_composite_states ancestors;
	collect_ancestors( ancestors, _final_ancestor );
	return( ancestors );
#endif
}


raw_regions state_impl::get_ancestors_as_regions() const
{																	 	
#ifdef Y_OPTIMIZE_4_SPEED
	if( ancestors_as_regions_.empty() )
	{
		collect_ancestors_as_regions( ancestors_as_regions_ );
	}
	return ( ancestors_as_regions_ );
#else
	 raw_regions ancestors_as_regions;
	 collect_ancestors_as_regions( ancestors_as_regions );
	 return( ancestors_as_regions );
#endif
}


std::size_t state_impl::get_nesting_level() const
{
	const raw_composite_states& ancestors = get_ancestors( Y_NULLPTR );

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
	region* const parent_region = get_parent_region();
	parent_region->set_active_state( this );
	parent_region->set_state_was_active( this );
	Y_LOG( log_level::LL_DEBUG, "State '%' is now active.", get_uri().to_string() );
}


void state_impl::set_inactive()
{
	region* const parent_region = get_parent_region();
	parent_region->set_active_state( Y_NULLPTR );
	set_was_active();
	Y_LOG( log_level::LL_DEBUG, "State '%' is now inactive.", get_uri().to_string() );
}


bool state_impl::is_active() const
{
	bool is_active = false;
	const region* const parent_region = get_parent_region();
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
	const behavior* const behavior = get_entry_behavior();
	if( behavior )
	{
		Y_LOG( sxy::log_level::LL_TRACE, "Executing state's '%' enter behavior.", get_name() );
		( *behavior )( _event );
	}
}


void state_impl::execute_exit_behavior( const event& _event ) const
{
	const behavior* const behavior = get_exit_behavior();
	if( behavior )
	{
		Y_LOG( sxy::log_level::LL_TRACE, "Executing state's '%' exit behavior.", get_name() );
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


event_sptr state_impl::get_error_event() const
{
	return( event_sptr() );
}


void state_impl::collect_ancestors( raw_composite_states& _ancestors, composite_state* const _final_ancestor ) const
{
	if( get_parent_region() != Y_NULLPTR )
	{
		const state* current_vertex = this;
		while( _final_ancestor != current_vertex )
		{
			region* const parent_region = current_vertex->get_parent_region();
			if( parent_region != Y_NULLPTR )
			{
				composite_state& parent_state = parent_region->get_parent_state();
				_ancestors.push_back( &parent_state );
				current_vertex = &parent_state;
			}
			else
			{
				Y_ASSERT( !_final_ancestor, "The given composite state '%' was not reached in the child-parent chain!" );
				break;
			}
		}
	}
}


void state_impl::collect_ancestors_as_regions( raw_regions& _ancestors_as_regions ) const
{
	const state* source_state = this;
	while( true )
	{
		region* const parent_region = source_state->get_parent_region();
		if( parent_region != Y_NULLPTR )
		{
			_ancestors_as_regions.push_back( parent_region );
			const composite_state& previous_state = parent_region->get_parent_state();
			source_state = &previous_state;
		}
		else
		{
			break;
		}
	}
}


}
