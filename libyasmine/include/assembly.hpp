//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASSEMBLY_07A0176B_5967_4CDB_B7CF_624220170138
#define ASSEMBLY_07A0176B_5967_4CDB_B7CF_624220170138

#ifndef SX_CPP03_BOOST
	#include <type_traits>
#endif

#include "essentials/macro_helpers.hpp"

#include "behavior_fwd.hpp"
#include "constraint_fwd.hpp"
#include "caller.hpp"
#include "guard_caller.hpp"
										 

#ifndef SX_CPP03_BOOST
		

//!\deprecated Use Y_BEHAVIOR_METHOD2 instead.
#define Y_BEHAVIOR_METHOD( ... ) EXPAND( VA_SELECT( Y_BEHAVIOR_METHOD_SELECT, __VA_ARGS__ ) )

//!\brief Macro for using any type of action as a behavior.
#define Y_BEHAVIOR_ACTION( ... ) EXPAND( VA_SELECT( Y_BEHAVIOR_ACTION_SELECT, __VA_ARGS__ ) )

//!\deprecated Use Y_BEHAVIOR_METHOD2 instead.
#define Y_BEHAVIOR_METHOD_NO_EVENT( ... ) EXPAND( VA_SELECT( Y_BEHAVIOR_METHOD_NO_EVENT_SELECT, __VA_ARGS__ ) )

//!\deprecated Use Y_GUARD_METHOD2 instead.
#define Y_GUARD_METHOD( ... ) EXPAND( VA_SELECT( Y_GUARD_METHOD_SELECT, __VA_ARGS__ ) )

//!\brief Macro for using any type of action returning bool as a guard.
#define Y_GUARD_ACTION( ... ) EXPAND( VA_SELECT( Y_GUARD_ACTION_SELECT, __VA_ARGS__ ) )

//!\deprecated Use Y_GUARD_METHOD2 instead.
#define Y_GUARD_METHOD_NO_EVENT( ... ) EXPAND( VA_SELECT( Y_GUARD_METHOD_NO_EVENT_SELECT, __VA_ARGS__ ) )


//!\brief Macro for using a class method as a behavior.
//!\deprecated Use Y_BEHAVIOR_METHOD2 instead.
#define Y_BEHAVIOR_METHOD_SELECT_1( _method_name ) \
		sxy::behavior_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event_collector); this->_method_name( _event ); } )

//!\brief Macro for using a class method as a behavior.
//!\deprecated Use Y_BEHAVIOR_METHOD2 instead.
#define Y_BEHAVIOR_METHOD_SELECT_2( _class_name, _method_name ) \
		sxy::behavior_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){  SX_UNUSED_PARAMETER(_event_collector); this->_method_name( _event ); } )

//!\brief Macro for using any type of action as a behavior.
#define Y_BEHAVIOR_ACTION_SELECT_1( _action ) \
		sxy::behavior_function( [ this ]( const sxy::event& _event ){ SX_UNUSED_PARAMETER(_event); _action } )

//!\brief Macro for using any type of action as a behavior.
#define Y_BEHAVIOR_ACTION_SELECT_2( _class_name, _action ) \
		sxy::behavior_function( [ this ]( const sxy::event& _event ){ SX_UNUSED_PARAMETER(_event); _action } )

//!\brief Macro for using a class method as a behavior without an event.
//!\deprecated Use Y_BEHAVIOR_METHOD2 instead.
#define Y_BEHAVIOR_METHOD_NO_EVENT_SELECT_1( _method_name ) \
    sxy::behavior_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event); SX_UNUSED_PARAMETER(_event_collector); this->_method_name(); } )

//!\brief Macro for using a class method as a behavior without an event.
//!\deprecated Use Y_BEHAVIOR_METHOD2 instead.
#define Y_BEHAVIOR_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name ) \
		sxy::behavior_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event); SX_UNUSED_PARAMETER(_event_collector); this->_method_name(); } )

