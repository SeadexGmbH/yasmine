//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BASE_0C97CC9D_8A5B_4696_9964_49819CD9233A
#define BASE_0C97CC9D_8A5B_4696_9964_49819CD9233A


//!\def SX_ASSERT( _condition, _message )
//!\brief Assert a given condition. Adds the message to the assert for better diagnostics when the assert is triggered.
#define SX_ASSERT( _condition, _message ) \
	do \
	{ \
			assert( ( _condition ) && _message ); \
	} \
	while( 0 )

//!\def SX_ASSERTED( _x )
//!\brief Suppress warnings for variables that are only used within asserts.
#define SX_ASSERTED( _x ) static_cast< void >( _x );

//!\def SX_UNUSED_PARAMETER( _x )
//!\brief Suppress warnings for unreferenced parameters.
#define SX_UNUSED_PARAMETER( _x ) static_cast<void>( _x )


//!\def SX_UNUSED_VARIABLE( _x )
//!\brief Suppress warnings for unreferenced variable.
#define SX_UNUSED_VARIABLE( _x ) static_cast<void>( _x )


#include <cassert>


#endif
