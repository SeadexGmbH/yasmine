//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "simple_state_model_impl.hpp"

#include "model_vertex_visitor.hpp"
#include "model_element_type.hpp"


namespace sxy
{


namespace model
{


simple_state_model_impl::simple_state_model_impl( const std::string& _name, const std::string& _enter_behavior,
	const std::string& _do_behavior, const std::string& _exit_behavior, const event_ids& _deferred_events,
	event_sptr _error_event, bool _is_async)
	: state_model_impl( _name, model_element_type::TYE_SIMPLE_STATE, _deferred_events ),
		enter_behavior_( _enter_behavior ),
		do_behavior_( _do_behavior ),
		exit_behavior_( _exit_behavior ),
		error_event_( _error_event ),
		is_async_( _is_async )
{
	// Nothing to do...
}


simple_state_model_impl::~simple_state_model_impl()SX_NOEXCEPT
{
	// Nothing to do...
}


const std::string& simple_state_model_impl::get_enter_behavior() const
{
	return( enter_behavior_ );
}


void simple_state_model_impl::set_enter_behavior( const std::string& _enter_behavior )
{
	enter_behavior_ = _enter_behavior;
}


const std::string& simple_state_model_impl::get_do_behavior() const
{
	return( do_behavior_ );
}


void simple_state_model_impl::set_do_behavior( const std::string& _do_behavior )
{
	do_behavior_ = _do_behavior;
}


const std::string& simple_state_model_impl::get_exit_behavior() const
{
	return( exit_behavior_ );
}


void simple_state_model_impl::set_exit_behavior( const std::string& _exit_behavior )
{
	exit_behavior_ = _exit_behavior;
}


const raw_const_region_models simple_state_model_impl::get_regions() const
{
	raw_const_region_models regions;
	return( regions );
}


void simple_state_model_impl::accept( model_vertex_visitor& _constructor_visitor ) const
{
	_constructor_visitor.visit( *this );
}


event_sptr simple_state_model_impl::get_error_event() const
{
	return( error_event_ );
}


void simple_state_model_impl::set_error_event( event_sptr _error_event )
{
	error_event_ = _error_event;
}


bool simple_state_model_impl::is_async() const
{
	return( is_async_ );
}


void simple_state_model_impl::set_is_async( bool _is_async )
{
	is_async_ = _is_async;
}


}


}
