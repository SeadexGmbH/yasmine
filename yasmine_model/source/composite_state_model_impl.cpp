//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "composite_state_model_impl.hpp"

#include <algorithm>

#include "essentials/base.hpp"

#include "pseudostate_model_impl.hpp"
#include "model_vertex_visitor.hpp"
#include "model_element_type.hpp"
#include "region_model.hpp"
#include "model_exception.hpp"
#include "delete_visitor.hpp"


namespace sxy
{


namespace model
{


composite_state_model_impl::composite_state_model_impl( const std::string& _name, const std::string& _enter_behavior,
	const std::string& _exit_behavior, const event_ids& _deferred_events )
	: state_model_impl( _name, model_element_type::TYE_COMPOSITE_STATE, _deferred_events ),
		enter_behavior_( _enter_behavior ),
		do_behavior_( "" ),
		exit_behavior_( _exit_behavior ),
		regions_(),
		state_pseudostates_()
{
	// Nothing to do...
}


composite_state_model_impl::~composite_state_model_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


const std::string& composite_state_model_impl::get_do_behavior() const
{
	return( do_behavior_ );
}


void composite_state_model_impl::set_do_behavior( const std::string& _do_behavior )
{
	SX_UNUSED_PARAMETER( _do_behavior );
}


const std::string& composite_state_model_impl::get_enter_behavior() const
{
	return( enter_behavior_ );
}


void composite_state_model_impl::set_enter_behavior( const std::string& _enter_behavior )
{
	enter_behavior_ = _enter_behavior;
}


const std::string& composite_state_model_impl::get_exit_behavior() const
{
	return( exit_behavior_ );
}


void composite_state_model_impl::set_exit_behavior( const std::string& _exit_behavior )
{
	exit_behavior_ = _exit_behavior;
}


const raw_const_region_models composite_state_model_impl::get_regions() const
{
	raw_const_region_models regions;
	if( !regions_.empty() )
	{
		SX_FOR( const region_model_uptr &region, regions_ )
		{
			regions.push_back( region.get() );
		}
	}

	return( regions );
}


const size_t composite_state_model_impl::get_regions_count() const
{
	return( regions_.size() );
}


region_model& composite_state_model_impl::get_region( const size_t _index )
{
	if( _index >= regions_.size() )
	{
		throw exception( "Index out of range!" );
	}
	return( *regions_.at( _index ) );
}


void composite_state_model_impl::add_region( region_model_uptr _region )
{
	_region->set_parent( this );
	regions_.push_back( sxe::move( _region ) );
}


void composite_state_model_impl::remove_region( const size_t _index )
{
	if( _index >= regions_.size() )
	{
		throw exception( "Index out of range!" );
	}
	regions_.erase( std::remove( regions_.begin(), regions_.end(), regions_.at( _index ) ) );
}


raw_const_pseduostate_models composite_state_model_impl::get_state_pseudostates() const
{
	raw_const_pseduostate_models pseudostates;
	SX_FOR( const pseudostate_model_uptr &pseudostate, state_pseudostates_ )
	{
		pseudostates.push_back( pseudostate.get() );
	}
	return( pseudostates );
}


const size_t composite_state_model_impl::get_state_pseudostates_count() const
{
	return( state_pseudostates_.size() );
}


pseudostate_model& composite_state_model_impl::get_state_pseudostate( const size_t _index )
{
	if( _index >= state_pseudostates_.size() )
	{
		throw exception( "Index out of range!" );
	}
	return( *state_pseudostates_.at( _index ) );
}


void composite_state_model_impl::add_state_pseudostate( pseudostate_model_uptr _pseudostate )
{
	_pseudostate->set_parent( this );
	state_pseudostates_.push_back( sxe::move( _pseudostate ) );
}


void composite_state_model_impl::remove_state_pseudostate( const size_t _index )
{
	if( _index >= state_pseudostates_.size() )
	{
		throw exception( "Index out of range!" );
	}
	state_pseudostates_.erase( std::remove( state_pseudostates_.begin(), state_pseudostates_.end(), state_pseudostates_.at( _index ) ) );
}


state_machine_element_model* composite_state_model_impl::get_child( const sxe::uri& _uri )
{
	state_machine_element_model* found_child = SX_NULLPTR;
	sxe::uri local_uri = _uri;
	if( get_name() == local_uri.get_front() )
	{
		if( local_uri.size() == 1 )
		{
			found_child = this;
		}
		else
		{
			local_uri.pop_front();
			const std::string child_to_find = local_uri.get_front();

			for( size_t i = 0; i < regions_.size() && !found_child; ++i )
			{
				if( regions_.at( i )->get_name() == child_to_find )
				{
					if( local_uri.size() == 1 )
					{
						found_child = regions_.at( i ).get();
					}
					else
					{
						found_child = regions_.at( i )->get_child( local_uri );
					}
				}
			}

			if( !found_child )
			{
				for( size_t j = 0; j < state_pseudostates_.size() && !found_child; ++j )
				{
					if( state_pseudostates_.at( j )->get_name() == child_to_find )
					{
						if( local_uri.size() == 1 )
						{
							found_child = state_pseudostates_.at( j ).get();
						}
						else
						{
							throw sxy::model::exception( "A state pseudostate cannot have children!" );
						}
					}
				}
			}

			if( !found_child )
			{
				throw sxy::model::exception( "Composite state '%' has no child with name '%'!", get_name(), child_to_find );
			}
		}
	}
	return( found_child );
}


void composite_state_model_impl::get_event_references( std::vector<sxy::model::state_machine_element_model* >& _elements,
	const event_sptr _event )
{
	state_model_impl::get_event_references( _elements, _event );
	for( size_t i = 0; i < get_regions_count(); ++i )
	{
		region_model& region = get_region( i );
		for( size_t j = 0; j < region.get_states_count(); ++j )
		{
			region.get_state( j ).get_event_references( _elements, _event );
		}
	}
}


void composite_state_model_impl::accept( model_vertex_visitor& _constructor_visitor ) const
{
	_constructor_visitor.visit( *this );
}


void composite_state_model_impl::accept_delete_visitor( delete_visitor& _delete_visitor )
{
	_delete_visitor.visit( *this );
}


}


}
