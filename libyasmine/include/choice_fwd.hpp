//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CHOICE_FWD_CC41E744_8F28_465B_8CD6_4F3A437D121C
#define CHOICE_FWD_CC41E744_8F28_465B_8CD6_4F3A437D121C


#include <vector>

#include "compatibility.hpp"


namespace sxy
{


class choice;
typedef Y_UNIQUE_PTR< choice > choice_uptr;
typedef std::vector< choice_uptr > choices;
typedef std::vector< const choice* > raw_const_choices;


}


#endif
