//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_event_creation_request.h"

#include "i_event.h"


namespace sxy
{


t_event_creation_request::t_event_creation_request(
	const std::chrono::time_point< std::chrono::system_clock >& p_time, const t_event_sptr p_event, const int p_handle )
	: m_time( p_time ),
		m_event( p_event ),
		m_handle( p_handle )
{
	Y_LOG( t_log_level::LL_INFO, "Event creation request for event '%' @ %.", p_event->get_id(),
		p_time.time_since_epoch().count() );
}


t_event_creation_request::~t_event_creation_request() = default;


std::chrono::time_point< std::chrono::system_clock > t_event_creation_request::get_time() const
{
	return( m_time );
}


int t_event_creation_request::get_handle() const
{
	return( m_handle );
}


t_event_sptr t_event_creation_request::get_event() const
{
	return( m_event );
}


}
