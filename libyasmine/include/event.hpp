//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_990555DD_B4D7_49E4_AC39_7448568164F0
#define EVENT_990555DD_B4D7_49E4_AC39_7448568164F0


#include "essentials/non_copyable.hpp"

#include "event_id.hpp"
#include "event_priority.hpp"
#include "event_fwd.hpp"


namespace sxy
{

//!\interface event
//!\brief Interface of an event. An event has an ID, a name and a priority (for processing by the async state machine).
class event
{
public:
	event()
	{
		// Nothing to do...
	}


	virtual ~event() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY(event)

	//!\brief Getter of event's ID.
	//!\return ID of event.
	virtual event_id get_id() const = 0;

	//!\brief Getter of event's name.
	//!\return Name of event.
	virtual std::string get_name() const = 0;

	//!\brief Getter of event's priority.
	//!\return Priority of event.
	virtual event_priority get_priority() const = 0;	

	//!\brief Method for comparing the priorities between the current event and a given event.
	//!\param _rhs Reference to an event whose priority is compared with the current event's priority.
	//!\return True if the current event has a greater priority, else false.
	virtual bool operator>(const event& _rhs) const = 0;
};


}


#endif
