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


#if _MSC_VER && _MSC_VER <= 1800
#define constexpr const
#endif


#define Y_ASSERT( p_condition, p_message ) \
	do \
	{ \
		if( !( p_condition ) ) \
		{ \
			Y_LOG( sxy::t_log_level::LL_ASSERT, p_message ); \
			assert( ( p_condition ) && p_message ); \
		} \
	} \
	while( 0 )


#define Y_ASSERT_NO_LOG( p_condition, p_message ) \
	do \
	{ \
		if( !( p_condition ) ) \
		{ \
			assert( ( p_condition ) && p_message ); \
		} \
	} \
	while( 0 )


#define Y_ASSERTED( p_x ) static_cast< void >( p_x );


#define Y_UNUSED_PARAMETER( p_x ) [ &p_x ] {} \
	( )


#include <cassert>

#include "log.h"


#endif
