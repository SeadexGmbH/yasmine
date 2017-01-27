//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_EXCEPTION_FWD_10403E70_B796_4F09_9764_470D42AF9C4A
#define BEHAVIOR_EXCEPTION_FWD_10403E70_B796_4F09_9764_470D42AF9C4A


#include <vector>

#include "compatibility.hpp"


namespace sxy
{


class behavior_exception;


typedef Y_UNIQUE_PTR< behavior_exception > behavior_exception_uptr;
typedef std::vector< behavior_exception_uptr > behavior_exceptions;

}


#endif
