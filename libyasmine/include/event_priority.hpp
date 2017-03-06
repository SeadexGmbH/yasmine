//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_PRIORITY_A7F92EA4_6076_48E4_B56A_E5BDDC99A655
#define EVENT_PRIORITY_A7F92EA4_6076_48E4_B56A_E5BDDC99A655


#include <vector>

#include "compatibility.hpp"


namespace sxy
{


//!\brief The type alias for yasmine's event priorities.
typedef sxy::int8_t event_priority;

//!\brief The type alias for yasmine's event priority list.
typedef std::vector< event_priority > event_prioritys;


#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )

#define STATE_MACHINE_INTERNAL_EVENT_PRIORITY 127u
#define DEFAULT_EVENT_PRIORITY 0u

#else

//!\brief yasmine's predefined event priority for the internal use.
constexpr event_priority STATE_MACHINE_INTERNAL_EVENT_PRIORITY = 127;
//!\brief yasmine's predefined default event priority.
constexpr event_priority DEFAULT_EVENT_PRIORITY = 0;

#endif


}


#endif
