//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "behavior_caller.hpp"


namespace sxy
{


void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void()>& _function )
{
	SX_UNUSED_PARAMETER( _event );
	SX_UNUSED_PARAMETER( _event_collector );
	_function();
}


void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void( event_collector& )>& _function )
{
	SX_UNUSED_PARAMETER( _event );
	_function( _event_collector );
}


}
