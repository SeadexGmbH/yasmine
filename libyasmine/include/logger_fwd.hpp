//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef Y_NO_LOGGING

#ifndef LOGGER_FWD_9F0DC46E_91EC_44AB_ADE0_7F223D30DE83
#define LOGGER_FWD_9F0DC46E_91EC_44AB_ADE0_7F223D30DE83


#include <vector>			

#include "compatibility.hpp"


namespace sxy
{


class logger;
typedef Y_UNIQUE_PTR< logger > logger_uptr;
typedef std::vector< logger_uptr > loggers;


}


#endif

#endif
