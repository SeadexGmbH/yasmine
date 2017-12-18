//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENTS_3DF961B9_B77A_4349_9F81_6D8AA0877248
#define EVENTS_3DF961B9_B77A_4349_9F81_6D8AA0877248


#include "yasmine.hpp"


#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )
	#define EVENT_1 1
	#define EVENT_2 2
	#define EVENT_3 3
	#define EVENT_4 4
#else
	constexpr sxy::event_id EVENT_1 = 1;
	constexpr sxy::event_id EVENT_2 = 2;
	constexpr sxy::event_id EVENT_3 = 3;
	constexpr sxy::event_id EVENT_4 = 4;
#endif


namespace	examples
{

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )
	Y_EVENT_WITH_ID( E1, EVENT_1 )
	Y_EVENT_WITH_ID( E2, EVENT_2 )
	Y_EVENT_WITH_ID( E3, EVENT_3 )
	Y_EVENT_1PARAM_WITH_ID( E4, std::string, get_message, EVENT_4 )
#else
	Y_EVENT_CREATE( E1, EVENT_1 )
	Y_EVENT_CREATE( E2, EVENT_2 )
	Y_EVENT_CREATE( E3, EVENT_3 )
	Y_EVENT_CREATE( E4, EVENT_4, std::string, get_message )
#endif


}


#endif
