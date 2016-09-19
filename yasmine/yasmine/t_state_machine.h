//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_STATE_MACHINE_0DD08953_1A90_4992_A22E_118A42B1E45A
#define T_STATE_MACHINE_0DD08953_1A90_4992_A22E_118A42B1E45A


#include <string>

#include "t_state_machine_defects.h"
#include "i_transition_fwd.h"
#include "i_composite_state_fwd.h"
#include "t_state_machine_defects_fwd.h"
#include "i_vertex_fwd.h"
#include "i_state_machine_introspection.h"

#include "i_event_fwd.h"
#include "t_event_id.h"
#include "t_transition_kind.h"
#include "i_behavior_fwd.h"
#include "i_constraint_fwd.h"


namespace sxy
{


class i_event_processing_callback;
class i_event;
class t_uri;
class i_region;


//!\class t_state_machine
//!\brief Class for the "single-threaded version" of the state machine. It provides the methods to start the state machine, to fire events, to check the state machine for possible defects and to get the root state reference.
class t_state_machine: private i_state_machine_introspection
{
public:
	//!\brief Constructor of t_state_machine.
	//!\param p_name Name of the state machine.
	//!\param p_event_processing_callback Event processing callback interface pointer. It can be a nullptr if no callback interface should be used.
	explicit t_state_machine
	(
		const std::string& p_name,
		i_event_processing_callback* const p_event_processing_callback = nullptr
	);

	
	virtual
	~t_state_machine
	(
	) override;


	t_state_machine
	(
		const t_state_machine&
	) = delete;


	t_state_machine& operator=
	(
		const t_state_machine&
	) = delete;


	//!\brief Returns the root state of the state machine. Commonly used to add regions to the root state.
	//!\return Reference to the root state of the state machine.
	i_composite_state&
	get_root_state
	(
	) const;


	//!\brief Add a transition to the state machine. The state machine takes ownership of the transition.
	//!\param p_transition A transition.
	//!\return transition Reference to the added transition.
	virtual i_transition&
	add_transition
	(
		i_transition_uptr p_transition
	);


	//!\brief Creates a transition with the given name, kind, event, guard and behavior between the given source and target and adds it to the state machine given as parameter.
	//!\param p_transition_name Name of the transition.	
	//!\param p_event_id ID of the event for which the transition will be enabled.
	//!\param p_source  The source vertex.
	//!\param p_target The target vertex.
	//!\param p_kind Transition kind. Default is EXTERNAL.
	//!\param p_guard The guard of the transition. Default is an empty function.
	//!\param p_behavior The behavior of the transition. Default is an empty function.
	//!\return a reference to the new created transition.
	virtual i_transition&
	add_transition
	(
		const std::string& p_transition_name,
		const t_event_id p_event_id,
		i_vertex& p_source,
		i_vertex& p_target,
		const sxy::t_transition_kind p_kind = t_transition_kind::EXTERNAL,
		const t_constraint_function& p_guard = t_constraint_function(),
		const t_behavior_function& p_behavior = t_behavior_function()
	);


	//!\brief Creates a transition with the given name, kind, event, guard and behavior between the given source and target and adds it to the state machine given as parameter.
	//!\param p_transition_name Name of the transition.	
	//!\param p_event_ids IDs of the events for which the transition will be enabled.
	//!\param p_source The source vertex.
	//!\param p_target The target vertex.
	//!\param p_kind Transition kind.	Default is EXTERNAL.
	//!\param p_guard The guard of the transition. Default is an empty function.
	//!\param p_behavior The behavior of the transition. Default is an empty function.
	//!\return a reference to the new created transition.
	virtual i_transition&
	add_transition
	(
		const std::string& p_transition_name,
		const t_event_ids p_event_ids,
		i_vertex& p_source,
		i_vertex& p_target,
		const sxy::t_transition_kind p_kind = sxy::t_transition_kind::EXTERNAL,
		const t_constraint_function& p_guard = t_constraint_function(),
		const t_behavior_function& p_behavior = t_behavior_function()
	);


	//!\brief Fire the given event.
	//!\param p_event Event to be fired.
	//!\return true if event was successfully fired, else false what means that a terminate pseudostate has been reached, the state machine was stopped and no
	// further events can be fired.
	virtual bool
	fire_event
	(
		const t_event_sptr& p_event
	);


	//!\brief Check the state machine for defects by checking the constraints of each component.
	//!\param p_defects Collected for all found defects.
	//!\return bool true if there are no defects, else false.
	bool
	check
	(
		t_state_machine_defects& p_defects
	) const;


	//!\brief Starts the state machine.
	//!\return bool true if state machine can be started, else false what means that a terminate pseudostate has been reached and the state machine is stopped.
	bool
	start_state_machine
	(	
	);


protected:
	bool
	process_event
	(
		const t_event_sptr& p_event
	);
	

private:	
	virtual const t_events&
	get_deferred_events
	(
	) const override;


	virtual t_raw_const_states
	get_active_state_configuration
	(
	) const override;


	void
	get_active_states_from_region
	(
		t_raw_const_states& p_active_state_configuration,
		const i_region& p_region
	) const;


	void
	check_regions_for_active_states
	(
		t_raw_const_states& p_active_state_configuration,
		const i_state& p_state
	) const;


	void
	add_deferred_event
	(
		const t_event_sptr& p_event_id
	);


	bool
	process_deferred_events
	(
	);
	
	
	t_raw_const_transitions m_outgoing_transitions;
	t_raw_const_transitions m_incoming_transitions;
															 
	const std::string m_name;
	i_event_processing_callback* m_event_processing_callback;
	i_composite_state_uptr m_root_state;
	t_transitions m_transitions;
	t_events m_deferred_events;
	bool m_state_machine_is_running;
	
};


}


#endif
