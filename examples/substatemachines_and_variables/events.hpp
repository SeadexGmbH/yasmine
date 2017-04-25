//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENTS_9579372F_23DD_4365_927A_48C94C0A2585
#define EVENTS_9579372F_23DD_4365_927A_48C94C0A2585


#include "yasmine.hpp"
 
 
namespace
{


#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )
	#define EVENT_1 1
	#define EVENT_2 2
	#define EVENT_3 3
	#define EVENT_4 4
	#define EVENT_5 5
#else
	constexpr sxy::event_id EVENT_1 = 1;
	constexpr sxy::event_id EVENT_2 = 2;
	constexpr sxy::event_id EVENT_3 = 3;
	constexpr sxy::event_id EVENT_4 = 4;
	constexpr sxy::event_id EVENT_5 = 5;
#endif
 	
		
}


namespace examples
{

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )
	Y_EVENT_WITH_ID( event_1, EVENT_1 )
	Y_EVENT_WITH_ID( event_2, EVENT_2 )
	Y_EVENT_WITH_ID( event_3, EVENT_3 )
	Y_EVENT_WITH_ID( event_4, EVENT_4 )
	Y_EVENT_1PARAM_WITH_ID( event_5, std::string, get_param, EVENT_5 )
#else
	Y_EVENT_CREATE( event_1, EVENT_1 )
	Y_EVENT_CREATE( event_2, EVENT_2 )
	Y_EVENT_CREATE( event_3, EVENT_3 )
	Y_EVENT_CREATE( event_4, EVENT_4 )
	Y_EVENT_CREATE( event_5, EVENT_5, std::string, get_param )
#endif

}

#endif
