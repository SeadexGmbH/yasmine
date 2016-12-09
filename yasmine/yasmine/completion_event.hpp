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

#ifndef Y_CPP03_BOOST

#include <limits>

#endif

#ifdef max
	#undef max
#endif


namespace sxy
{


//!\brief yasmine's predefined event ID for the completion event.
#ifdef Y_CPP03_BOOST
#define COMPLETION_EVENT_ID UINT_MAX
#else
	constexpr event_id COMPLETION_EVENT_ID = std::numeric_limits<event_id>::max();
#endif


	Y_EVENT_WITH_ID(completion_event, COMPLETION_EVENT_ID);


}


#endif
