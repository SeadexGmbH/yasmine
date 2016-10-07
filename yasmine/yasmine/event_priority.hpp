//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_PRIORITY_A7F92EA4_6076_48E4_B56A_E5BDDC99A655
#define EVENT_PRIORITY_A7F92EA4_6076_48E4_B56A_E5BDDC99A655


#include <cstdint>
#include <vector>

#include "compatibility.hpp"


namespace sxy
{


//!\brief The type alias for yasmine's event priorities.
using event_priority = std::int8_t;

//!\brief The type alias for yasmine's event priority list.
using event_prioritys = std::vector< event_priority >;


#ifdef _MSC_VER
	#if _MSC_VER <= 1800
		#ifndef constexpr
		#define constexpr const
		#define STATE_MACHINE_INTERNAL_EVENT_PRIORITY 127u
		#define DEFAULT_EVENT_PRIORITY 0u
		#endif
	#else
//!\brief yasmine's predefined event priority for the internal use.
		constexpr event_priority STATE_MACHINE_INTERNAL_EVENT_PRIORITY = 127;
//!\brief yasmine's predefined default event priority.
		constexpr event_priority DEFAULT_EVENT_PRIORITY = 0;
	#endif
#else
//!\brief yasmine's predefined event priority for the internal use.
	constexpr event_priority STATE_MACHINE_INTERNAL_EVENT_PRIORITY = 127;
	//!\brief yasmine's predefined default event priority.
	constexpr event_priority DEFAULT_EVENT_PRIORITY = 0;
#endif


}


#endif
