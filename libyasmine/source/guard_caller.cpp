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


bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool()>& _function )
{
	SX_UNUSED_PARAMETER( _event );
	SX_UNUSED_PARAMETER( _event_collector );
	const bool enabled = _function();
	return( enabled );
}


bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool( sxy::event_collector& _event_collector )>& _function )
{
	SX_UNUSED_PARAMETER( _event );
	const bool enabled = _function( _event_collector );
	return( enabled );
}


}
