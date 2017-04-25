//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EVENT_ADJUSTER_49D9A1B8_827D_4FE4_8789_07E6AA5A77E5
#define EVENT_ADJUSTER_49D9A1B8_827D_4FE4_8789_07E6AA5A77E5


#ifdef NDEBUG
#else
#include "essentials/base.hpp"
#include "hermes/log.hpp"
#endif


namespace sxy
{


template<typename _event_type>
const _event_type& adjust_event_type( const event& _event )
{
#ifdef NDEBUG
	return( static_cast< const _event_type& >( _event ) );
#else
	const _event_type* const specialized_event = dynamic_cast< const _event_type* const >( &_event );
	const std::string message = "Event " + _event.get_name() + " is not of given type.";
	if( !specialized_event )
	{
		SX_LOG( hermes::log_level::LL_ASSERT, message );
		SX_ASSERT( false, "Invalid event type!" );
	}
	return( *specialized_event );
#endif
}


}


#endif