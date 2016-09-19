//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_LOG_AND_THROW_A0ED92EB_7368_43EA_BB73_822E62AB4E66
#define T_LOG_AND_THROW_A0ED92EB_7368_43EA_BB73_822E62AB4E66


#include "log.h"
#include "t_exception.h"


namespace sxy
{


#define LOG_AND_THROW( p_log_level, p_message, ... ) \
	Y_LOG( p_log_level, p_message, ## __VA_ARGS__ ); \
	throw t_exception( p_message, ## __VA_ARGS__ ); \


}


#endif
