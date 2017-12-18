//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASSEMBLY_COMMON_C18F9FED_78DF_4939_A120_5C0FC87B0295
#define ASSEMBLY_COMMON_C18F9FED_78DF_4939_A120_5C0FC87B0295

#include "behavior_fwd.hpp"
#include "constraint_fwd.hpp"

#include "create_behavior_function.hpp"
#include "create_guard_function.hpp"


//!\brief Macro for an empty behavior.
#define Y_EMPTY_BEHAVIOR sxy::behavior_function()


//!\brief Macro for an empty guard.
#define Y_EMPTY_GUARD sxy::constraint_function()


#define Y_BEHAVIOR_METHOD2_SELECT_1( _object, _method ) sxy::create_behavior_function( sxy::adapt( _object, _method ) )
#define Y_BEHAVIOR_METHOD2_SELECT_2( _object, _method1, _method2 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ) )
#define Y_BEHAVIOR_METHOD2_SELECT_3( _object, _method1, _method2, _method3 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ) )
#define Y_BEHAVIOR_METHOD2_SELECT_4( _object, _method1, _method2, _method3, _method4 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ) )
#define Y_BEHAVIOR_METHOD2_SELECT_5( _object, _method1, _method2, _method3, _method4, _method5 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ) )
#define Y_BEHAVIOR_METHOD2_SELECT_6( _object, _method1, _method2, _method3, _method4, _method5, _method6 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ) )
#define Y_BEHAVIOR_METHOD2_SELECT_7( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ) )

#ifndef SX_CPP03_BOOST
	#define Y_BEHAVIOR_METHOD2_SELECT_8( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_9( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ), sxy::adapt( _object, _method9 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_10( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9, _method10 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ), sxy::adapt( _object, _method9 ), sxy::adapt( _object, _method10 ) )
#else
	#ifdef BOOST_BIND_OVER_9
		#define Y_BEHAVIOR_METHOD2_SELECT_8( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ) )
		#define Y_BEHAVIOR_METHOD2_SELECT_9( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ), sxy::adapt( _object, _method9 ) )
		#define Y_BEHAVIOR_METHOD2_SELECT_10( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9, _method10 ) sxy::create_behavior_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ), sxy::adapt( _object, _method9 ), sxy::adapt( _object, _method10 ) )
	#endif
#endif


#define Y_GUARD_METHOD2_SELECT_1( _object, _method ) sxy::create_guard_function( sxy::adapt( _object, _method ) )
#define Y_GUARD_METHOD2_SELECT_2( _object, _method1, _method2 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ) )
#define Y_GUARD_METHOD2_SELECT_3( _object, _method1, _method2, _method3 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ) )
#define Y_GUARD_METHOD2_SELECT_4( _object, _method1, _method2, _method3, _method4 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ) )
#define Y_GUARD_METHOD2_SELECT_5( _object, _method1, _method2, _method3, _method4, _method5 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ) )
#define Y_GUARD_METHOD2_SELECT_6( _object, _method1, _method2, _method3, _method4, _method5, _method6 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ) )
#define Y_GUARD_METHOD2_SELECT_7( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ) )
#ifndef SX_CPP03_BOOST
	#define Y_GUARD_METHOD2_SELECT_8( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ) )
	#define Y_GUARD_METHOD2_SELECT_9( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ), sxy::adapt( _object, _method9 ) )
	#define Y_GUARD_METHOD2_SELECT_10( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9, _method10 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ), sxy::adapt( _object, _method9 ), sxy::adapt( _object, _method10 ) )
#else
	#ifdef BOOST_BIND_OVER_9
		#define Y_GUARD_METHOD2_SELECT_8( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ) )
		#define Y_GUARD_METHOD2_SELECT_9( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ), sxy::adapt( _object, _method9 ) )
		#define Y_GUARD_METHOD2_SELECT_10( _object, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9, _method10 ) sxy::create_guard_function( sxy::adapt( _object, _method1 ), sxy::adapt( _object, _method2 ), sxy::adapt( _object, _method3 ), sxy::adapt( _object, _method4 ), sxy::adapt( _object, _method5 ), sxy::adapt( _object, _method6 ), sxy::adapt( _object, _method7 ), sxy::adapt( _object, _method8 ), sxy::adapt( _object, _method9 ), sxy::adapt( _object, _method10 ) )
	#endif
#endif


