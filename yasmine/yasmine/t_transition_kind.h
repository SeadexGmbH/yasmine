//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TRANSITION_KIND_402F7AC6_8AF5_40E0_9557_B8A9E2D1CD0A
#define T_TRANSITION_KIND_402F7AC6_8AF5_40E0_9557_B8A9E2D1CD0A


#include <string>


namespace sxy
{


enum struct t_transition_kind
{
	EXTERNAL = 0, 
	INTERNAL = 1, 
	LOCAL = 2
};


std::string
to_string
(
	const t_transition_kind p_kind
);
											

}


#endif
