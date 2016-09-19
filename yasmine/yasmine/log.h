//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_5AD3F1F5_0FC9_4D0E_8101_D9D70B8B1486
#define LOG_5AD3F1F5_0FC9_4D0E_8101_D9D70B8B1486

// !\brief Macro to create a log message.
// !\param p_level The log level of the message.
// !\param ... Parameters that are inserted in the message.
// !\sa yprintf
#define Y_LOG( p_level, ... ) \
	do \
	{ \
		auto & log_manager = sxy::t_log_manager::get_instance(); \
		if( p_level <= log_manager.get_log_level() ) \
		{ \
			log_manager.log( p_level, sxy::t_log_manager::get_instance().get_timestamp(), __FILE__, __LINE__, __VA_ARGS__ ); \
		} \
	} \
	while( false )


#include "t_log_manager_template.h"
#include "t_std_timestamp_policy.h"


namespace sxy
{


// !\brief An alias-declaration for the log manager template.
using t_log_manager = sxy::t_log_manager_template< sxy::t_std_timestamp_policy >;


}


#endif
