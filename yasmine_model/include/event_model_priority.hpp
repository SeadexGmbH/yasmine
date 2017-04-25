//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EVENT_MODEL_PRIORITY_E5077DAE_CCFB_416A_845C_593C6FE00A01
#define EVENT_MODEL_PRIORITY_E5077DAE_CCFB_416A_845C_593C6FE00A01


#include <limits>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


namespace model
{


//!\brief The type alias for yasmine model's event priorities.
typedef sxe::int8_t event_priority;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )

#ifdef max
	#undef max
#endif

#define DEFAULT_EVENT_PRIORITY 0u

#else

//!\brief yasmine model's predefined default event priority.
constexpr event_priority DEFAULT_EVENT_PRIORITY = 0;

#endif


}


}


#endif
