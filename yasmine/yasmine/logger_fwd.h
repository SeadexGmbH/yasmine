//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOGGER_FWD_9F0DC46E_91EC_44AB_ADE0_7F223D30DE83
#define LOGGER_FWD_9F0DC46E_91EC_44AB_ADE0_7F223D30DE83


#include <vector>
#include <memory>


namespace sxy
{


class logger;
using logger_uptr = std::unique_ptr< logger >;
using loggers = std::vector< logger_uptr >;


}


#endif
