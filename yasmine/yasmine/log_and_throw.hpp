//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_AND_THROW_A0ED92EB_7368_43EA_BB73_822E62AB4E66
#define LOG_AND_THROW_A0ED92EB_7368_43EA_BB73_822E62AB4E66


#include "log.hpp"
#include "exception.hpp"


namespace sxy
{


#define LOG_AND_THROW( _log_level, ... ) \
	Y_LOG( _log_level, __VA_ARGS__ ); \
	throw exception( __VA_ARGS__ );


}


#endif
