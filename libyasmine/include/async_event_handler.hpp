//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_EVENT_HANDLER_314E2E70_50A4_442B_BE7C_E7F3FC77D71E
#define ASYNC_EVENT_HANDLER_314E2E70_50A4_442B_BE7C_E7F3FC77D71E

#include "event_fwd.hpp"


namespace sxy
{


class async_event_handler
{


public:
	async_event_handler()
	{
		// Nothing to do...
	}


	virtual ~async_event_handler() Y_NOEXCEPT
	{
		// Nothing to do...
	}


	Y_NO_COPY(async_event_handler)
	virtual void on_event( const event_sptr& _event ) = 0;


};


}


#endif
