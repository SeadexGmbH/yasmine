//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "region_model_impl.hpp"

#include <algorithm>

#include "pseudostate_model_impl.hpp"
#include "state_model.hpp"
#include "model_exception.hpp"
#include "delete_visitor.hpp"


namespace sxy
{


namespace model
{


region_model_impl::region_model_impl( const std::string& _name )
	: state_machine_element_model_impl( _name, model_element_type::TYE_REGION )
{
	// Nothing to do...
}


region_model_impl::~region_model_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


row_const_state_models region_model_impl::get_states() const
{
	row_const_state_models states;
	SX_FOR( const state_model_uptr &state, states_ )
	{
		states.push_back( state.get() );
	}
	return( states );
}


const size_t region_model_impl::get_states_count() const
{
	return( states_.size() );
}


state_model& region_model_impl::get_state( const size_t _index )
{
	if( _index >= states_.size() )
	{
		throw exception( "Index out of range!" );
	}
	return( *states_.at( _index ) );
}


void region_model_impl::add_state( state_model_uptr _state )
{
	_state->set_parent( this );
	states_.push_back( sxe::move( _state ) );
}


void region_model_impl::remove_state( const size_t _index )
{
	if( _index >= states_.size() )
	{
		throw exception( "Index out of range!" );
	}
	states_.erase( std::remove( states_.begin(), states_.end(), states_.at( _index ) ) );
}


raw_const_pseduostate_models region_model_impl::get_pseudostates() const
{
	raw_const_pseduostate_models pseudostates;
	SX_FOR( const pseudostate_model_uptr &pseudostate, pseudostates_ )
	{
		pseudostates.push_back( pseudostate.get() );
	}
	return( pseudostates );
}


const size_t region_model_impl::get_pseudostates_count() const
{
	return( pseudostates_.size() );
}


pseudostate_model& region_model_impl::get_pseudostate( const size_t _index )
{
	if( _index >= pseudostates_.size() )
	{
		throw exception( "Index out of range!" );
	}
	return( *pseudostates_.at( _index ) );
}


void region_model_impl::add_pseudostate( pseudostate_model_uptr _pseudostate )
{
	_pseudostate->set_parent( this );
	pseudostates_.push_back( sxe::move( _pseudostate ) );
}


void region_model_impl::remove_pseudostate( const size_t _index )
{
	if( _index >= pseudostates_.size() )
	{
		throw exception( "Index out of range!" );
	}
	pseudostates_.erase( std::remove( pseudostates_.begin(), pseudostates_.end(), pseudostates_.at( _index ) ) );
}


state_machine_element_model* region_model_impl::get_child( const sxe::uri& _uri )
{
	state_machine_element_model* found_child = SX_NULLPTR;
	sxe::uri local_uri = _uri;
	local_uri.pop_front();
	const std::string child_to_find = local_uri.get_front();
	
	for( size_t i = 0; i < states_.size() && !found_child; ++i )
	{
		if( states_.at( i )->get_name() == child_to_find )
		{
			if( local_uri.size() == 1 )
			{
				found_child = states_.at( i ).get();
			}
			else
			{
				found_child = states_.at( i )->get_child( local_uri );
			}
		}
	}

	if( !found_child )
	{
		for( size_t j = 0; j < pseudostates_.size() && !found_child; ++j )
		{
			if( pseudostates_.at( j )->get_name() == child_to_find )
			{
				if( local_uri.size() == 1 )
				{
					found_child = pseudostates_.at( j ).get();
				}
				else
				{
					throw sxy::model::exception( "A pseudostate cannot have children!" );
				}
			}
		}
	}

	if( !found_child )
	{
		throw sxy::model::exception( "Region '%' has no child with name '%'!", get_name(), child_to_find );
	}

	return( found_child );
}


void region_model_impl::accept_delete_visitor( delete_visitor& _delete_visitor )
{
	_delete_visitor.visit( *this );
}


}


}
