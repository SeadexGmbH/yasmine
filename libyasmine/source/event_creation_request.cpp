//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "event_creation_request.hpp"

#include <utility>

#include "event.hpp"
#include "log.hpp"


namespace sxy
{


event_creation_request::event_creation_request(
	const sxy::time_point< sxy::system_clock >& _time, const event_sptr _event, const handle_type _handle )
	: time_( _time ),
		event_( _event ),
		handle_( _handle )
{
	Y_LOG( log_level::LL_TRACE, "Event creation request for event '%' (%) @ %.", _event->get_name(), _event->get_id(),
		_time.time_since_epoch().count() );
}


event_creation_request::~event_creation_request() Y_NOEXCEPT
{
	// Nothing to do...
}


#ifndef Y_CPP03_BOOST
event_creation_request::event_creation_request( event_creation_request&& _event_creation_request )
	: time_(sxy::move( _event_creation_request.time_)),
		event_(sxy::move(_event_creation_request.event_)),
		handle_(sxy::move(_event_creation_request.handle_))
{
	Y_LOG( log_level::LL_TRACE, "Event creation request for event '%' (%) @ %.", event_->get_name(), event_->get_id(),
		time_.time_since_epoch().count() );
}


event_creation_request& event_creation_request::operator=( event_creation_request&& _event_creation_request )
{
	time_ = sxy::move( _event_creation_request.time_ );	
	event_ = sxy::move( _event_creation_request.event_ );
	handle_ = sxy::move( _event_creation_request.handle_ );
	Y_LOG( log_level::LL_TRACE, "Event creation request for event '%' (%) @ %.", event_->get_name(), event_->get_id(),
		time_.time_since_epoch().count() );
	return( *this );
}
#endif


sxy::time_point< sxy::system_clock > event_creation_request::get_time() const
{
	return( time_ );
}


handle_type event_creation_request::get_handle() const
{
	return( handle_ );
}


event_sptr event_creation_request::get_event() const
{
	return( event_ );
}


}
