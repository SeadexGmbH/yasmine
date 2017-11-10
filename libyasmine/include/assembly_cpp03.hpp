//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASSEMBLY_CPP03_59BF4ABA_7F2D_4E58_AD8D_782FDD624770
#define ASSEMBLY_CPP03_59BF4ABA_7F2D_4E58_AD8D_782FDD624770


#ifdef SX_CPP03_BOOST

#include "essentials/macro_helpers.hpp"

#include "assembly_common.hpp"


#define Y_BEHAVIOR_METHOD( _class_name, _method_name ) Y_BEHAVIOR_METHOD_SELECT_2( _class_name, _method_name )
#define Y_BEHAVIOR_METHOD_NO_EVENT( _class_name, _method_name ) Y_BEHAVIOR_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name )
#define Y_GUARD_METHOD( _class_name, _method_name ) Y_GUARD_METHOD_SELECT_2( _class_name, _method_name )
#define Y_GUARD_METHOD_NO_EVENT( _class_name, _method_name ) Y_GUARD_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name )

//!\brief Macro for using a class method as a behavior.
#define Y_BEHAVIOR_METHOD_SELECT_2( _class_name, _method_name ) \
			sxy::behavior_function( sxe::bind( &_class_name::_method_name, this, sxe::_1 ) )

//!\brief Macro for using a class method as a behavior without an event.
#define Y_BEHAVIOR_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name ) \
			sxy::behavior_function( sxe::bind( &_class_name::_method_name, this ) )

#define Y_GUARD_METHOD_SELECT_2( _class_name, _method_name ) \
		sxy::constraint_function( sxe::bind( &_class_name::_method_name, this, sxe::_1 ) )

//!\brief Macro for using a class method as a guard without an event.
#define Y_GUARD_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name ) \
		sxy::constraint_function( sxe::bind (&_class_name::_method_name, this ) )

//!\brief Macro for using a free function as a guard.
#define Y_GUARD_FUNCTION( _function_name ) \
		sxy::constraint_function( sxe::bind( &_function_name, sxe::_1 ) )

//!\brief Macro for using a free function as a guard without an event.
#define Y_GUARD_FUNCTION_NO_EVENT( _function_name ) \
		sxy::constraint_function( sxe::bind( &_function_name ) )

//!\brief Macro for using a free function as a behavior.
#define Y_BEHAVIOR_FUNCTION( _function_name ) \
			sxy::behavior_function( sxe::bind( &_function_name, sxe::_1 ) )

//!\brief Macro for using a free function as a behavior without an event.
#define Y_BEHAVIOR_FUNCTION_NO_EVENT( _function_name ) \
		sxy::behavior_function( sxe::bind( &_function_name ) )


#define Y_BEHAVIOR_METHOD2 Y_BEHAVIOR_METHOD2_SELECT_1
#define Y_GUARD_METHOD2 Y_GUARD_METHOD2_SELECT_1
#define Y_BEHAVIOR_FUNCTION2 Y_BEHAVIOR_FUNCTION2_SELECT_1
#define Y_GUARD_FUNCTION2 Y_GUARD_FUNCTION2_SELECT_1


#endif // SX_CPP03_BOOST





#endif // include guard
