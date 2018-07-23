//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASSEMBLY_CPP11_D1BFD81D_D2FD_4AD5_A426_CE822C4C6C9F
#define ASSEMBLY_CPP11_D1BFD81D_D2FD_4AD5_A426_CE822C4C6C9F

#ifndef SX_CPP03_BOOST // C++11 only


#include <type_traits>
#include "assembly_common.hpp"

#include "essentials/macro_helpers.hpp"


//!\brief Macro for using a method as a behavior.
#define Y_BEHAVIOR_ACTION( _action ) \
			sxy::behavior_function( [this]( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER( _event ); SX_UNUSED_PARAMETER( _event_collector ); _action } )

//!\brief Macro for using a free function as a behavior.
#define Y_BEHAVIOR_FREE_ACTION( _action ) \
			sxy::behavior_function( []( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER( _event ); SX_UNUSED_PARAMETER( _event_collector ); _action } )

//!\brief Macro for using a method as a guard.
#define Y_GUARD_ACTION( _action ) \
		sxy::constraint_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event); SX_UNUSED_PARAMETER( _event_collector ); _action } )

//!\brief Macro for using a free function as a guard.
#define Y_GUARD_FREE_ACTION( _action ) \
		sxy::constraint_function( []( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event); SX_UNUSED_PARAMETER( _event_collector ); _action } )


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



// deprecated macros

#if defined(Y_USE_DEPRECATED) && (Y_USE_DEPRECATED <= 1)

//!\deprecated Use Y_BEHAVIOR_METHOD2 instead.
#define Y_BEHAVIOR_METHOD( ... ) EXPAND( VA_SELECT( Y_BEHAVIOR_METHOD_SELECT, __VA_ARGS__ ) )

//!\deprecated Use Y_BEHAVIOR_METHOD2 instead.
#define Y_BEHAVIOR_METHOD_NO_EVENT( ... ) EXPAND( VA_SELECT( Y_BEHAVIOR_METHOD_NO_EVENT_SELECT, __VA_ARGS__ ) )

//!\deprecated Use Y_GUARD_METHOD2 instead.
#define Y_GUARD_METHOD( ... ) EXPAND( VA_SELECT( Y_GUARD_METHOD_SELECT, __VA_ARGS__ ) )

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
		sxy::constraint_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event_collector); return( this->_method_name( _event ) ); } )

//!\brief Macro for using a class method as a guard.
//!\deprecated USE Y_GUARD_METHOD2 instead.
#define Y_GUARD_METHOD_SELECT_2( _class_name, _method_name ) \
		sxy::constraint_function( [ this ]( const sxy::event& _event, sxy::event_collector& _event_collector ){ SX_UNUSED_PARAMETER(_event_collector); return( this->_method_name( _event ) ); } )

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
		sxy::constraint_function( []( const sxy::event& _event, sxy::event_collector& _event_collector )->bool { SX_UNUSED_PARAMETER(_event_collector); return( _function_name( _event ) ); } )

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


#endif // defined(Y_USE_DEPRECATED) && (Y_USE_DEPRECATED <= 1)


#endif // SX_CPP03_BOOST
 

#endif // include guard
