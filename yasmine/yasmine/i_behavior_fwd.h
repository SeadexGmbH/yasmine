//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_BEHAVIOR_FWD_56B32B7A_BC57_467C_84D8_A79626B0DD0D
#define I_BEHAVIOR_FWD_56B32B7A_BC57_467C_84D8_A79626B0DD0D


#include <memory>
#include <functional>


namespace sxy
{


class i_behavior;
class i_event;
using i_behavior_uptr = std::unique_ptr< i_behavior >;
using t_behavior_function = std::function< void ( const i_event& ) >;


}


#endif
