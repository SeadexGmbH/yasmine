//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "composite_state_impl.hpp"

#include <algorithm>

#include "essentials/uri.hpp"
#include "hermes/log_and_throw.hpp"

#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "state_visitor.hpp"
#include "complex_state_visitor.hpp"
#include "region_impl.hpp"
#include "deep_history_impl.hpp"
#include "shallow_history_impl.hpp"
#include "exit_point_impl.hpp"
#include "entry_point_impl.hpp"
#include "behavior.hpp"
#include "state_machine_defect.hpp"


namespace sxy
{


composite_state_impl::composite_state_impl( const std::string& _name, behavior_uptr _entry_action, 
	behavior_uptr _exit_action, const event_ids& _deferred_events )
	: complex_state_impl( _name, sxe::move( _entry_action ), sxe::move( _exit_action ), _deferred_events ),
		regions_(),
		deep_history_(deep_history_uptr()),
		shallow_history_(shallow_history_uptr()),
		entry_points_(),
		exit_points_()
{
	// Nothing to do...
}


composite_state_impl::~composite_state_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


region& composite_state_impl::add_region( region_uptr _region )
{
	_region->set_parent_state( this );
	region& new_region = *_region;
	regions_.push_back( sxe::move( _region ) );
	SX_LOG( hermes::log_level::LL_TRACE, "Region '%' was added to composite state'%'.", _region->get_name(), get_name() );
	return( new_region );
}


region& composite_state_impl::add_region( const std::string& _region_name )
{
	sxe::SX_UNIQUE_PTR< sxy::region_impl > region = SX_MAKE_UNIQUE< sxy::region_impl >( _region_name );
	region->set_parent_state( this );
	region_impl& new_region = *region;
	regions_.push_back( sxe::move( region ) );
	SX_LOG( hermes::log_level::LL_TRACE, "Region '%' was added to composite state'%'.", _region_name, get_name() );
	return( new_region );
}


const regions& composite_state_impl::get_regions() const
{
	return( regions_ );
}


regions& composite_state_impl::get_regions()
{
	return( regions_ );
}


region* composite_state_impl::get_region( const std::string& _region_name ) const
{
	region* found_region = SX_NULLPTR;

	SX_FOR( const region_uptr& region, get_regions() )
	{
		if( region->get_name() == _region_name )
		{
			found_region = region.get();
			break;
		}
	}

	return( found_region );
}


bool composite_state_impl::is_complete() const
{
	return( check_if_regions_are_completed() );
}


const deep_history* composite_state_impl::get_deep_history() const
{
	return( deep_history_.get() );
}


deep_history& composite_state_impl::add_deep_history( deep_history_uptr _deep_history )
{
	if( deep_history_ )
	{
		LOG_AND_THROW( hermes::log_level::LL_FATAL, "There already is a deep history in the composite state '%'!", get_name() );
	}

	_deep_history->set_parent_state( this );
	deep_history_ = sxe::move( _deep_history );
	SX_LOG( hermes::log_level::LL_TRACE, "Deep history '%' was added to composite state'%'.", _deep_history->get_name(),
		get_name() );
	return( *deep_history_ );
}


deep_history& composite_state_impl::add_deep_history( const std::string& _deep_history_name )
{
	if( deep_history_ )
	{
		LOG_AND_THROW( hermes::log_level::LL_FATAL, "There is already a deep history in the composite state '%'!", get_name() );
	}

	sxe::SX_UNIQUE_PTR< sxy::deep_history_impl > deep_history =
		SX_MAKE_UNIQUE< sxy::deep_history_impl >( _deep_history_name );
	deep_history->set_parent_state( this );
	deep_history_ = sxe::move( deep_history );
	SX_LOG( hermes::log_level::LL_TRACE, "Deep history '%' was added to composite state'%'.", _deep_history_name, get_name() );
	return( *deep_history_ );
}


shallow_history* composite_state_impl::get_shallow_history() const
{
	return( shallow_history_.get() );
}


shallow_history& composite_state_impl::add_shallow_history( shallow_history_uptr _shallow_history )
{
	if( shallow_history_ )
	{
		LOG_AND_THROW( hermes::log_level::LL_FATAL, "There is already a shallow history in the composite state '%'!",	get_name() );
	}

	_shallow_history->set_parent_state( this );
	shallow_history_ = sxe::move( _shallow_history );
	SX_LOG( hermes::log_level::LL_TRACE, "Shallow history '%' was added to composite state'%'.", _shallow_history->get_name(),
		get_name() );
	return( *shallow_history_ );
}


shallow_history& composite_state_impl::add_shallow_history( const std::string& _shallow_history_name )
{
	if( shallow_history_ )
	{
		LOG_AND_THROW( hermes::log_level::LL_FATAL, "There is already a shallow history in the composite state '%'!",
			get_name() );
	}

	sxe::SX_UNIQUE_PTR< sxy::shallow_history_impl > shallow_history =
		SX_MAKE_UNIQUE< sxy::shallow_history_impl >( _shallow_history_name );
	shallow_history->set_parent_state( this );
	shallow_history_ = sxe::move( shallow_history );
	SX_LOG( hermes::log_level::LL_TRACE, "Shallow history '%' was added to composite state'%'.", _shallow_history_name,
		get_name() );
	return( *shallow_history_ );
}


const raw_const_entry_points composite_state_impl::get_entry_points() const
{
	raw_const_entry_points entry_points;
	entry_points.reserve( entry_points_.size() );

	SX_FOR( const entry_point_uptr& entry_point, entry_points_ )
	{
		entry_points.push_back( entry_point.get() );
	}

	return( entry_points );
}


entry_point& composite_state_impl::add_entry_point( entry_point_uptr _entry_point )
{
	_entry_point->set_parent_state( this );
	entry_points_.push_back( sxe::move( _entry_point ) );
	SX_LOG( hermes::log_level::LL_TRACE, "Entry point '%' was added to composite state'%'.", _entry_point->get_name(), get_name() );
	return( *entry_points_.back() );
}


entry_point& composite_state_impl::add_entry_point( const std::string& _entry_point_name )
{
	sxe::SX_UNIQUE_PTR< sxy::entry_point_impl > entry_point =
		SX_MAKE_UNIQUE< sxy::entry_point_impl >( _entry_point_name );
	entry_point->set_parent_state( this );
	entry_points_.push_back( sxe::move( entry_point ) );
	SX_LOG( hermes::log_level::LL_TRACE, "Entry point '%' was added to composite state'%'.", _entry_point_name, get_name() );
	return( *entry_points_.back() );
}


const raw_const_exit_points composite_state_impl::get_exit_points() const
{
	raw_const_exit_points exit_points;
	exit_points.reserve( exit_points_.size() );

	SX_FOR( const exit_point_uptr& exit_point, exit_points_ )
	{
		exit_points.push_back( exit_point.get() );
	}

	return( exit_points );
}


exit_point& composite_state_impl::add_exit_point( exit_point_uptr _exit_point )
{
	_exit_point->set_parent_state( this );
	exit_points_.push_back( sxe::move( _exit_point ) );
	SX_LOG( hermes::log_level::LL_TRACE, "Exit point '%' was added to composite state'%'.", _exit_point->get_name(), get_name() );
	return( *exit_points_.back() );
}


exit_point& composite_state_impl::add_exit_point( const std::string& _exit_point_name )
{
	sxe::SX_UNIQUE_PTR< sxy::exit_point_impl > exit_point = SX_MAKE_UNIQUE< sxy::exit_point_impl >( _exit_point_name );
	exit_point->set_parent_state( this );
	exit_points_.push_back( sxe::move( exit_point ) );
	SX_LOG( hermes::log_level::LL_TRACE, "Entry point '%' was added to composite state'%'.", _exit_point_name, get_name() );
	return( *exit_points_.back() );
}


vertex* composite_state_impl::get_pseudostate( const std::string& _name_of_pseudostate ) const
{
	vertex* found_vertex = SX_NULLPTR;
	if( deep_history_ && ( deep_history_->get_name() == _name_of_pseudostate ) )
	{
		found_vertex = deep_history_.get();
	}
	else
	if( shallow_history_ && ( shallow_history_->get_name() == _name_of_pseudostate ) )
	{
		found_vertex = shallow_history_.get();
	}
	else
	{
		SX_FOR( const entry_point_uptr& entry_point, entry_points_ )
		{
			if( entry_point->get_name() == _name_of_pseudostate )
			{
				found_vertex = entry_point.get();
				break;
			}
		}

		if( !found_vertex )
		{
			SX_FOR( const exit_point_uptr& exit_point, exit_points_ )
			{
				if( exit_point->get_name() == _name_of_pseudostate )
				{
					found_vertex = exit_point.get();
					break;
				}
			}
		}
	}

	return( found_vertex );
}


size_t composite_state_impl::get_region_index( const region* const _region ) const
{
	regions::const_iterator element =
		std::find_if( regions_.begin(), regions_.end(), sxe::bind( &composite_state_impl::regions_are_equal, _region, sxe::_1 ) );
	const size_t index = element - regions_.begin();
	return( index );
}


size_t composite_state_impl::get_parent_region_index() const
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


bool composite_state_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// 15.3.11 State -> Constraint [5]: A composite state is a state with at least one region.
	if( get_regions().empty() )
	{
		_defects.push_back( state_machine_defect( *this, "Composite state '%' has no regions!",
				get_name() ) );
		check_ok = false;
	}

