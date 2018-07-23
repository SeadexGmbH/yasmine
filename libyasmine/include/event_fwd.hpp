//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_FWD_622C6A23_5E15_4A6B_8278_460C74941A10
#define EVENT_FWD_622C6A23_5E15_4A6B_8278_460C74941A10


#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class event;
typedef sxe::shared_ptr< event > event_sptr;
typedef std::vector< event_sptr > events;


}


#endif
