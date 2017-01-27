//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef INTERNAL_COMPLETION_EVENT_ID_E92CB14A_F191_491F_9D5D_EAC18995DBB7
#define INTERNAL_COMPLETION_EVENT_ID_E92CB14A_F191_491F_9D5D_EAC18995DBB7


#include "event_template.hpp"

#ifndef Y_CPP03_BOOST

#include <limits>

#endif

#ifdef max
	#undef max
#endif


//!\brief yasmine's predefined internal event ID for the completion event.
#ifdef Y_CPP03_BOOST
	#define Y_INTERNAL_COMPLETION_EVENT_ID UINT_MAX
#else
	#ifdef _MSC_VER
		#if _MSC_VER <= 1800
			#define Y_INTERNAL_COMPLETION_EVENT_ID UINT_MAX	
		#endif
	#endif
#endif
 

#endif