	// 15.3.11 State -> Constraint [5]: An orthogonal state is a composite state with at least 2 regions.
	// Not reason to check this. For yasmine this is not relevant.

	SX_FOR( const region_uptr& region, get_regions() )
	{
		if( !region->check( _defects ) )
		{
			check_ok = false;
		}
	}

	SX_FOR( const entry_point* const entry_point, get_entry_points() )
	{
		if( !entry_point->check( _defects ) )
		{
			check_ok = false;
		}
	}

	SX_FOR( const exit_point* const exit_point, get_exit_points() )
	{
		if( !exit_point->check( _defects ) )
		{
			check_ok = false;
		}
	}

	const deep_history* const deep_history = get_deep_history();
	if( deep_history )
	{
		if( !deep_history->check( _defects ) )
		{
			check_ok = false;
		}
	}

	const shallow_history* const shallow_history = get_shallow_history();
	if( shallow_history )
	{
		if( !shallow_history->check( _defects ) )
		{
			check_ok = false;
		}
	}

	// a state cannot defer an event that triggers a transition
	if( complex_state_impl::check_if_one_of_the_deferred_events_triggers_a_transition() )
	{
		_defects.push_back( state_machine_defect( *this,
				"Simple state '%' defer event that triggers a outgoing transition!", get_name() ) );
		check_ok = false;
	}

	return( check_ok );
}


void composite_state_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void composite_state_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void composite_state_impl::accept_complex_state_visitor( complex_state_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void composite_state_impl::accept_state_visitor( state_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


bool composite_state_impl::is_orthogonal() const
{
	bool is_orthogonal = false;
	
	if( get_regions().size() > 1 )
	{
		is_orthogonal = true;
	}

	return( is_orthogonal );
}


bool composite_state_impl::check_if_regions_are_completed() const
{
	bool regions_are_completed = true;

	SX_FOR( const region_uptr& region, get_regions() )
	{
		if( !region->is_active_state_final() )
		{
			regions_are_completed = false;
			SX_LOG( hermes::log_level::LL_SPAM, "Region '%' is not completed.", region->get_name() );
			break;
		}

		SX_LOG( hermes::log_level::LL_SPAM, "Region '%' is completed.", region->get_name() );
	}

	return( regions_are_completed );
}


bool composite_state_impl::regions_are_equal(const region* const _region, const region_uptr& _vector_element_region)
{
	return( _region == _vector_element_region.get() );
}


}
