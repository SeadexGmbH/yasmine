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


}


}
