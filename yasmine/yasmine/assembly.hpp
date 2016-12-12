//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASSEMBLY_07A0176B_5967_4CDB_B7CF_624220170138
#define ASSEMBLY_07A0176B_5967_4CDB_B7CF_624220170138


#include "macro_helpers.hpp"
#include "behavior_fwd.hpp"
#include "constraint_fwd.hpp"
#include "caller.hpp"
										 

#ifndef Y_CPP03_BOOST


#define Y_BEHAVIOR_METHOD( ... ) EXPAND( VA_SELECT( Y_BEHAVIOR_METHOD_SELECT, __VA_ARGS__ ) )
#define Y_BEHAVIOR_METHOD_NO_EVENT( ... ) EXPAND( VA_SELECT( Y_BEHAVIOR_METHOD_NO_EVENT_SELECT, __VA_ARGS__ ) )
#define Y_GUARD_METHOD( ... ) EXPAND( VA_SELECT( Y_GUARD_METHOD_SELECT, __VA_ARGS__ ) )
#define Y_GUARD_METHOD_NO_EVENT( ... ) EXPAND( VA_SELECT( Y_GUARD_METHOD_NO_EVENT_SELECT, __VA_ARGS__ ) )


#else

#define Y_BEHAVIOR_METHOD( _class_name, _method_name ) Y_BEHAVIOR_METHOD_SELECT_2( _class_name, _method_name )
#define Y_BEHAVIOR_METHOD_NO_EVENT( _class_name, _method_name ) Y_BEHAVIOR_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name )
#define Y_GUARD_METHOD( _class_name, _method_name ) Y_GUARD_METHOD_SELECT_2( _class_name, _method_name )
#define Y_GUARD_METHOD_NO_EVENT( _class_name, _method_name ) Y_GUARD_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name )

#endif


//!\brief Macro for using a class method as a behavior.
#define Y_BEHAVIOR_METHOD_SELECT_2( _class_name, _method_name ) \
		sxy::behavior_function( sxy::bind( &_class_name::_method_name, this, sxy::_1 ) )

//!\brief Macro for using a class method as a behavior without an event.
#define Y_BEHAVIOR_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name ) \
		sxy::behavior_function( sxy::bind( &_class_name::_method_name, this ) )         

#define Y_GUARD_METHOD_SELECT_2( _class_name, _method_name ) \
    sxy::constraint_function( sxy::bind( &_class_name::_method_name, this, sxy::_1 ) )

//!\brief Macro for using a class method as a guard without an event.
#define Y_GUARD_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name ) \
    sxy::constraint_function( sxy::bind (&_class_name::_method_name, this ) )

//!\brief Macro for using a free function as a guard.
#define Y_GUARD_FUNCTION( _function_name ) \
    sxy::constraint_function( sxy::bind( &_function_name, sxy::_1 ) )


//!\brief Macro for using a free function as a guard without an event.
#define Y_GUARD_FUNCTION_NO_EVENT( _function_name ) \
    sxy::constraint_function( sxy::bind( &_function_name ) )


//!\brief Macro for using a free function as a behavior.
#define Y_BEHAVIOR_FUNCTION( _function_name ) \
		sxy::behavior_function( sxy::bind( &_function_name, sxy::_1 ) )


//!\brief Macro for using a free function as a behavior without an event.
#define Y_BEHAVIOR_FUNCTION_NO_EVENT( _function_name ) \
    sxy::behavior_function( sxy::bind( &_function_name ) )


#ifndef Y_CPP03_BOOST

//!\brief Macro for using a class method as a behavior.
#define Y_BEHAVIOR_METHOD_SELECT_1( _method_name ) \
		sxy::behavior_function( [ this ]( const sxy::event& _event ){ this->_method_name( _event ); } )


//!\brief Macro for using a class method as a behavior without an event.
#define Y_BEHAVIOR_METHOD_NO_EVENT_SELECT_1( _method_name ) \
    sxy::behavior_function( [ this ]( const sxy::event& _event ){ Y_UNUSED_PARAMETER(_event); this->_method_name(); } )


