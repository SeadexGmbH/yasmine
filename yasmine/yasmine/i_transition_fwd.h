//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_TRANSITION_FWD_394BD21E_9C09_454E_8C58_19F984D09497
#define I_TRANSITION_FWD_394BD21E_9C09_454E_8C58_19F984D09497


#include <vector>
#include <memory>


namespace sxy
{


class i_transition;
using i_transition_uptr = std::unique_ptr< i_transition >;
using t_raw_const_transitions = std::vector< const i_transition* >;
using t_raw_transitions = std::vector< i_transition* >;
using t_transitions = std::vector< i_transition_uptr >;


}


#endif
