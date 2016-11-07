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

#include "behavior_fwd.hpp"
#include "constraint_fwd.hpp"


//!\brief Macro for using a class method as a behavior.
#define Y_BEHAVIOR_METHOD( _method_name ) \
		sxy::behavior_function( [ this ]( const sxy::event& _event ){ this->_method_name( _event ); } )


//!\brief Macro for using a class method as a behavior without an event.
#define Y_BEHAVIOR_METHOD_NO_EVENT( _method_name ) \
         sxy::behavior_function( [ this ]( const sxy::event& _event ){ Y_UNUSED_PARAMETER(_event); this->_method_name(); } )


//!\brief Macro for using a free function as a behavior.
#define Y_BEHAVIOR_FUNCTION( _function_name ) \
         sxy::behavior_function( []( const sxy::event& _event ){ _function_name( _event ); } )


//!\brief Macro for using a free function as a behavior without an event.
#define Y_BEHAVIOR_FUNCTION_NO_EVENT( _function_name ) \
         sxy::behavior_function( []( const sxy::event& _event ){ Y_UNUSED_PARAMETER(_event); _function_name(); } )


//!\brief Macro for using a class method as a guard.
#define Y_GUARD_METHOD( _method_name ) \
         sxy::constraint_function( [ this ]( const sxy::event& _event ){ return( this->_method_name( _event ) ); } )


//!\brief Macro for using a class method as a guard without an event.
#define Y_GUARD_METHOD_NO_EVENT( _method_name ) \
         sxy::constraint_function( [ this ]( const sxy::event& _event ){ Y_UNUSED_PARAMETER(_event); return( this->_method_name() ); } )


//!\brief Macro for using a free function as a guard.
#define Y_GUARD_FUNCTION( _function_name ) \
         sxy::constraint_function( []( const sxy::event& _event ){ return( _function_name( _event ) ); } )


//!\brief Macro for using a free function as a guard without an event.
#define Y_GUARD_FUNCTION_NO_EVENT( _function_name ) \
         sxy::constraint_function( []( const sxy::event& _event ){ Y_UNUSED_PARAMETER(_event); return( _function_name() ); } )


//!\brief Macro for an empty behavior.
#define Y_EMPTY_BEHAVIOR \
		sxy::behavior_function( [ ]( const sxy::event& _event ){ Y_UNUSED_PARAMETER(_event); } )


#endif
