//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "state_machine_model.hpp"

#include <algorithm>

#include "composite_state_model_impl.hpp"
#include "model_exception.hpp"


namespace sxy
{


namespace model
{


state_machine_model::state_machine_model()
	: transitions_(),
		root_state_(),
		event_list_(),
		externals_()
{
	// Nothing to do...
}


state_machine_model::~state_machine_model() SX_NOEXCEPT
{
	// Nothing to do...
}


void state_machine_model::add_transition( transition_model_uptr _transition )
{
	transitions_.push_back( sxe::move( _transition ) );
}


void state_machine_model::remove_transition( const size_t _index )
{
	if( _index >= transitions_.size() )
	{
		throw exception( "Index out of range!" );
	}
	transitions_.erase( std::remove( transitions_.begin(), transitions_.end(), transitions_.at( _index ) ) );
}


raw_const_transition_models state_machine_model::get_transitions() const
{
	raw_const_transition_models transitions;
	if( !transitions_.empty() )
	{
		SX_FOR( const transition_model_uptr &transition, transitions_ )
		{
			transitions.push_back( transition.get() );
		}
	}

	return( transitions );
}


transition_model& state_machine_model::get_transition( const size_t _index )
{
	if( _index >= transitions_.size() )
	{
		throw exception( "Index out of range!" );
	}
	return( *transitions_.at( _index ) );
}


composite_state_model_impl& state_machine_model::get_root_state() const
{
	return( *root_state_ );
}


void state_machine_model::add_root_state( composite_state_model_uptr _root_state )
{
	root_state_ = sxe::move( _root_state );
}


sxy::model::state_machine_model::events state_machine_model::get_events() const
{
	return( event_list_ );
}


event_model& state_machine_model::get_event( const size_t _index )
{
	if( _index >= event_list_.size() )
	{
		throw exception( "Index out of range!" );
	}
	return( *event_list_.at( _index ) );
}


const event_model& state_machine_model::get_event( const size_t _index ) const
{
	if( _index >= event_list_.size() )
	{
		throw exception( "Index out of range!" );
	}
	return( *event_list_.at( _index ) );
}


std::string state_machine_model::get_event_name( const sxy::model::event_id& _event_id ) const
{
	std::string event_name = "";
	for( size_t i = 0; i < event_list_.size(); ++i )
	{
		if( event_list_.at( i )->get_id() == _event_id )
		{
			event_name = event_list_.at( i )->get_name();
			break;
		}
	}
	return( event_name );
}


void state_machine_model::add_event( const std::string& _event_name, const event_id& _event_id, 
	const event_priority& _event_priority )
{
	event_list_.push_back( SX_MAKE_SHARED<event_model>( _event_name, _event_id, _event_priority ) );
}


void state_machine_model::remove_event( const size_t _index )
{
	sxy::model::event_sptr event_to_be_deleted = event_list_.at( _index );
	event_list_.erase( std::remove( event_list_.begin(), event_list_.end(), event_to_be_deleted ), event_list_.end() );
}


std::vector<sxy::model::state_machine_element_model*> state_machine_model::get_event_references( const event_sptr _event )
{
	std::vector<sxy::model::state_machine_element_model*> elements;
	for( size_t i = 0; i < transitions_.size(); ++i )
	{
		if( transitions_.at( i )->has_trigger( _event->get_id() ) )
		{
			elements.push_back( transitions_.at( i ).get() );
		}
	}

	root_state_->get_event_references( elements, _event );
	return( elements );
}


const external_vertices& state_machine_model::get_externals() const
{
	return( externals_ );
}


external_vertices& state_machine_model::get_externals()
{
	return( externals_ );
}


void state_machine_model::add_external_vertex( external_uptr _external_vertex )
{
	externals_.push_back( sxe::move( _external_vertex ) );
}


void state_machine_model::remove_external_vertex( const size_t _index )
{
	external_uptr& vertex_to_be_deleted = externals_.at( _index );
	externals_.erase( std::remove( externals_.begin(), externals_.end(), vertex_to_be_deleted ) );
}


}


}
