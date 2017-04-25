//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "region_model_impl.hpp"

#include "pseudostate_model.hpp"
#include "state_model.hpp"


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


void region_model_impl::add_state( state_model_uptr _state )
{
	_state->set_parent( this );
	states_.push_back( sxe::move( _state ) );
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


void region_model_impl::add_pseudostate( pseudostate_model_uptr _pseudostate )
{
	_pseudostate->set_parent( this );
	pseudostates_.push_back( sxe::move( _pseudostate ) );
}


}


}
