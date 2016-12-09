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


#ifdef Y_CPP03_BOOST
	#ifdef Y_NO_VARIADIC_MACRO
		#include "log_and_throw_helper.hpp"
	#endif
#endif


namespace sxy
{


#ifndef Y_CPP03_BOOST


#define LOG_AND_THROW( _log_level, ... ) \
	Y_LOG( _log_level, __VA_ARGS__ ); \
	throw exception( __VA_ARGS__ );


#else

#ifndef Y_NO_VARIADIC_MACRO

#define Y_EXPAND( x ) x

#define Y_CAT( A, B ) A ## B
#define Y_SELECT( NAME, NUM ) Y_CAT( NAME ## _, NUM )
	
#define Y_GET_COUNT( _ONE, _TWO, _THREE, _FOUR, _FIVE, _SIX, COUNT, ... ) COUNT
#define Y_VA_SIZE( ... ) Y_EXPAND( Y_GET_COUNT( __VA_ARGS__, 6, 5, 4, 3, 2, 1 ) )
	
#define Y_VA_SELECT( NAME, _level, ... ) Y_EXPAND( Y_SELECT( NAME, Y_VA_SIZE(__VA_ARGS__) )( _level, __VA_ARGS__) )
	
#define LOG_AND_THROW( _level, ... ) Y_EXPAND( Y_VA_SELECT( LOG_AND_THROW_PARAM, _level, __VA_ARGS__ ) )


#define LOG_AND_THROW_PARAM_1( _log_level, _what ) \
	Y_LOG( _log_level, _what ); \
	throw exception( _what );


#define LOG_AND_THROW_PARAM_2( _log_level, _what, _value ) \
	Y_LOG( _log_level, _what, _value ); \
	throw exception( _what, _value );


#define LOG_AND_THROW_PARAM_3( _log_level, _what, _value1, _value2 ) \
	Y_LOG( _log_level, _what, _value1, _value2 ); \
	throw exception( _what, _value1, _value2 );


#define LOG_AND_THROW_PARAM_4( _log_level, _what, _value1, _value2, _value3 ) \
	Y_LOG( _log_level, _what, _value1, _value2, _value3 ); \
	throw exception( _what, _value1, _value2, _value3 );


#define LOG_AND_THROW_PARAM_5( _log_level, _what, _value1, _value2, _value3, _value4 ) \
	Y_LOG( _log_level, _what, _value1, _value2, _value3, _value4 ); \
	throw exception( _what, _value1, _value2, _value3, _value4 );


#define LOG_AND_THROW_PARAM_6( _log_level, _what, _value1, _value2, _value3, _value4, _value5 ) \
	Y_LOG( _log_level, _what, _value1, _value2, _value3, _value4, _value5 ); \
	throw exception( _what, _value1, _value2, _value3, _value4, _value5 );


#else
		
	#define	LOG_AND_THROW sxy::log_and_throw_helper( __FILE__, __LINE__ ).log

#endif

#endif


}


#endif
