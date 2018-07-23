//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_COLLECTOR_B423B8BB_DC7E_4957_95F5_2B5ECB9DD689
#define EVENT_COLLECTOR_B423B8BB_DC7E_4957_95F5_2B5ECB9DD689


#include "essentials/non_copyable.hpp"

#include "event.hpp"


namespace sxy
{


class event_collector
{
public:
	event_collector()
	{
		// Nothing to do...
	}

	virtual ~event_collector() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY( event_collector )
	virtual bool push( const event_sptr& _event ) = 0;


};


}


#endif
