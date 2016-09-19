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

#include "event.hpp"


namespace sxy
{


event_creation_request::event_creation_request(
	const std::chrono::time_point< std::chrono::system_clock >& _time, const event_sptr _event, const int _handle )
	: time_( _time ),
		event_( _event ),
		handle_( _handle )
{
	Y_LOG( log_level::LL_TRACE, "Event creation request for event '%' @ %.", _event->get_id(),
		_time.time_since_epoch().count() );
}


std::chrono::time_point< std::chrono::system_clock > event_creation_request::get_time() const
{
	return( time_ );
}


int event_creation_request::get_handle() const
{
	return( handle_ );
}


event_sptr event_creation_request::get_event() const
{
	return( event_ );
}


}
