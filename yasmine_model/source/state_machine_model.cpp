//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "state_machine_model.hpp"

#include "composite_state_model_impl.hpp"


namespace sxy
{


namespace model
{


state_machine_model::state_machine_model()
	: transitions_(),
		root_state_(),
		event_list_()
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


void state_machine_model::add_event( const std::string& _event_name, const event_id& _event_id, 
	const event_priority& _event_priority )
{
	event_list_.push_back( event_model( _event_name, _event_id, _event_priority ) );
}


}


}
