//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_990555DD_B4D7_49E4_AC39_7448568164F0
#define EVENT_990555DD_B4D7_49E4_AC39_7448568164F0


#include "event_id.hpp"
#include "event_priority.hpp"
#include "event_fwd.hpp"
#include "non_copyable.hpp"


namespace sxy
{


class event
{
public:
	event()
	{
		// Nothing to do...
	}


	virtual ~event() Y_NOEXCEPT
	{
		// Nothing to do...
	}


	Y_NO_COPY(event)
	virtual event_id get_id() const = 0;
	virtual std::string get_name() const = 0;
	virtual event_priority get_priority() const = 0;	
	virtual bool operator>(const event& _rhs) const = 0;
};


}


#endif