//!\brief Macro for using a class method as a guard.
#define Y_GUARD_METHOD_SELECT_1( _method_name ) \
    sxy::constraint_function( [ this ]( const sxy::event& _event ){ return( this->_method_name( _event ) ); } )


//!\brief Macro for using a class method as a guard without an event.
#define Y_GUARD_METHOD_NO_EVENT_SELECT_1( _method_name ) \
    sxy::constraint_function( [ this ]( const sxy::event& _event ){ Y_UNUSED_PARAMETER(_event); return( this->_method_name() ); } )

#endif		


//!\brief Macro for an empty behavior.
#define Y_EMPTY_BEHAVIOR sxy::behavior_function()


#ifndef Y_CPP03_BOOST // C++11 only
	// Macros for passing handlers as behavior

	//!\ The macro adds the specified class method(s) as behavior(s) to states or transitions. 
	//!\ The macro is variadic and can take up to 5 class methods pointers as parameters.
	#define Y_BEHAVIOR_METHOD_EVENT(...) EXPAND( VA_SELECT( Y_BEHAVIOR_METHOD_EVENT_SELECT, __VA_ARGS__ ) )

	//!\ The macro adds the specified function(s) as behavior(s) to states or transitions. 
	//!\ The macro is variadic and can take up to 5 function pointers as parameters.
	#define Y_BEHAVIOR_FUNCTION_EVENT( ... ) EXPAND( VA_SELECT( Y_BEHAVIOR_FUNCTION_EVENT_SELECT, __VA_ARGS__ ) )

	#define Y_BEHAVIOR_METHOD_EVENT_SELECT_1( _method ) sxy::behavior_function( [this]( const sxy::event& _event ) { method_caller( _event, this, _method ); } )
	#define Y_BEHAVIOR_METHOD_EVENT_SELECT_2( _method1, _method2 ) sxy::behavior_function( [this]( const sxy::event& _event ) { method_caller( _event, this, _method1, _method2 ); } )
	#define Y_BEHAVIOR_METHOD_EVENT_SELECT_3( _method1, _method2, _method3 ) sxy::behavior_function( [this]( const sxy::event& _event ) { method_caller( _event, this, _method1, _method2, _method3 ); } )
	#define Y_BEHAVIOR_METHOD_EVENT_SELECT_4( _method1, _method2, _method3, _method4 ) sxy::behavior_function( [this]( const sxy::event& _event ) { method_caller( event, this, _method1, _method2, _method3, _method4 ); } )
	#define Y_BEHAVIOR_METHOD_EVENT_SELECT_5( _method1, _method2, _method3, _method4, _method5 ) sxy::behavior_function( [this]( const sxy::event& _event ) { method_caller( _event, this, _method1, _method2, _method3, _method4, _method5 ); } )


	#define Y_BEHAVIOR_FUNCTION_EVENT_SELECT_1( _function) sxy::behavior_function( []( const sxy::event& _event ) { function_caller( _event, _function ); })
	#define Y_BEHAVIOR_FUNCTION_EVENT_SELECT_2( _function1, _function2 ) sxy::behavior_function( [](const sxy::event& _event ) { function_caller( _event, _function1, _function2 ); } )
	#define Y_BEHAVIOR_FUNCTION_EVENT_SELECT_3( _function1, _function2, _function3 ) sxy::behavior_function( [](const sxy::event& _event ) { function_caller( _event, _function1, _function2, _function3 ); } )
	#define Y_BEHAVIOR_FUNCTION_EVENT_SELECT_4( _function1, _function2, _function3, _function4 ) sxy::behavior_function( []( const sxy::event& _event ) { function_caller( _event, _function1, _function2, _function3, _function4 ); } )
	#define Y_BEHAVIOR_FUNCTION_EVENT_SELECT_5( _function1, _function2, _function3, _function4, _function5 ) sxy::behavior_function( []( const sxy::event& _event ) { function_caller( _event, _function1, _function2, _function3, _function4, _function5 ); } )

#endif

#endif
