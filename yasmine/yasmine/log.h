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


#ifdef Y_NO_LOGGING


inline void parameter_muncher()
{
	// Nothing to do...
}


template< typename T, typename ... args >
void parameter_muncher( T, args ... _args )
{
	parameter_muncher( _args... );
}


// !\brief Macro that is used when Y_NO_LOGGING is defined and thus there should be no logging. Consumes all parameters so no warnings occur because of
// unused parameters. The code does nothing and can (will) be removed by the optimizer.
// !\sa yprintf
#define Y_LOG( _dummy, ... ) \
	do \
	{	\
		parameter_muncher( __VA_ARGS__ ); \
	} \
	while( false )


#else
// !\brief Macro to create a log message.
// !\param _level The log level of the message.
// !\param ... Parameters that are inserted into the message.
// !\sa yprintf
#define Y_LOG( _level, ... ) \
	do \
	{ \
		auto& l_log_manager = sxy::log_manager::get_instance(); \
		if( _level <= l_log_manager.get_log_level() ) \
		{ \
			l_log_manager.log( _level, sxy::log_manager::get_instance().get_timestamp(), __FILE__, __LINE__, __VA_ARGS__ ); \
		} \
	} \
	while( false )


#endif


#include "log_manager_template.h"
#include "std_timestamp_policy.h"


namespace sxy
{


// !\brief An alias-declaration for the log manager template.
using log_manager = sxy::log_manager_template< sxy::std_timestamp_policy >;


}



#endif
