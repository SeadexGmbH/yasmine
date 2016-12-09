//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "vertex_impl.hpp"

#include <algorithm>
#include <iostream>

#include "composite_state.hpp"
#include "region.hpp"
#include "transition.hpp"
#include "uri.hpp"
#include "log.hpp"
#include "event.hpp"


namespace sxy
{


vertex_impl::vertex_impl( const std::string& _name )
	: state_machine_element_impl( _name ),
		outgoing_transitions_(),
		incoming_transitions_()
{
	// Nothing to do...
}


vertex_impl::~vertex_impl() Y_NOEXCEPT
{
	// Nothing to do...
}
	 

void vertex_impl::add_outgoing_transition( transition& _outgoing_transition )
{
	outgoing_transitions_.push_back( &_outgoing_transition );
}


void vertex_impl::add_incoming_transition( transition& _incoming_transition )
{
	incoming_transitions_.push_back( &_incoming_transition );
}


void vertex_impl::remove_outgoing_transition( const transition& _outgoing_transition )
{
	const raw_transitions::iterator outgoing_transition = std::find( outgoing_transitions_.begin(),
		outgoing_transitions_.end(), &_outgoing_transition );
	outgoing_transitions_.erase( outgoing_transition );
}


void vertex_impl::remove_incoming_transition( const transition& _incoming_transition )
{
	const raw_transitions::iterator incoming_transition = std::find( incoming_transitions_.begin(),
		incoming_transitions_.end(), &_incoming_transition );
	incoming_transitions_.erase( incoming_transition );
}


const raw_transitions& vertex_impl::get_outgoing_transitions() const
{
	return( outgoing_transitions_ );
}


const raw_transitions& vertex_impl::get_incoming_transitions() const
{
	return( incoming_transitions_ );
}


uri vertex_impl::get_uri() const
{
	uri uri( get_name() );
	add_ancestor_uri( uri );
	return( uri );
}


transition* vertex_impl::search_transition( const event& _event ) const
{
	const raw_transitions& transitions = get_outgoing_transitions();
	transition* found_transition = Y_NULLPTR;

	Y_FOR( transition* const transition, transitions )
	{
		if( transition->can_accept_event( _event.get_id() ) )
		{
			const bool is_checked = transition->check_guard( _event );
			if( is_checked )
			{
				found_transition = transition;
				break;
			}
		}
	}

	return( found_transition );
}


region* vertex_impl::LCA_region( const vertex& _rhs ) const
{
	Y_LOG( log_level::LL_SPAM, "Start calculating LCA_region for '%' and '%'.", get_name(), _rhs.get_name() );
	region* lca = Y_NULLPTR;
	const raw_regions& ancestors_of_lhs = get_ancestors_as_regions();
	const raw_regions& ancestors_of_rhs = _rhs.get_ancestors_as_regions();
	Y_ASSERT( ancestors_of_lhs.size() >= 1 && ancestors_of_rhs.size() >= 1,
		"One of the ancestor region lists is empty!" );
	size_t r_idx = ancestors_of_rhs.size() - 1;
	size_t l_idx = ancestors_of_lhs.size() - 1;
	while( ancestors_of_rhs[ r_idx ] == ancestors_of_lhs[ l_idx ] )
	{
		lca = ancestors_of_lhs[ l_idx ];
		if( ( l_idx == 0 ) || ( r_idx == 0 ) )
		{
			break;
		}

		--r_idx;
		--l_idx;
	}

	Y_ASSERT( lca, "No LCA_region has been found!" );
	Y_LOG( log_level::LL_SPAM, "LCA region found: '%'.", lca->get_name() );
	return( lca );
}


composite_state* vertex_impl::LCA_composite_state( const vertex& _rhs ) const
{
	Y_LOG( log_level::LL_SPAM, "Start calculating LCA_composite_state for '%' and '%'.", get_name(), _rhs.get_name() );
	composite_state* lca = Y_NULLPTR;
	const raw_composite_states& ancestors_of_lhs = get_ancestors( Y_NULLPTR );
	const raw_composite_states& ancestors_of_rhs = _rhs.get_ancestors( Y_NULLPTR );
	Y_ASSERT( ancestors_of_lhs.size() >= 1 && ancestors_of_rhs.size() >= 1,
		"One of the ancestor region lists is empty!" );
	size_t r_idx = ancestors_of_rhs.size() - 1;
	size_t l_idx = ancestors_of_lhs.size() - 1;
	while( ancestors_of_rhs[ r_idx ] == ancestors_of_lhs[ l_idx ] )
	{
		lca = ancestors_of_lhs[ l_idx ];
		if( ( l_idx == 0 ) || ( r_idx == 0 ) )
		{
			break;
		}

		--r_idx;
		--l_idx;
	}

	if( lca )
	{
		Y_LOG( log_level::LL_SPAM, "LCA_composite_state found: '%'.", lca->get_name() );
	}
	else
	{
		Y_LOG( log_level::LL_SPAM, "No LCA_composite_state has been found. LCA is nullptr." );
	}

	return( lca );
}


void vertex_impl::add_ancestor_uri( uri& _uri ) const
{
	const state_machine_element* parent = get_parent();
	while( parent )
	{
		_uri.push_front( parent->get_name() );
		parent = parent->get_parent();
	}
}


}
