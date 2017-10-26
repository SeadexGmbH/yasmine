//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_9D568568_F100_40E3_B02C_1141C218D7D8
#define TRANSITION_9D568568_F100_40E3_B02C_1141C218D7D8


#include "state_machine_element.hpp"

#include "transition_kind.hpp"
#include "event_id.hpp"
#include "transition_fwd.hpp"


namespace sxy
{


class vertex;
class constraint;
class behavior;
class event;
class event_collector;


class transition:
	public virtual state_machine_element
{
public:
	transition()		
	{
		// Nothing to do...
	}


	virtual ~transition() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(transition)
	virtual const vertex& get_source() const = 0;
	virtual const vertex& get_target() const = 0;
	virtual vertex& get_target() = 0;
	virtual const constraint * get_guard() const = 0;
	virtual const behavior * get_behavior() const = 0;
	virtual sxy::transition_kind get_kind() const = 0;
	virtual void on_transition_behavior( const event& _event, event_collector& _event_collector ) const = 0;
	virtual bool check_guard( const event& _event, event_collector& _event_collector ) const = 0;
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE = 0;
	virtual bool can_accept_event( const event_id _event ) const = 0;
};


}


#endif
