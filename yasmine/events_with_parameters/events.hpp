//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENTS_21338320_A7F5_43B1_90D9_E0FBED2D211B
#define EVENTS_21338320_A7F5_43B1_90D9_E0FBED2D211B


#include "yasmine.hpp"


namespace	sxy
{

	namespace
	{


#ifndef Y_CPP03_BOOST	
	constexpr event_id EVENT_1 = 1;
	constexpr event_id EVENT_2 = 2;
#else
	#define	EVENT_1 1
	#define	EVENT_2 2
#endif


}

	Y_EVENT_1PARAM_WITH_ID(event_1, std::string, get_param, EVENT_1);
	Y_EVENT_2PARAM_WITH_ID(event_2, int, get_param_1, double, get_param_2, EVENT_2);


}


#endif
