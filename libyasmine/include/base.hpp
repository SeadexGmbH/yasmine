//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BASE_0C97CC9D_8A5B_4696_9964_49819CD9233A
#define BASE_0C97CC9D_8A5B_4696_9964_49819CD9233A


#define Y_ASSERT( _condition, _message ) \
	do \
	{ \
		if( !( _condition ) ) \
		{ \
			Y_LOG_AND_WAIT( sxy::log_level::LL_ASSERT, "Assert failed! Message: '%', Condition '%'", _message, #_condition ); \
			assert( ( _condition ) && _message ); \
		} \
	} \
	while( 0 )


#define Y_ASSERT_NO_LOG( _condition, _message ) \
	do \
	{ \
		if( !( _condition ) ) \
		{ \
			assert( ( _condition ) && _message ); \
		} \
	} \
	while( 0 )


#define Y_ASSERTED( _x ) static_cast< void >( _x );


#define Y_UNUSED_PARAMETER( _x ) static_cast<void>( _x )



#include <cassert>

#include "log.hpp"


#endif
