//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_impl.h"

#include <algorithm>

#include "base.h"
#include "vertex.h"
#include "behavior.h"
#include "constraint.h"
#include "event.h"
#include "uri.h"
#include "state_machine_defect.h"
#include "region.h"
#include "state.h"
#include "pseudostate.h"
#include "composite_state.h"


namespace sxy
{


transition_impl::transition_impl( const event_id _event_id, vertex& _source, vertex& _target, 
	const sxy::transition_kind _kind, const std::string& _name,	constraint_uptr _guard, 
	behavior_uptr _behavior )
	: transition_impl( event_ids { _event_id }, _source, _target, _kind, _name, std::move( _guard ), 
										std::move( _behavior ) ) 
{
	// Nothing to do...
}


transition_impl::transition_impl( const event_ids _event_ids, vertex& _source, vertex& _target, 
	const sxy::transition_kind _kind, const std::string& _name,	constraint_uptr _guard, 
	behavior_uptr _behavior )
	: state_machine_element_impl( _name ),
		events_( _event_ids ),
		source_( _source ),
		target_( _target ),
		guard_( std::move( _guard ) ),
		behavior_( std::move( _behavior ) ),
		kind_( _kind )
{
	source_.add_outgoing_transition( *this );
	target_.add_incoming_transition( *this );
}


transition_impl::~transition_impl()
{
	source_.remove_outgoing_transition( *this );
	target_.remove_incoming_transition( *this );
}


const vertex& transition_impl::get_source() const
{
	return( source_ );
}


const vertex& transition_impl::get_target() const
{
	return( target_ );
}


vertex& transition_impl::get_target()
{
	return( target_ );
}


const constraint* transition_impl::get_guard() const
{
	return( guard_.get() );
}


const behavior* transition_impl::get_behavior() const
{
	return( behavior_.get() );
}


uri transition_impl::get_uri() const
{
	uri uri( get_name() );
	add_ancestor_uri( uri );
	return( uri );
}


sxy::transition_kind transition_impl::get_kind() const
{
	return( kind_ );
}


void transition_impl::add_ancestor_uri( uri& _uri ) const
{
	Y_UNUSED_PARAMETER( _uri );

	// Nothing to do...
}


void transition_impl::on_transition_behavior( const event& _event ) const
{
	Y_LOG( sxy::log_level::LL_INFO, "Executing transition '%' from '%' to '%'.", get_name().c_str(),
		get_source().get_name(), get_target().get_name() );
	auto behavior = get_behavior();
	if( behavior != nullptr )
	{
		( *behavior )( _event );
	}

	Y_LOG( sxy::log_level::LL_INFO, "Executed transition '%' from '%' to '%'.", get_name().c_str(),
		get_source().get_name(), get_target().get_name() );
}


bool transition_impl::check_guard( const event& _event ) const
{
	auto is_checked = true;
	if( guard_ != nullptr )
	{
		is_checked = ( *guard_ )( _event );
	}

	return( is_checked );
}


bool transition_impl::check( state_machine_defects& _defects ) const
{
	Y_UNUSED_PARAMETER( _defects );
	auto check_ok = true;
	const auto& source = get_source();
	auto source_ancestors = source.get_ancestors_as_regions();
	const auto& target = get_target();
	auto target_ancestors = target.get_ancestors_as_regions();
	const auto lca_of_source_target = source.LCA_region( target );
	auto found_source_itr = std::find( source_ancestors.begin(), source_ancestors.end(), lca_of_source_target );
	if( found_source_itr != source_ancestors.begin() )
	{
		--found_source_itr;
	}

	auto found_target_itr = std::find( target_ancestors.begin(), target_ancestors.end(), lca_of_source_target );
	if( found_target_itr != target_ancestors.begin() )
	{
		--found_target_itr;
	}

	if( ( ( **found_source_itr ).get_uri().to_string() == lca_of_source_target->get_uri().to_string() ) ||
			( ( **found_target_itr ).get_uri().to_string() == lca_of_source_target->get_uri().to_string() ) )
	{
	}
	else
	if( ( **found_source_itr ).get_uri().to_string() != ( **found_target_itr ).get_uri().to_string() )
	{
		auto& source_composite_state = ( **found_source_itr ).get_parent_state();
		auto& target_composite_state = ( **found_target_itr ).get_parent_state();
		if( source_composite_state.get_uri().to_string() == target_composite_state.get_uri().to_string() )
		{
			const std::string message =
				"Transition '%' has source ('%') and target ('%') in different regions of the same composite state.";
			_defects.push_back( std::make_unique< state_machine_defect >( *this, message, get_name(),
					source.get_name(), target.get_name() ) );
			check_ok = false;
		}
	}

	if( sxy::transition_kind::INTERNAL == get_kind() )
	{
		const auto source_state = dynamic_cast< const state* >( &get_source() );
		if( source_state )
		{
			if( get_source().get_uri().to_string() != get_target().get_uri().to_string() )
			{
				const std::string message =
					"Transition '%' has '%' kind, but it has different states as source and target! (source= '%', target = '%').";
				_defects.push_back( std::make_unique< state_machine_defect >( *this, message, get_name(),
						to_string( get_kind() ), source_.get_name(), target_.get_name() ) );
				check_ok = false;
			}
		}
		else
		{
			_defects.push_back( std::make_unique< state_machine_defect >( *this,
					"Source '%' of transition '%' (kind: '%') is not a state!", get_source().get_name(), get_name(),
					to_string( get_kind() ) ) );
			check_ok = false;
		}
	}

	// Transition that enters a pseudostate cannot have a transition kind (it must be EXTERNAL).
	if( dynamic_cast< const pseudostate* >( &get_target() ) )
	{
		if( get_kind() != transition_kind::EXTERNAL )
		{
			_defects.push_back( std::make_unique< state_machine_defect >( *this,
					"Transition '%' enters pseudostate '%' but have '%' kind! It is not possible!", get_name(),
					get_target().get_name(), to_string( get_kind() ) ) );
			check_ok = false;
		}
	}

	if( transition_kind::LOCAL == get_kind() )
	{
		if( !check_if_source_and_target_are_in_ancestor_relationship( get_source(), get_target() ) )
		{
			_defects.push_back( std::make_unique< state_machine_defect >( *this,
					"Transition's '%' source '%' and target '%' are not in a ancestor relationship!", get_name(),
					get_source().get_name(), get_target().get_name() ) );
			check_ok = false;
		}
	}

	return( check_ok );
}


bool transition_impl::can_accept_event( const event_id _event ) const
{
	bool accept = false;
	if( std::find( events_.begin(), events_.end(), _event ) != events_.end() )
	{
		accept = true;
	}

	return( accept );
}


bool transition_impl::check_if_source_and_target_are_in_ancestor_relationship(	const vertex& _source,	
	const vertex& _target )
{
	auto are_in_ancestor_relationship = false;
	auto target_as_composite_state = dynamic_cast< const composite_state* >( &_target );
	if( target_as_composite_state )
	{
		are_in_ancestor_relationship = check_relationship( _source, target_as_composite_state );
	}

	if( !are_in_ancestor_relationship )
	{
		auto source_as_composite_state = dynamic_cast< const composite_state* >( &_source );
		if( source_as_composite_state )
		{
			are_in_ancestor_relationship = check_relationship( _target, source_as_composite_state );
		}
	}

	return( are_in_ancestor_relationship );
}



bool transition_impl::check_relationship( const vertex& _lhs, const composite_state* _rhs )
{
	auto are_in_relationship = false;
	const auto lhs_ancestors = _lhs.get_ancestors( nullptr );

	for( const auto ancestor : lhs_ancestors )
	{
		if( ancestor == _rhs )
		{
			are_in_relationship = true;
			break;
		}
	}

	return( are_in_relationship );
}


}