#define Y_BEHAVIOR_FUNCTION2_SELECT_1( _function ) sxy::create_behavior_function( sxy::adapt_function( _function ) )
#define Y_BEHAVIOR_FUNCTION2_SELECT_2( _function1, _function2 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ) )
#define Y_BEHAVIOR_FUNCTION2_SELECT_3( _function1, _function2, _function3 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ) )
#define Y_BEHAVIOR_FUNCTION2_SELECT_4( _function1, _function2, _function3, _function4 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ) )
#define Y_BEHAVIOR_FUNCTION2_SELECT_5( _function1, _function2, _function3, _function4, _function5 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ) )
#define Y_BEHAVIOR_FUNCTION2_SELECT_6( _function1, _function2, _function3, _function4, _function5, _function6 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ) )
#define Y_BEHAVIOR_FUNCTION2_SELECT_7( _function1, _function2, _function3, _function4, _function5, _function6, _function7 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ) )
#ifndef SX_CPP03_BOOST
	#define Y_BEHAVIOR_FUNCTION2_SELECT_8( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_9( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ), sxy::adapt_function( _function9 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_10( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ), sxy::adapt_function( _function9 ), sxy::adapt_function( _function10 ) )
#else
	#ifdef BOOST_BIND_OVER_9
		#define Y_BEHAVIOR_FUNCTION2_SELECT_8( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ) )
		#define Y_BEHAVIOR_FUNCTION2_SELECT_9( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ), sxy::adapt_function( _function9 ) )
		#define Y_BEHAVIOR_FUNCTION2_SELECT_10( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ) sxy::create_behavior_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ), sxy::adapt_function( _function9 ), sxy::adapt_function( _function10 ) )
	#endif
#endif


#define Y_GUARD_FUNCTION2_SELECT_1( _function ) sxy::create_guard_function( sxy::adapt_function( _function ) )
#define Y_GUARD_FUNCTION2_SELECT_2( _function1, _function2 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ) )
#define Y_GUARD_FUNCTION2_SELECT_3( _function1, _function2, _function3 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ) )
#define Y_GUARD_FUNCTION2_SELECT_4( _function1, _function2, _function3, _function4 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ) )
#define Y_GUARD_FUNCTION2_SELECT_5( _function1, _function2, _function3, _function4, _function5 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ) )
#define Y_GUARD_FUNCTION2_SELECT_6( _function1, _function2, _function3, _function4, _function5, _function6 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ) )
#define Y_GUARD_FUNCTION2_SELECT_7( _function1, _function2, _function3, _function4, _function5, _function6, _function7 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ) )
#ifndef SX_CPP03_BOOST
	#define Y_GUARD_FUNCTION2_SELECT_8( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ) )
	#define Y_GUARD_FUNCTION2_SELECT_9( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ), sxy::adapt_function( _function9 ) )
	#define Y_GUARD_FUNCTION2_SELECT_10( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ), sxy::adapt_function( _function9 ), sxy::adapt_function( _function10 ) )
#else
	#ifdef BOOST_BIND_OVER_9
		#define Y_GUARD_FUNCTION2_SELECT_8( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ) )
		#define Y_GUARD_FUNCTION2_SELECT_9( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ), sxy::adapt_function( _function9 ) )
		#define Y_GUARD_FUNCTION2_SELECT_10( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ) sxy::create_guard_function( sxy::adapt_function( _function1 ), sxy::adapt_function( _function2 ), sxy::adapt_function( _function3 ), sxy::adapt_function( _function4 ), sxy::adapt_function( _function5 ), sxy::adapt_function( _function6 ), sxy::adapt_function( _function7 ), sxy::adapt_function( _function8 ), sxy::adapt_function( _function9 ), sxy::adapt_function( _function10 ) )
	#endif
#endif


#define Y_BEHAVIOR_METHOD2_1 Y_BEHAVIOR_METHOD2_SELECT_1
#define Y_BEHAVIOR_METHOD2_2 Y_BEHAVIOR_METHOD2_SELECT_2
#define Y_BEHAVIOR_METHOD2_3 Y_BEHAVIOR_METHOD2_SELECT_3
#define Y_BEHAVIOR_METHOD2_4 Y_BEHAVIOR_METHOD2_SELECT_4
#define Y_BEHAVIOR_METHOD2_5 Y_BEHAVIOR_METHOD2_SELECT_5
#define Y_BEHAVIOR_METHOD2_6 Y_BEHAVIOR_METHOD2_SELECT_6
#define Y_BEHAVIOR_METHOD2_7 Y_BEHAVIOR_METHOD2_SELECT_7
#ifndef SX_CPP03_BOOST
	#define Y_BEHAVIOR_METHOD2_8 Y_BEHAVIOR_METHOD2_SELECT_8
	#define Y_BEHAVIOR_METHOD2_9 Y_BEHAVIOR_METHOD2_SELECT_9
	#define Y_BEHAVIOR_METHOD2_10 Y_BEHAVIOR_METHOD2_SELECT_10
#else
	#ifdef BOOST_BIND_OVER_9
		#define Y_BEHAVIOR_METHOD2_8 Y_BEHAVIOR_METHOD2_SELECT_8
		#define Y_BEHAVIOR_METHOD2_9 Y_BEHAVIOR_METHOD2_SELECT_9
		#define Y_BEHAVIOR_METHOD2_10 Y_BEHAVIOR_METHOD2_SELECT_10
	#endif
