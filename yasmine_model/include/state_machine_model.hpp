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
#include "essentials/compatibility/compatibility.hpp"

#include "state_machine_model_fwd.hpp"
#include "transition_model_fwd.hpp"
#include "composite_state_model_fwd.hpp"
#include "event_model.hpp"
#include "state_machine_external_element.hpp"
#include "state_machine_element_model_impl.hpp"


namespace sxy
{


namespace model
{


class state_machine_element_model;


//!\class state_machine_model
//!\brief Class representing a model of a complete state machine.
class state_machine_model
{
public:
	typedef std::vector< event_sptr > events;

	state_machine_model();
	~state_machine_model() SX_NOEXCEPT;
	SX_NO_COPY( state_machine_model )

	//!\brief Add a transition to the state machine.
	void add_transition( transition_model_uptr _transition );

	//!\brief Remove transition with the given index from state machine.
	void remove_transition( const size_t _index );

	//!\brief Get a list of transitions.
	//!\return List of transitions.
	raw_const_transition_models get_transitions() const;

	//!\brief Get the transition with the given index.
	//!\param _index The index of requested transition.
	//!\return Requested transition.
	transition_model& get_transition( const size_t _index );

	//!\brief Get a reference to the root state of the state machine.
	//!\return Root state of the state machine.
	composite_state_model_impl& get_root_state() const;

	//!\brief Add the root state to the state machine.
	void add_root_state( composite_state_model_uptr _root_state );

	//!\brief Get a list of events that was read from a JSON file. These events are the events used in this state machine.
	events get_events() const;

	//!\brief Get the event with the given index.
	event_model& get_event( const size_t _index );

	//!\brief Get the event with the given index.
	const event_model& get_event( const size_t _index ) const;

	//!\brief Get name of the event with the given ID.
	std::string get_event_name( const sxy::model::event_id& _event_id ) const;

	//!\brief Add an event to the list of events.
	//!\param _event_name Name of the event.
	//!\param _event_id ID of the event.
	void add_event( const std::string& _event_name, const event_id& _event_id, const event_priority& _event_priority );

	//!\brief Remove an event from the list of events.
	//!\param _index Index of the event to be deleted.
	void remove_event( const size_t _index );

	//!\brief Get a list of elements that have a reference to the given event.
	//!\param _event Event for which referencing elements are searched.
	//!\return List of elements that are referencing the given event.
	std::vector<sxy::model::state_machine_element_model*> get_event_references( const event_sptr _event );

	//!\brief Get a list of elements that are not part of this state machine, but of another state machine.
	// These elements can be used as source or target for transitions.
	const external_vertices& get_externals() const;

	//!\brief Get a list of elements that are not part of this state machine, but of another state machine.
	external_vertices& get_externals();

	//!\brief Add a new external vertex.
	//!\param _external_vertex The vertex that is added to the list of external vertices.
	void add_external_vertex( external_uptr _external_vertex );

	//!\brief Remove an element from the list of external vertices.
	//!\param _index Index of the element to be deleted.
	void remove_external_vertex( const size_t _index );


private:
	transition_models transitions_;
	composite_state_model_uptr root_state_;
	events event_list_;
	external_vertices externals_;
};


}


}


#endif
