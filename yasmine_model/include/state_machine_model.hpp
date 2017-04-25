//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_MACHINE_MODEL_3F3E9321_9E31_4FE6_AC87_B084AF84F17A
#define STATE_MACHINE_MODEL_3F3E9321_9E31_4FE6_AC87_B084AF84F17A

#include <vector>

#include "essentials/non_copyable.hpp"

#include "transition_model_fwd.hpp"
#include "composite_state_model_fwd.hpp"
#include "event_model.hpp"


namespace sxy
{


namespace model
{


//!\class state_machine_model
//!\brief Class representing a model of a complete state machine.
class state_machine_model
{
public:
	typedef std::vector< event_model > events;

	state_machine_model();
	~state_machine_model() SX_NOEXCEPT;
	SX_NO_COPY( state_machine_model )

	//!\brief Add a transition to the state machine.
	void add_transition( transition_model_uptr _transition );

	//!\brief Get a list of transitions.
	//!\return List of transitions.
	raw_const_transition_models get_transitions() const;

	//!\brief Get a reference to the root state of the state machine.
	//!\reference Reference to the root state of the state machine.
	composite_state_model_impl& get_root_state() const;

	//!\brief Add the root state to the state machine.
	void add_root_state( composite_state_model_uptr _root_state );

	//!\brief Get a list of events that was read from JSON file. This events are the events used in this state machine's scenario.
	events get_events() const;
	
	//!\brief Add an event to the list of the events.
	//!\param _event_name Name of the event.
	//!\param _event_id Id of the event.
	void add_event( const std::string& _event_name, const event_id& _event_id, const event_priority& _event_priority );


private:
	transition_models transitions_;
	composite_state_model_uptr root_state_;
	events event_list_;
};


}


}


#endif
