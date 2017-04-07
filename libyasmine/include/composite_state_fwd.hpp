//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOSITE_STATE_FWD_4E6EFA7D_4400_4B33_A330_603146E114BD
#define COMPOSITE_STATE_FWD_4E6EFA7D_4400_4B33_A330_603146E114BD


#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class composite_state;
typedef sxe::SX_UNIQUE_PTR< composite_state > composite_state_uptr;
typedef std::vector< composite_state* > raw_composite_states;


}


#endif
