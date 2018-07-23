//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "create_guard_function.hpp"

#include "guard_caller.hpp"


namespace sxy
{


#ifdef SX_CPP03_BOOST // C++03 with Boost


// cppcheck-suppress unusedFunction
sxy::constraint_function create_guard_function( const sxe::function<bool()>& _function )
{
	typedef bool ( *guard_caller_selector )( const sxy::event& _event, sxy::event_collector& _event_collector, const sxe::function<bool()>& );
	return( sxy::constraint_function( sxe::bind( static_cast<guard_caller_selector>( guard_caller ), sxe::_1, sxe::_2, _function ) ) );
}


sxy::constraint_function create_guard_function( const sxe::function<bool( sxy::event_collector& )>& _function )
{
	typedef bool( *guard_caller_selector )( const sxy::event& _event, sxy::event_collector& _event_collector, const sxe::function<bool( sxy::event_collector& )>& );
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function ) ) );
}


#else


// cppcheck-suppress unusedFunction
void dummy_to_silence_linker_warning_in_create_guard_function()
{
	// Nothing to do...
}


#endif


}
