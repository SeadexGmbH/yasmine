//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_FWD_B1FE7EC2_9444_4D6B_AD05_C59EA6F7FF8A
#define STATE_FWD_B1FE7EC2_9444_4D6B_AD05_C59EA6F7FF8A


#include <vector>
#include <set>
#include <memory>

#include "states_nesting_comparer.h"
#include "states_nesting_comparer_ascending.h"


namespace sxy
{


class state;
using state_uptr = std::unique_ptr< state >;
using raw_const_states = std::vector< const state* >;
using states = std::vector< state_uptr >;
using raw_const_state_set = std::set< const state* >;
using raw_const_states_by_nesting_level = std::set< const state*, states_nesting_comparer >;
using raw_states_by_nesting_level = std::set< state*, states_nesting_comparer >;
using raw_states_by_nesting_level_ascending = std::set< state*, states_nesting_comparer_ascending >;


}


#endif
