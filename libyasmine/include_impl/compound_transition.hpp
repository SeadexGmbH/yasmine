//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOUND_TRANSITION_E7300B8C_33B4_4D4B_9093_A864A5ADA27C
#define COMPOUND_TRANSITION_E7300B8C_33B4_4D4B_9093_A864A5ADA27C


#include "compound_transition_consumer.hpp"
#include "compound_transition_fwd.hpp"
#include "transition_step_fwd.hpp"


namespace sxy
{


class vertex;
class region;
class transition;
class composite_state;
class event;
class event_collector;


class compound_transition:
	public virtual compound_transition_consumer
{
public:
	compound_transition()
	{
		// Nothing to do...
	}


	virtual ~compound_transition() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(compound_transition)
	virtual void add_sub_compound_transition( compound_transition_uptr _sub_compound_transition ) = 0;
	virtual bool check_if_starts_with( const transition& _incoming_transition ) = 0;
	virtual bool create_and_check_transition_path( transition& _start_transition, const event& _event, 
		event_collector& _event_collector ) = 0;
};


}


#endif
