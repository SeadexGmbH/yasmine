//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOUR_FWD_56B32B7A_BC57_467C_84D8_A79626B0DD0D
#define BEHAVIOUR_FWD_56B32B7A_BC57_467C_84D8_A79626B0DD0D


#include "compatibility.hpp"


namespace sxy
{


class behaviour;
class event;


typedef Y_UNIQUE_PTR< behaviour > behaviour_uptr;
typedef sxy::function< void ( const event& ) > behaviour_function;


}


#endif
