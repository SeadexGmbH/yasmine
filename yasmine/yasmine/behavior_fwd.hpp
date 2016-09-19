//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_FWD_56B32B7A_BC57_467C_84D8_A79626B0DD0D
#define BEHAVIOR_FWD_56B32B7A_BC57_467C_84D8_A79626B0DD0D


#include <memory>
#include <functional>


namespace sxy
{


class behavior;
class event;
using behavior_uptr = std::unique_ptr< behavior >;
using behavior_function = std::function< void ( const event& ) >;


}


#endif
