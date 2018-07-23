//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "transition_model_impl.hpp"

#include <algorithm>

#include "essentials/base.hpp"

#include "model_exception.hpp"
#include "delete_visitor.hpp"


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


void transition_model_impl::set_kind( transition_model_kind _kind )
{
	kind_ = _kind;
}


const std::string& transition_model_impl::get_behavior() const
{
	return( behavior_ );
}


void transition_model_impl::set_behavior( const std::string& _behavior )
{
	behavior_ = _behavior;
}


const std::string& transition_model_impl::get_guard() const
{
	return( guard_ );
}


void transition_model_impl::set_guard( const std::string& _guard )
{
	guard_ = _guard;
}


const sxe::uri& transition_model_impl::get_source() const
{
	return( source_ );
}


void transition_model_impl::set_source( const std::string& _source )
{
	source_ = sxe::uri( _source );
}


const sxe::uri& transition_model_impl::get_target() const
{
	return( target_ );
}


void transition_model_impl::set_target( const std::string& _target )
{
	target_ = sxe::uri( _target );
}


const event_ids& transition_model_impl::get_event_ids() const
{
	return( events_ );
}


void transition_model_impl::set_event_ids( event_ids& _event_ids )
{
	events_ = _event_ids;
}


void transition_model_impl::add_event( const event_id _id )
{
	events_.push_back( _id );
}


void transition_model_impl::remove_event( const event_id _id )
{
	events_.erase( std::remove( events_.begin(), events_.end(), _id ), events_.end() );
}


bool transition_model_impl::has_trigger( event_id _id ) const
{
	bool transition_has_trigger = false;
	if( std::find( events_.begin(), events_.end(), _id ) != events_.end() )
	{
		transition_has_trigger = true;
	}

	return( transition_has_trigger );
}


state_machine_element_model* transition_model_impl::get_child( const sxe::uri& _uri )
{
	SX_UNUSED_PARAMETER( _uri );
	throw sxy::model::exception( "Transitions cannot have children!" );
}


void transition_model_impl::accept_delete_visitor( delete_visitor& _delete_visitor )
{
	_delete_visitor.visit( *this );
}


}


}