//!\brief Macro for using a class method as a guard.
//!\deprecated USE Y_GUARD_METHOD2 instead.
#define Y_GUARD_METHOD_SELECT_1( _method_name ) \
    sxy::constraint_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ return(  SX_UNUSED_PARAMETER(_event_collector); this->_method_name( _event ) ); } )

//!\brief Macro for using a class method as a guard.
//!\deprecated USE Y_GUARD_METHOD2 instead.
#define Y_GUARD_METHOD_SELECT_2( _class_name, _method_name ) \
    sxy::constraint_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ return(  SX_UNUSED_PARAMETER(_event_collector); this->_method_name( _event ) ); } )

//!\brief Macro for using any type of action returning bool as a guard.
#define Y_GUARD_ACTION_SELECT_1( _action ) \
    sxy::constraint_function( [ this ]( const sxy::event& _event ){ SX_UNUSED_PARAMETER(_event); _action } )

//!\brief Macro for using any type of action returning bool as a guard.
#define Y_GUARD_ACTION_SELECT_2( _class_name, _action ) \
    sxy::constraint_function( [ this ]( const sxy::event& _event ){ SX_UNUSED_PARAMETER(_event); _action } )

//!\brief Macro for using a class method as a guard without an event.
//!\deprecated Use Y_GUARD_METHOD2 instead.
#define Y_GUARD_METHOD_NO_EVENT_SELECT_1( _method_name ) \
    sxy::constraint_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event); SX_UNUSED_PARAMETER(_event_collector); return( this->_method_name() ); } )

//!\brief Macro for using a class method as a guard without an event.
//!\deprecated Use Y_GUARD_METHOD2 instead.
#define Y_GUARD_METHOD_NO_EVENT_SELECT_2( _class_name, _method_name ) \
    sxy::constraint_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event); SX_UNUSED_PARAMETER(_event_collector); return( this->_method_name() ); } )

//!\brief Macro for using a free function as a guard.
//!\deprecated Use Y_GUARD_FUNCTION2 instead.
#define Y_GUARD_FUNCTION( _function_name ) \
    sxy::constraint_function( []( const sxy::event& _event, sxy::event_collector& _event_collector )->bool { return( SX_UNUSED_PARAMETER(_event_collector); _function_name( _event ) ); } )

//!\brief Macro for using a free function as a guard without an event.
//!\deprecated Use Y_GUARD_FUNCTION2 instead.
#define Y_GUARD_FUNCTION_NO_EVENT( _function_name ) \
    sxy::constraint_function( []( const sxy::event& _event, sxy::event_collector& _event_collector )->bool { SX_UNUSED_PARAMETER(_event); SX_UNUSED_PARAMETER(_event_collector); return( _function_name() ); } )

//!\brief Macro for using a free function as a behavior.
//!\deprecated Use Y_BEHAVIOR_FUNCTION2 instead.
#define Y_BEHAVIOR_FUNCTION( _function_name ) \
	sxy::behavior_function( []( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event_collector); _function_name( _event ); } )

//!\brief Macro for using a free function as a behavior without an event.
//!\deprecated Use Y_BEHAVIOR_FUNCTION2 instead.
#define Y_BEHAVIOR_FUNCTION_NO_EVENT( _function_name ) \
	sxy::behavior_function( []( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event); SX_UNUSED_PARAMETER(_event_collector); _function_name(); } )\


#else


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


#endif


//!\brief Macro for an empty behavior.
#define Y_EMPTY_BEHAVIOR sxy::behavior_function()


//!\brief Macro for an empty guard.
#define Y_EMPTY_GUARD sxy::constraint_function()


#ifndef SX_CPP03_BOOST // C++11 only
	// Macros for passing handlers as behavior	
	
	//!\brief The macro creates a behavior_function for the specified method(s).
	//!\ The macro is variadic and can take up to 10 class methods pointers as parameters.
	//#define Y_BEHAVIOR_METHOD_EVENT(...) EXPAND( VA_SELECT( Y_BEHAVIOR_METHOD_EVENT_SELECT, __VA_ARGS__ ) )
	#define Y_BEHAVIOR_METHOD_EVENT(...) EXPAND( Y_BEHAVIOR_METHOD2( this, __VA_ARGS__ ) )
		
	//!\brief The macro creates a behavior_function for the specified function(s). 
	//!\ The macro is variadic and can take up to 10 function pointers as parameters.
	#define Y_BEHAVIOR_FUNCTION_EVENT( ... ) EXPAND( Y_BEHAVIOR_FUNCTION2( __VA_ARGS__ ) )


