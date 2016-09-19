//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_event.h"

#include <memory>


namespace sxy
{


t_event::t_event( const t_event_id p_event_id )
	: i_event(),
		m_event_id( p_event_id )
{
	// Nothing to do...
}


t_event::~t_event() = default;


t_event_id t_event::get_id() const
{
	return( m_event_id );
}


// cppcheck-suppress unusedFunction
t_event_sptr t_event::create_event( const t_event_id p_event_id )
{
	return( std::make_shared< sxy::t_event >( p_event_id ) );
}


}
