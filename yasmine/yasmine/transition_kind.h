//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_KIND_BA4883BC_C6FF_4F55_BA40_3FF8C973631D
#define TRANSITION_KIND_BA4883BC_C6FF_4F55_BA40_3FF8C973631D


#include <string>


namespace sxy
{


enum struct transition_kind
{
	EXTERNAL = 0, INTERNAL = 1, LOCAL = 2
};

std::string to_string( const transition_kind _kind );


}


#endif