#define VA_SELECT_WITH_CLASS_INSTANCE( NAME, CLASS_INSTANCE, ... ) EXPAND( SELECT( NAME, VA_SIZE(__VA_ARGS__) )(CLASS_INSTANCE, __VA_ARGS__) )

//!\brief The macro creates a behavior_function for the specified method(s).
//!\ The macro is variadic and can take up to 10 class methods pointers as parameters.
#define Y_BEHAVIOR_METHOD2(CLASS_INSTANCE, ...) EXPAND( VA_SELECT_WITH_CLASS_INSTANCE(Y_BEHAVIOR_METHOD2_SELECT, CLASS_INSTANCE, __VA_ARGS__))

//!\brief The macro creates a behavior_function for the specified function(s).
//!\ The macro is variadic and can take up to 10 function pointers as parameters.
#define Y_BEHAVIOR_FUNCTION2(...) EXPAND( VA_SELECT(Y_BEHAVIOR_FUNCTION2_SELECT, __VA_ARGS__) )

//!\brief The macro creates a behavior_function for the specified method(s).
//!\ The macro is variadic and can take up to 10 class methods pointers as parameters.
#define Y_GUARD_METHOD2(CLASS_INSTANCE, ...) EXPAND( VA_SELECT_WITH_CLASS_INSTANCE(Y_GUARD_METHOD2_SELECT, CLASS_INSTANCE, __VA_ARGS__))

//!\brief The macro creates a guard_function for the specified function(s).
//!\ The macro is variadic and can take up to 10 function pointers as parameters.
#define Y_GUARD_FUNCTION2(...) EXPAND( VA_SELECT(Y_GUARD_FUNCTION2_SELECT, __VA_ARGS__) )

//!\brief The macro creates a constraint_function for the specified method(s).
//!\ The macro is variadic and can take up to 10 method pointers as parameters.
//#define Y_GUARD_METHOD_EVENT(...) EXPAND( VA_SELECT( Y_GUARDR_METHOD_EVENT_SELECT, __VA_ARGS__ ) )
#define Y_GUARD_METHOD_EVENT(...) EXPAND( Y_GUARD_METHOD2( this, __VA_ARGS__ ) )

//!\brief The macro creates a constraint_function for the specified function(s). 
//!\ The macro is variadic and can take up to 10 function pointers as parameters.
#define Y_GUARD_FUNCTION_EVENT( ... ) EXPAND( VA_SELECT( Y_GUARD_FUNCTION_EVENT_SELECT, __VA_ARGS__ ) )


template< typename ... Args >
sxy::behavior_function create_behavior_function( Args...args )
{
	return ( sxy::behavior_function( [ args... ]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, args... ); } ) );
}


