//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_FWD_0AA81213_6028_46A1_AB10_9FB2E31B8069
#define BEHAVIOR_FWD_0AA81213_6028_46A1_AB10_9FB2E31B8069


#include "compatibility.hpp"


namespace sxy
{


class behavior;
class event;
class event_collector;


typedef Y_UNIQUE_PTR< behavior > behavior_uptr;
typedef sxy::function< void ( const event&, event_collector& ) > behavior_function;


}


#endif
