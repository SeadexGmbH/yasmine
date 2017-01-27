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

#include "states_nesting_comparer.hpp"
#include "states_nesting_comparer_ascending.hpp"


namespace sxy
{


class state;
typedef Y_UNIQUE_PTR< state > state_uptr;
typedef std::vector< const state* > raw_const_states;
typedef std::vector< state_uptr > states;
typedef std::set< const state* > raw_const_state_set;
typedef std::set< const state*, states_nesting_comparer > raw_const_states_by_nesting_level;
typedef std::set< state*, states_nesting_comparer > raw_states_by_nesting_level;
typedef std::set< state*, states_nesting_comparer_ascending > raw_states_by_nesting_level_ascending;


}


#endif
