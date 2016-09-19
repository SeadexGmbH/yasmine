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
#include <memory>


namespace sxy
{


class transition;
using transition_uptr = std::unique_ptr< transition >;
using raw_const_transitions = std::vector< const transition* >;
using raw_transitions = std::vector< transition* >;
using transitions = std::vector< transition_uptr >;


}


#endif
