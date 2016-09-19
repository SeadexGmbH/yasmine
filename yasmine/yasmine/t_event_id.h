//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_EVENT_ID_CF181689_64F7_47A0_BCD5_8BD0C22F7478
#define T_EVENT_ID_CF181689_64F7_47A0_BCD5_8BD0C22F7478


#include <vector>


namespace sxy
{


// !\brief The type alias for yasmine's event IDs.
using t_event_id = unsigned int;

// !\brief The type alias for yasmine's event ID list.
using t_event_ids = std::vector< t_event_id >;

// !\brief yasmine's predefined event ID for the completion event.
extern const t_event_id COMPLETION_EVENT;


}


#endif
