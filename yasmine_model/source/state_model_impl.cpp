//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "state_model_impl.hpp"

#include <algorithm>

#include "essentials/base.hpp"

#include "model_exception.hpp"
#include "region_model.hpp"


namespace sxy
{


namespace model
{


state_model_impl::state_model_impl( const std::string& _name, const model_element_type& _type, 
	const event_ids& _deferred_events )
	: state_machine_element_model_impl( _name, _type ),
		transitions_(),
		deferred_events_( _deferred_events )
{
	// Nothing to do...
}


state_model_impl::~state_model_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


const size_t state_model_impl::get_regions_count() const
{
	return( 0 );
}


raw_const_transition_models state_model_impl::get_transitions() const
{
	std::vector< const transition_model* > transitions;
	SX_FOR( const transition_model_uptr &transition, transitions_ )
	{
		transitions.push_back( transition.get() );
	}
	return( transitions );
}


const event_ids& state_model_impl::get_deferred_events() const
{
	return( deferred_events_ );
}


void state_model_impl::add_deferred_event( const event_id _deferred_event_id )
{
	deferred_events_.push_back( _deferred_event_id );
}


void state_model_impl::remove_deferred_event( const event_id _deferred_event_id )
{
	deferred_events_.erase( std::remove( deferred_events_.begin(), deferred_events_.end(), _deferred_event_id ), deferred_events_.end() );
}


bool state_model_impl::defers_event( const event_id _id ) const
{
	bool state_defers_event = false;
	if( std::find( deferred_events_.begin(), deferred_events_.end(), _id ) != deferred_events_.end() )
	{
		state_defers_event = true;
	}
	return( state_defers_event );
}


state_machine_element_model* state_model_impl::get_child( const sxe::uri& _uri )
{
	SX_UNUSED_PARAMETER( _uri );
	throw sxy::model::exception( "State '%' is of type '%' and cannot have children!", get_name(), 
		model_element_type_to_string( get_type() ) );
}


void state_model_impl::get_event_references( std::vector<sxy::model::state_machine_element_model* >& _elements,
	const event_sptr _event )
{
	if( defers_event( _event->get_id() ) )
	{
		_elements.push_back( this );
	}
}


}


}
