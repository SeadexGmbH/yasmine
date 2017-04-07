//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_5AD3F1F5_0FC9_4D0E_8101_D9D70B8B1486
#define LOG_5AD3F1F5_0FC9_4D0E_8101_D9D70B8B1486


#ifdef SX_NO_LOGGING


inline void parameter_muncher()
{
	// Nothing to do...
}


template< typename T, typename ... args >
void parameter_muncher( T, args ... _args )
{
	parameter_muncher( _args... );
}


//!\brief Macro that is used when SX_NO_LOGGING is defined and thus there should be no logging. Consumes all parameters
//!so no warnings occur because of unused parameters. The code does nothing and can (will) be removed by the optimizer.
//!\sa sxprintf
#define SX_LOG( _dummy, ... ) \
	do \
	{	\
		parameter_muncher( __VA_ARGS__ ); \
	} \
	while( false )


//!\brief Macro that is used when SX_NO_LOGGING is defined and thus there should be no logging. Consumes all parameters
//!so no warnings occur because of unused parameters. The code does nothing and can (will) be removed by the optimizer.
//!\sa sxprintf
#define SX_LOG_HEX( _dummy, ... ) \
	do \
	{	\
		parameter_muncher( __VA_ARGS__ ); \
	} \
	while( false )


#else


#ifndef SX_CPP03_BOOST

//!\brief Create a log message.
//!\param _level The log level of the message.
//!\param ... Parameters that are inserted into the message.
//!\sa sxprintf
#define SX_LOG( _level, ... ) \
	do \
	{ \
		hermes::log_manager_template<hermes::std_timestamp_policy>& l_log_manager = hermes::log_manager::get_instance(); \
		if( _level <= l_log_manager.get_log_level() ) \
		{ \
			l_log_manager.log( _level, hermes::log_manager::get_instance().get_timestamp(), __FILE__, __LINE__, __VA_ARGS__ ); \
		} \
	} \
	while( false )


//!\brief Create a hex log message.
//!\param _level The log level of the message.
//!\param _heading The heading of the message.
//!\param _data The message of the log.
//!\param ... Parameters that are inserted into the message.
//!\sa sxprintf
#define SX_LOG_HEX( _level, _heading, _data, ... ) \
	do \
	{ \
		hermes::log_manager_template<hermes::std_timestamp_policy>& l_log_manager = hermes::log_manager::get_instance(); \
		if( _level <= l_log_manager.get_log_level() ) \
		{ \
			const std::string l_heading(_heading);\
			const std::string l_data(_data);\
			const std::string l_message = l_heading + "\n" + l_data;\
			l_log_manager.log( _level, hermes::log_manager::get_instance().get_timestamp(), __FILE__, __LINE__, l_message, __VA_ARGS__ ); \
		} \
	} \
	while( false )


//!\brief Create a log message and wait for the message to be written by the logger.
//!\param _level The log level of the message.
//!\param ... Parameters that are inserted into the message.
//!\sa sxprintf
#define SX_LOG_AND_WAIT( _level, ... ) \
	do \
	{ \
		hermes::log_manager_template<hermes::std_timestamp_policy>& l_log_manager = hermes::log_manager::get_instance(); \
		if( _level <= l_log_manager.get_log_level() ) \
		{ \
			l_log_manager.log_and_wait( _level, hermes::log_manager::get_instance().get_timestamp(), __FILE__, __LINE__, __VA_ARGS__ ); \
		} \
	} \
	while( false )


#else


#define SX_LOG hermes::log_helper( __FILE__, __LINE__).log
#define SX_LOG_AND_WAIT hermes::log_helper( __FILE__, __LINE__).log_and_wait


#endif


#endif


#ifndef SX_NO_LOGGING


#include "log_manager_template.hpp"
#include "std_timestamp_policy.hpp"


namespace hermes
{


//!\brief An alias-declaration for the log manager template.
typedef hermes::log_manager_template< hermes::std_timestamp_policy > log_manager;


}


#ifdef SX_CPP03_BOOST
#include "log_helper.hpp"
#endif


#endif


#endif
