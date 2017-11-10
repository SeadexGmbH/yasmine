//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENTS_21338320_A7F5_43B1_90D9_E0FBED2D211B
#define EVENTS_21338320_A7F5_43B1_90D9_E0FBED2D211B


#include "yasmine.hpp"


#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )
	#define EVENT_1 1
	#define EVENT_2 2
#else
constexpr sxy::event_id EVENT_1 = 1;
constexpr sxy::event_id EVENT_2 = 2;
#endif


namespace	examples
{

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )
	Y_EVENT_1PARAM_WITH_ID( event_1, std::string, get_param, EVENT_1 )
	Y_EVENT_2PARAM_WITH_ID( event_2, int, get_param_1, double, get_param_2, EVENT_2 )
#else
	Y_EVENT_CREATE( event_1, EVENT_1, std::string, get_param )
	Y_EVENT_CREATE( event_2, EVENT_2, int, get_param_1, double, get_param_2 )
#endif


}


#endif
