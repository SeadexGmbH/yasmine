//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_CREATION_REQUEST_05BAD27E_EBBD_405D_B23D_00670DF91241
#define EVENT_CREATION_REQUEST_05BAD27E_EBBD_405D_B23D_00670DF91241


#include <chrono>

#include "event_id.h"
#include "log.h"
#include "event_fwd.h"


namespace sxy
{


class event_creation_request final
{
public:
	event_creation_request(	const std::chrono::time_point< std::chrono::system_clock >& _time,	
		const event_sptr _event,	const int _handle );
	~event_creation_request();
	event_creation_request( const event_creation_request& ) = delete;
	event_creation_request& operator=( const event_creation_request& ) = delete;
	std::chrono::time_point< std::chrono::system_clock > get_time() const;
	int get_handle() const;
	event_sptr get_event() const;


private:
	std::chrono::time_point< std::chrono::system_clock > time_;
	const event_sptr event_;
	int handle_;
};


}


#endif
