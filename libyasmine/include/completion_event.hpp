//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPLETION_EVENT_DD072799_B626_4F7D_B694_0A3B97990632
#define COMPLETION_EVENT_DD072799_B626_4F7D_B694_0A3B97990632


#include "event_template.hpp"
#include "internal_completion_event_id.hpp"


namespace sxy
{



#ifdef Y_CPP03_BOOST
	extern const event_id Y_COMPLETION_EVENT_ID;
	Y_EVENT_WITH_ID( completion_event, Y_INTERNAL_COMPLETION_EVENT_ID )
#else
	#ifdef _MSC_VER
		#if _MSC_VER <= 1800
			extern const event_id Y_COMPLETION_EVENT_ID;
			Y_EVENT_WITH_ID( completion_event, Y_INTERNAL_COMPLETION_EVENT_ID )
		#else
			constexpr event_id Y_COMPLETION_EVENT_ID = std::numeric_limits<sxy::event_id>::max();
			Y_EVENT_WITH_ID( completion_event, Y_COMPLETION_EVENT_ID )
		#endif
	#else
		constexpr event_id Y_COMPLETION_EVENT_ID = std::numeric_limits<sxy::event_id>::max();
		Y_EVENT_WITH_ID( completion_event, Y_COMPLETION_EVENT_ID )
	#endif
#endif


}


#endif
