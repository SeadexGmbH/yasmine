//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_STEP_FWD_EE67C572_F92D_481C_AC2C_0F8214399FC4
#define TRANSITION_STEP_FWD_EE67C572_F92D_481C_AC2C_0F8214399FC4


#include <vector>
#include <memory>

#include "compatibility.hpp"


namespace sxy
{


class transition_step;
typedef sxy::Y_UNIQUE_PTR< transition_step > transition_step_uptr;
typedef std::vector< transition_step_uptr > transition_steps;


}


#endif
