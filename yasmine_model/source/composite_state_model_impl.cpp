//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "composite_state_model_impl.hpp"

#include "pseudostate_model.hpp"
#include "model_vertex_visitor.hpp"
#include "model_element_type.hpp"
#include "region_model.hpp"
#include "essentials/base.hpp"


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


void composite_state_model_impl::add_region( region_model_uptr _region )
{
	_region->set_parent( this );
	regions_.push_back( sxe::move( _region ) );
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


void composite_state_model_impl::add_state_pseudostate( pseudostate_model_uptr _pseudostate )
{
	_pseudostate->set_parent( this );
	state_pseudostates_.push_back( sxe::move( _pseudostate ) );
}


void composite_state_model_impl::accept( model_vertex_visitor& _constructor_visitor ) const
{
	_constructor_visitor.visit( *this );
}


}


}
