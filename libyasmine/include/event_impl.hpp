//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_IMPL_447B2A6E_B2CC_4851_A3EB_68ACC838AEA2
#define EVENT_IMPL_447B2A6E_B2CC_4851_A3EB_68ACC838AEA2


#include "event.hpp"


namespace sxy
{

//!\class event_impl
//!\brief Events that are processed by the state machine. 
//! An event can have an ID, a name and a priority (for processing by the async state machine).
class event_impl:
	public event
{
public:
	explicit event_impl( const event_id _event_id, const event_priority _event_priority = DEFAULT_EVENT_PRIORITY );
	virtual ~event_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(event_impl)

	//!\brief Getter of event's ID.
	//!\return ID of event.
	virtual event_id get_id() const SX_OVERRIDE;

	//!\brief Getter of event's name.
	//!\return Name of event.
	virtual std::string get_name() const SX_OVERRIDE;

	//!\brief Getter of event's priority.
	//!\return Priority of event.
	virtual event_priority get_priority() const SX_OVERRIDE;
	
	//!\brief Method for comparing the priorities between the current event and a given event.
	//!\param _rhs Reference to an event whose priority is compared with the current event's priority.
	//!\return True if the current event has a greater priority, else false.
	virtual bool operator>(const event& _rhs) const SX_OVERRIDE;
	
	//!\brief Static method for creating an event with the given ID and a priority. 
	//!\Priority has DEFAULT_EVENT_PRIORITY as default value.
	//!\param _event_id ID of the event that is created.
	//!\param _event_priority Priority of the event that is created. DEFAULT_EVENT_PRIORITY is the default value.
	//!\return The created event.
	static event_sptr create( const event_id _event_id, const event_priority _event_priority = DEFAULT_EVENT_PRIORITY );


private:
	event_id event_id_;
	event_priority event_priority_;
};


}


#endif
