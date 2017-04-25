//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING


#ifndef LOGGER_FWD_9F0DC46E_91EC_44AB_ADE0_7F223D30DE83
#define LOGGER_FWD_9F0DC46E_91EC_44AB_ADE0_7F223D30DE83


#include <vector>			

#include "essentials/compatibility/compatibility.hpp"


namespace hermes
{


class logger;

//!\typedef Alias for logger smart pointer.
typedef sxe::SX_UNIQUE_PTR< logger > logger_uptr;

//!\typedef Alias for vector of logger smart pointers.
typedef std::vector< logger_uptr > loggers;


}


#endif


#endif
