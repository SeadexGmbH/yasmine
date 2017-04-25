//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "guard_caller.hpp"


namespace sxy
{


// cppcheck-suppress unusedFunction
bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxe::function<bool()> _method )
{	
	SX_UNUSED_PARAMETER( _event );
	SX_UNUSED_PARAMETER( _event_collector );
	const bool enabled = _method();
	return( enabled );
}


bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxe::function<bool( sxy::event_collector& _event_collector )> _method )
{
	SX_UNUSED_PARAMETER( _event );
	const bool enabled = _method( _event_collector );
	return( enabled );
}


}
