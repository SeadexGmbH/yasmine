//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_FWD_394BD21E_9C09_454E_8C58_19F984D09497
#define TRANSITION_FWD_394BD21E_9C09_454E_8C58_19F984D09497


#include <vector>

#include "compatibility.hpp"


namespace sxy
{


class transition;


typedef sxy::Y_UNIQUE_PTR< transition > transition_uptr;
typedef std::vector< const transition* > raw_const_transitions;
typedef std::vector< transition* > raw_transitions;
typedef std::vector< transition_uptr > transitions;


}


#endif
