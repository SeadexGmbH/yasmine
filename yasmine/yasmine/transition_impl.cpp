//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_impl.hpp"

#include <algorithm>

#include "vertex.hpp"
#include "behavior.hpp"
#include "constraint.hpp"
#include "event.hpp"
#include "uri.hpp"
#include "state_machine_defect.hpp"
#include "region.hpp"
#include "state.hpp"
#include "pseudostate.hpp"
#include "composite_state.hpp"


namespace sxy
{


#ifdef Y_CPP03_BOOST
#pragma warning( disable : 4100 )
#endif


#ifdef Y_CPP03_BOOST
transition_impl::transition_impl( const event_id _event_id, vertex& _source, vertex& _target, 
	const sxy::transition_kind _kind, constraint_uptr _guard, behavior_uptr _behavior )
	: state_machine_element_impl( get_transition_name(_source, _target, event_ids( 1, _event_id ) ) ),
		event_ids_( event_ids( 1, _event_id ) ),
		source_( _source ),
		target_( _target ),
		guard_( sxy::move( _guard ) ),
		behavior_( sxy::move( _behavior ) ),
		kind_( _kind )
{
	source_.add_outgoing_transition( *this );
	target_.add_incoming_transition( *this );
}

#else
	transition_impl::transition_impl( const event_id _event_id, vertex& _source, vertex& _target,
		const sxy::transition_kind _kind, constraint_uptr _guard, behavior_uptr _behavior )
		: transition_impl( event_ids{ _event_id }, _source, _target, _kind, sxy::move( _guard ), sxy::move( _behavior ) )
	{
		// Nothing to do...
	}
#endif



transition_impl::transition_impl( const event_ids _event_ids, vertex& _source, vertex& _target, 
	const sxy::transition_kind _kind,	constraint_uptr _guard, behavior_uptr _behavior )
	: state_machine_element_impl( get_transition_name( _source, _target, _event_ids ) ),
		event_ids_( _event_ids ),
		source_( _source ),
		target_( _target ),
		guard_( sxy::move( _guard ) ),
		behavior_( sxy::move( _behavior ) ),
		kind_( _kind )
{
	source_.add_outgoing_transition( *this );
	target_.add_incoming_transition( *this );
}


transition_impl::~transition_impl() Y_NOEXCEPT
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


const state_machine_element* transition_impl::get_parent() const 
{
	return( Y_NULLPTR );
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
	Y_LOG( sxy::log_level::LL_TRACE, "Executing transition '%' from '%' to '%'.", get_name(), get_source().get_name(),
		get_target().get_name() );
	const behavior* const behavior = get_behavior();
	if( behavior != Y_NULLPTR )
	{
		( *behavior )( _event );
	}

	Y_LOG( sxy::log_level::LL_TRACE, "Executed transition '%' from '%' to '%'.", get_name(), get_source().get_name(),
		get_target().get_name() );
}


bool transition_impl::check_guard( const event& _event ) const
{
	bool is_checked = true;
	if( guard_ )
	{
		is_checked = ( *guard_ )( _event );
	}

	return( is_checked );
}


bool transition_impl::check( state_machine_defects& _defects ) const
{
	Y_UNUSED_PARAMETER( _defects );
	bool check_ok = true;
	const vertex& source = get_source();
	const raw_regions& source_ancestors = source.get_ancestors_as_regions();
	const vertex& target = get_target();
	const raw_regions& target_ancestors = target.get_ancestors_as_regions();
	const region* const lca_of_source_target = source.LCA_region( target );
	raw_regions::const_iterator found_source_itr = 
		std::find( source_ancestors.begin(), source_ancestors.end(), lca_of_source_target );
	if( found_source_itr != source_ancestors.begin() )
	{
		--found_source_itr;
	}

	raw_regions::const_iterator found_target_itr = 
		std::find( target_ancestors.begin(), target_ancestors.end(), lca_of_source_target );
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
		const composite_state& source_composite_state = ( **found_source_itr ).get_parent_state();
		const composite_state& target_composite_state = ( **found_target_itr ).get_parent_state();
		if( source_composite_state.get_uri().to_string() == target_composite_state.get_uri().to_string() )
		{
			const std::string message =
				"Transition '%' has source ('%') and target ('%') in different regions of the same composite state.";
			_defects.push_back( state_machine_defect( *this, message, get_name(),
					source.get_name(), target.get_name() ) );
			check_ok = false;
		}
	}

	if( sxy::transition_kind::INTERNAL == get_kind() )
	{
		const state* const source_state = dynamic_cast< const state* >( &get_source() );
		if( source_state )
		{
			if( get_source().get_uri().to_string() != get_target().get_uri().to_string() )
			{
				const std::string message =
					"Transition '%' has '%' kind, but it has different states as source and target! (source= '%', target = '%').";
				_defects.push_back( state_machine_defect( *this, message, get_name(),
						to_string( get_kind() ), source_.get_name(), target_.get_name() ) );
				check_ok = false;
			}
		}
		else
		{
			_defects.push_back( state_machine_defect( *this,
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
			_defects.push_back( state_machine_defect( *this,
					"Transition '%' enters pseudostate '%' but has '%' kind! It is not possible!", get_name(),
					get_target().get_name(), to_string( get_kind() ) ) );
			check_ok = false;
		}
	}

	if( transition_kind::LOCAL == get_kind() )
	{
		if( !check_if_source_and_target_are_in_ancestor_relationship( get_source(), get_target() ) )
		{
			_defects.push_back( state_machine_defect( *this,
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
	if( std::find( event_ids_.begin(), event_ids_.end(), _event ) != event_ids_.end() )
	{
		accept = true;
	}

	return( accept );
}


bool transition_impl::check_if_source_and_target_are_in_ancestor_relationship(	const vertex& _source,	
	const vertex& _target )
{
	bool are_in_ancestor_relationship = false;
	const composite_state* const target_as_composite_state = dynamic_cast< const composite_state* >( &_target );
	if( target_as_composite_state )
	{
		are_in_ancestor_relationship = check_relationship( _source, target_as_composite_state );
	}

	if( !are_in_ancestor_relationship )
	{
		const composite_state* const source_as_composite_state = dynamic_cast< const composite_state* >( &_source );
		if( source_as_composite_state )
		{
			are_in_ancestor_relationship = check_relationship( _target, source_as_composite_state );
		}
	}

	return( are_in_ancestor_relationship );
}



bool transition_impl::check_relationship( const vertex& _lhs, const composite_state* _rhs )
{
	bool are_in_relationship = false;
	const raw_composite_states& lhs_ancestors = _lhs.get_ancestors( Y_NULLPTR );

	Y_FOR( const composite_state* const ancestor, lhs_ancestors )
	{
		if( ancestor == _rhs )
		{
			are_in_relationship = true;
			break;
		}
	}

	return( are_in_relationship );
}



std::string transition_impl::get_transition_name( vertex& _source, vertex& _target, const event_ids& _event_ids )
{
	std::string transition_name = _source.get_name() + "->" + _target.get_name();
	if( !_event_ids.empty() )
	{
		
		std::stringstream ids_as_string;
		for( size_t i = 0; i < _event_ids.size(); ++i )
		{
			if( i != 0 )
			{
				ids_as_string << ",";
			}
			ids_as_string << _event_ids[ i ];
		}

		transition_name += "(" + ids_as_string.str() + ")";
	}
	return( transition_name );
}


}
