//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_AND_THROW_A0ED92EB_7368_43EA_BB73_822E62AB4E66
#define LOG_AND_THROW_A0ED92EB_7368_43EA_BB73_822E62AB4E66


#include "log.hpp"
#include "essentials/exception.hpp"


#ifdef SX_CPP03_BOOST
	#ifdef SX_NO_VARIADIC_MACRO
		#include "log_and_throw_helper.hpp"
	#else
		#include "essentials/macro_helpers.hpp"
	#endif
#endif


namespace hermes
{


#ifndef SX_CPP03_BOOST


//!\def LOG_AND_THROW( _log_level, ... )
//!\brief Log a message and then throw an exception with the same message.
#define LOG_AND_THROW( _log_level, ... ) \
	SX_LOG( _log_level, __VA_ARGS__ ); \
	throw sxe::exception( __VA_ARGS__ );


#else


#ifndef SX_NO_VARIADIC_MACRO

#define HERMES_VA_SELECT( NAME, _level, ... ) EXPAND( SELECT( NAME, VA_SIZE(__VA_ARGS__) )( _level, __VA_ARGS__) )

//!\def LOG_AND_THROW( _level, ... )
//!\brief Log a message and then throw an exception with the same message.
#define LOG_AND_THROW( _level, ... ) EXPAND( HERMES_VA_SELECT( LOG_AND_THROW_PARAM, _level, __VA_ARGS__ ) )


#define LOG_AND_THROW_PARAM_1( _log_level, _what ) \
	SX_LOG( _log_level, _what ); \
	throw sxe::exception( _what );


#define LOG_AND_THROW_PARAM_2( _log_level, _what, _value ) \
	SX_LOG( _log_level, _what, _value ); \
	throw sxe::exception( _what, _value );


#define LOG_AND_THROW_PARAM_3( _log_level, _what, _value1, _value2 ) \
	SX_LOG( _log_level, _what, _value1, _value2 ); \
	throw sxe::exception( _what, _value1, _value2 );


#define LOG_AND_THROW_PARAM_4( _log_level, _what, _value1, _value2, _value3 ) \
	SX_LOG( _log_level, _what, _value1, _value2, _value3 ); \
	throw sxe::exception( _what, _value1, _value2, _value3 );


#define LOG_AND_THROW_PARAM_5( _log_level, _what, _value1, _value2, _value3, _value4 ) \
	SX_LOG( _log_level, _what, _value1, _value2, _value3, _value4 ); \
	throw sxe::exception( _what, _value1, _value2, _value3, _value4 );


#define LOG_AND_THROW_PARAM_6( _log_level, _what, _value1, _value2, _value3, _value4, _value5 ) \
	SX_LOG( _log_level, _what, _value1, _value2, _value3, _value4, _value5 ); \
	throw sxe::exception( _what, _value1, _value2, _value3, _value4, _value5 );


#define LOG_AND_THROW_PARAM_7( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6 ) \
	SX_LOG( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6 ); \
	throw sxe::exception( _what, _value1, _value2, _value3, _value4, _value5, _value6 );


#define LOG_AND_THROW_PARAM_8( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7 ) \
	SX_LOG( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7 ); \
	throw sxe::exception( _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7 );


#define LOG_AND_THROW_PARAM_9( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8 ) \
	SX_LOG( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8 ); \
	throw sxe::exception( _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8 );


#define LOG_AND_THROW_PARAM_10( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9 ) \
	SX_LOG( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9 ); \
	throw sxe::exception( _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9 );


#define LOG_AND_THROW_PARAM_11( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10 ) \
	SX_LOG( _log_level, _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10 ); \
	throw sxe::exception( _what, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10 );


#else


#define	LOG_AND_THROW hermes::log_and_throw_helper( __FILE__, __LINE__ ).log


#endif


#endif


}


#endif
