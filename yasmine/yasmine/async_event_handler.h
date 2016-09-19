//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_EVENT_HANDLER_314E2E70_50A4_442B_BE7C_E7F3FC77D71E
#define ASYNC_EVENT_HANDLER_314E2E70_50A4_442B_BE7C_E7F3FC77D71E

#include "event_fwd.h"


namespace sxy
{


class async_event_handler
{


public:
	async_event_handler() = default;	
	virtual ~async_event_handler() = default;
	async_event_handler( const async_event_handler& ) = delete;
	async_event_handler& operator=(	const async_event_handler& ) = delete;
	virtual void on_event( const event_sptr _event ) = 0;


};


}


#endif
