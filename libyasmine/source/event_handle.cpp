//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "event_handle.hpp"


namespace sxy
{


#ifdef SX_CPP03_BOOST
	const handle_type Y_INVALID_EVENT_CREATION_REQUEST_HANDLE = UINT_MAX;
#else
	const handle_type Y_INVALID_EVENT_CREATION_REQUEST_HANDLE = std::numeric_limits< handle_type >::max();
#endif

const handle_type Y_DEFAULT_HANDLE = 0;


}
