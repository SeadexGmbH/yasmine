//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef SX_CPP03_BOOST


#include "completion_event.hpp"

namespace sxy
{
	const event_id Y_COMPLETION_EVENT_ID = std::numeric_limits<sxy::event_id>::max();
}


#else
	#ifdef _MSC_VER
		#if _MSC_VER <= 1800


#include "completion_event.hpp"

namespace sxy
{
	const event_id Y_COMPLETION_EVENT_ID = std::numeric_limits<sxy::event_id>::max();
}


		#endif
	#endif
#endif
