//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "create_behavior_function.hpp"

#include "essentials/compatibility/compatibility.hpp"

#include "behavior_caller.hpp"


namespace sxy
{


#ifdef SX_CPP03_BOOST // C++03 with Boost


// cppcheck-suppress unusedFunction
sxy::behavior_function create_behavior_function( const sxe::function<void ()>& _function )
{
	typedef void ( *behavior_caller_selector )( const sxy::event& _event, sxy::event_collector& _event_collector, const sxe::function<void()>& );
	return( sxy::behavior_function( sxe::bind( static_cast<behavior_caller_selector>( sxy::behavior_caller ), sxe::_1, sxe::_2, _function ) ) );
}


sxy::behavior_function create_behavior_function( const sxe::function<void( sxy::event_collector& )>& _function )
{
	typedef void( *behavior_caller_selector )( const sxy::event& _event, sxy::event_collector& _event_collector, const sxe::function<void( sxy::event_collector& )>& );
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( sxy::behavior_caller ), sxe::_1, sxe::_2, _function ) ) );
}


#else


// cppcheck-suppress unusedFunction
void dummy_to_silence_linker_warning_in_create_behavior_function()
{
	// Nothing to do...
}


#endif


}
