//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_STATE_FWD_B1FE7EC2_9444_4D6B_AD05_C59EA6F7FF8A
#define I_STATE_FWD_B1FE7EC2_9444_4D6B_AD05_C59EA6F7FF8A


#include <vector>
#include <set>
#include <memory>

#include "t_states_nesting_comparer.h"
#include "t_states_nesting_comparer_ascending.h"


namespace sxy
{


class i_state;

using i_state_uptr = std::unique_ptr< i_state >;

using t_raw_const_states = std::vector< const i_state* >;
using t_states = std::vector< i_state_uptr >;

using t_raw_const_state_set = std::set< const i_state* >;
using t_raw_const_states_by_nesting_level = std::set< const i_state*, t_states_nesting_comparer >;
using t_raw_states_by_nesting_level = std::set< i_state*, t_states_nesting_comparer >;
using t_raw_states_by_nesting_level_ascending = std::set< i_state*, t_states_nesting_comparer_ascending >;


}


#endif
