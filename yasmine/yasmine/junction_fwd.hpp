//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef JUNCTION_FWD_7B62488D_9661_42DD_BC43_8E9737158029
#define JUNCTION_FWD_7B62488D_9661_42DD_BC43_8E9737158029


#include <vector>
#include "compatibility.hpp"


namespace sxy
{


class junction;
typedef Y_UNIQUE_PTR< junction > junction_uptr;
typedef std::vector< junction_uptr > junctions;
typedef std::vector< const junction* > raw_const_junctions;


}


#endif