template< typename ... Args >
sxy::constraint_function create_guard_function( Args...args )
{
	return ( sxy::constraint_function( [args...]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, args... ) ); } ) );
}

	#define Y_BEHAVIOR_METHOD2_SELECT_1( _class_instance, _method ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_2( _class_instance, _method1, _method2 ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_3( _class_instance, _method1, _method2, _method3 ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_4( _class_instance, _method1, _method2, _method3, _method4 ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_5( _class_instance, _method1, _method2, _method3, _method4, _method5 ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_6( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6 ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_7( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6, _method7 ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method7 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_8( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8 ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method7 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method8 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_9( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9 ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method7 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method8 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method9 ) )
	#define Y_BEHAVIOR_METHOD2_SELECT_10( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9, _method10 ) create_behavior_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method7 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method8 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method9 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method10 ) )

	#define Y_GUARD_METHOD2_SELECT_1( _class_instance, _method ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method ) )
	#define Y_GUARD_METHOD2_SELECT_2( _class_instance, _method1, _method2 ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ) )
	#define Y_GUARD_METHOD2_SELECT_3( _class_instance, _method1, _method2, _method3 ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ) )
	#define Y_GUARD_METHOD2_SELECT_4( _class_instance, _method1, _method2, _method3, _method4 ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ) )
	#define Y_GUARD_METHOD2_SELECT_5( _class_instance, _method1, _method2, _method3, _method4, _method5 ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ) )
	#define Y_GUARD_METHOD2_SELECT_6( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6 ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ) )
	#define Y_GUARD_METHOD2_SELECT_7( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6, _method7 ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method7 ) )
	#define Y_GUARD_METHOD2_SELECT_8( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8 ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method7 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method8 ) )
	#define Y_GUARD_METHOD2_SELECT_9( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9 ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method7 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method8 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method9 ) )
	#define Y_GUARD_METHOD2_SELECT_10( _class_instance, _method1, _method2, _method3, _method4, _method5, _method6, _method7, _method8, _method9, _method10 ) create_guard_function( adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method1 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method2 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method3 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method4 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method5 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method6 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method7 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method8 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method9 ), adapt<std::remove_pointer<decltype(_class_instance)>::type>( _class_instance, _method10 ) )
	
	#define Y_BEHAVIOR_FUNCTION2_SELECT_1( _function ) create_behavior_function( adapt_function( _function ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_2( _function1, _function2 ) create_behavior_function( adapt_function( _function1 ), adapt_function( _function2 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_3( _function1, _function2, _function3 ) create_behavior_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_4( _function1, _function2, _function3, _function4 ) create_behavior_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_5( _function1, _function2, _function3, _function4, _function5 ) create_behavior_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_6( _function1, _function2, _function3, _function4, _function5, _function6 ) create_behavior_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_7( _function1, _function2, _function3, _function4, _function5, _function6, _function7 ) create_behavior_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ), adapt_function( _function7 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_8( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ) create_behavior_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ), adapt_function( _function7 ), adapt_function( _function8 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_9( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ) create_behavior_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ), adapt_function( _function7 ), adapt_function( _function8 ), adapt_function( _function9 ) )
	#define Y_BEHAVIOR_FUNCTION2_SELECT_10( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ) create_behavior_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ), adapt_function( _function7 ), adapt_function( _function8 ), adapt_function( _function9 ), adapt_function( _function10 ) )

	#define Y_GUARD_FUNCTION2_SELECT_1( _function ) create_guard_function( adapt_function( _function ) )
	#define Y_GUARD_FUNCTION2_SELECT_2( _function1, _function2 ) create_guard_function( adapt_function( _function1 ), adapt_function( _function2 ) )
	#define Y_GUARD_FUNCTION2_SELECT_3( _function1, _function2, _function3 ) create_guard_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ) )
	#define Y_GUARD_FUNCTION2_SELECT_4( _function1, _function2, _function3, _function4 ) create_guard_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ) )
	#define Y_GUARD_FUNCTION2_SELECT_5( _function1, _function2, _function3, _function4, _function5 ) create_guard_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ) )
	#define Y_GUARD_FUNCTION2_SELECT_6( _function1, _function2, _function3, _function4, _function5, _function6 ) create_guard_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ) )
	#define Y_GUARD_FUNCTION2_SELECT_7( _function1, _function2, _function3, _function4, _function5, _function6, _function7 ) create_guard_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ), adapt_function( _function7 ) )
	#define Y_GUARD_FUNCTION2_SELECT_8( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ) create_guard_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ), adapt_function( _function7 ), adapt_function( _function8 ) )
	#define Y_GUARD_FUNCTION2_SELECT_9( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ) create_guard_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ), adapt_function( _function7 ), adapt_function( _function8 ), adapt_function( _function9 ) )
	#define Y_GUARD_FUNCTION2_SELECT_10( _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ) create_guard_function( adapt_function( _function1 ), adapt_function( _function2 ), adapt_function( _function3 ), adapt_function( _function4 ), adapt_function( _function5 ), adapt_function( _function6 ), adapt_function( _function7 ), adapt_function( _function8 ), adapt_function( _function9 ), adapt_function( _function10 ) )


#endif

#endif
