//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_TRANSITION_STEP_FWD_EE67C572_F92D_481C_AC2C_0F8214399FC4
#define I_TRANSITION_STEP_FWD_EE67C572_F92D_481C_AC2C_0F8214399FC4


#include <vector>
#include <memory>


namespace sxy
{


class i_transition_step;
using i_transition_step_uptr = std::unique_ptr< i_transition_step >;
using t_transition_steps = std::vector< i_transition_step_uptr >;


}


#endif
