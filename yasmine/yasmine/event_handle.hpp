//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_HANDLE_57AE05A6_DA8B_4D0C_A50D_06AF8DFB46BF
#define EVENT_HANDLE_57AE05A6_DA8B_4D0C_A50D_06AF8DFB46BF


#include <algorithm>
#include "compatibility.hpp"


namespace sxy
{


	typedef sxy::uint32_t handle_type;

#ifndef Y_CPP03_BOOST
	extern const handle_type Y_INVALID_EVENT_CREATION_REQUEST_HANDLE;
#else
	#define Y_INVALID_EVENT_CREATION_REQUEST_HANDLE UINT_MAX
#endif

	extern const handle_type Y_DEFAULT_HANDLE;


}


#endif
