//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_ID_C05A5A39_AC17_467C_B975_8D744CC77D8B
#define EVENT_ID_C05A5A39_AC17_467C_B975_8D744CC77D8B


#include <vector>
#include <cstdint>


namespace sxy
{


//!\brief The type alias for yasmine's event IDs.
using event_id = std::uint32_t;

//!\brief The type alias for yasmine's event ID list.
using event_ids = std::vector< event_id >;

//!\brief yasmine's predefined event ID for the completion event.
extern const event_id COMPLETION_EVENT;


}


#endif
