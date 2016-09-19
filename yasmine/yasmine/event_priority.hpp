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


namespace sxy
{


//!\brief The type alias for yasmine's event priorities.
using event_priority = std::int8_t;

//!\brief The type alias for yasmine's event priority list.
using event_prioritys = std::vector< event_priority >;

//!\brief yasmine's predefined event priority for the internal use.
extern const event_priority STATE_MACHINE_INTERNAL_EVENT_PRIORITY;

//!\brief yasmine's predefined default event priority.
extern const event_priority DEFAULT_EVENT_PRIORITY;


}


#endif