#endif


#define Y_GUARD_METHOD2_1 Y_GUARD_METHOD2_SELECT_1
#define Y_GUARD_METHOD2_2 Y_GUARD_METHOD2_SELECT_2
#define Y_GUARD_METHOD2_3 Y_GUARD_METHOD2_SELECT_3
#define Y_GUARD_METHOD2_4 Y_GUARD_METHOD2_SELECT_4
#define Y_GUARD_METHOD2_5 Y_GUARD_METHOD2_SELECT_5
#define Y_GUARD_METHOD2_6 Y_GUARD_METHOD2_SELECT_6
#define Y_GUARD_METHOD2_7 Y_GUARD_METHOD2_SELECT_7
#ifndef SX_CPP03_BOOST
	#define Y_GUARD_METHOD2_8 Y_GUARD_METHOD2_SELECT_8
	#define Y_GUARD_METHOD2_9 Y_GUARD_METHOD2_SELECT_9
	#define Y_GUARD_METHOD2_10 Y_GUARD_METHOD2_SELECT_10
#else
	#ifdef BOOST_BIND_OVER_9
		#define Y_GUARD_METHOD2_8 Y_GUARD_METHOD2_SELECT_8
		#define Y_GUARD_METHOD2_9 Y_GUARD_METHOD2_SELECT_9
		#define Y_GUARD_METHOD2_10 Y_GUARD_METHOD2_SELECT_10
	#endif
#endif


#define Y_BEHAVIOR_FUNCTION2_1 Y_BEHAVIOR_FUNCTION2_SELECT_1
#define Y_BEHAVIOR_FUNCTION2_2 Y_BEHAVIOR_FUNCTION2_SELECT_2
#define Y_BEHAVIOR_FUNCTION2_3 Y_BEHAVIOR_FUNCTION2_SELECT_3
#define Y_BEHAVIOR_FUNCTION2_4 Y_BEHAVIOR_FUNCTION2_SELECT_4
#define Y_BEHAVIOR_FUNCTION2_5 Y_BEHAVIOR_FUNCTION2_SELECT_5
#define Y_BEHAVIOR_FUNCTION2_6 Y_BEHAVIOR_FUNCTION2_SELECT_6
#define Y_BEHAVIOR_FUNCTION2_7 Y_BEHAVIOR_FUNCTION2_SELECT_7
#ifndef SX_CPP03_BOOST
	#define Y_BEHAVIOR_FUNCTION2_8 Y_BEHAVIOR_FUNCTION2_SELECT_8
	#define Y_BEHAVIOR_FUNCTION2_9 Y_BEHAVIOR_FUNCTION2_SELECT_9
	#define Y_BEHAVIOR_FUNCTION2_10 Y_BEHAVIOR_FUNCTION2_SELECT_10
#else
	#ifdef BOOST_BIND_OVER_9
		#define Y_BEHAVIOR_FUNCTION2_8 Y_BEHAVIOR_FUNCTION2_SELECT_8
		#define Y_BEHAVIOR_FUNCTION2_9 Y_BEHAVIOR_FUNCTION2_SELECT_9
		#define Y_BEHAVIOR_FUNCTION2_10 Y_BEHAVIOR_FUNCTION2_SELECT_10
	#endif
#endif


#define Y_GUARD_FUNCTION2_1 Y_GUARD_FUNCTION2_SELECT_1
#define Y_GUARD_FUNCTION2_2 Y_GUARD_FUNCTION2_SELECT_2
#define Y_GUARD_FUNCTION2_3 Y_GUARD_FUNCTION2_SELECT_3
#define Y_GUARD_FUNCTION2_4 Y_GUARD_FUNCTION2_SELECT_4
#define Y_GUARD_FUNCTION2_5 Y_GUARD_FUNCTION2_SELECT_5
#define Y_GUARD_FUNCTION2_6 Y_GUARD_FUNCTION2_SELECT_6
#define Y_GUARD_FUNCTION2_7 Y_GUARD_FUNCTION2_SELECT_7
#ifndef SX_CPP03_BOOST
	#define Y_GUARD_FUNCTION2_8 Y_GUARD_FUNCTION2_SELECT_8
	#define Y_GUARD_FUNCTION2_9 Y_GUARD_FUNCTION2_SELECT_9
	#define Y_GUARD_FUNCTION2_10 Y_GUARD_FUNCTION2_SELECT_10
#else
	#ifdef BOOST_BIND_OVER_9
		#define Y_GUARD_FUNCTION2_8 Y_GUARD_FUNCTION2_SELECT_8
		#define Y_GUARD_FUNCTION2_9 Y_GUARD_FUNCTION2_SELECT_9
		#define Y_GUARD_FUNCTION2_10 Y_GUARD_FUNCTION2_SELECT_10
	#endif
#endif


#endif // include guard
