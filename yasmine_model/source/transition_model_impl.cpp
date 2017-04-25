//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "transition_model_impl.hpp"

namespace sxy
{


namespace model
{


transition_model_impl::transition_model_impl( const std::string& _name, const sxe::uri& _source_uri, 
	const sxe::uri& _target_uri, const transition_model_kind _kind, const std::string& _behavior,
	const std::string& _guard, const event_ids& _events )
	: state_machine_element_model_impl( _name, model_element_type::TYE_TRANSITION ),
		source_( _source_uri.to_string() ),
		target_( _target_uri ),
		kind_( _kind ),
		behavior_( _behavior ),
		guard_( _guard ),
		events_( _events )
{
	// Nothing to do...
}


transition_model_impl::~transition_model_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


transition_model_kind transition_model_impl::get_kind() const
{
	return( kind_ );
}


const std::string& transition_model_impl::get_behavior() const
{
	return( behavior_ );
}


const std::string& transition_model_impl::get_guard() const
{
	return( guard_ );
}


const sxe::uri& transition_model_impl::get_source() const
{
	return( source_ );
}


const sxe::uri& transition_model_impl::get_target() const
{
	return( target_ );
}


const event_ids& transition_model_impl::get_event_ids() const
{
	return( events_ );
}


}


}
