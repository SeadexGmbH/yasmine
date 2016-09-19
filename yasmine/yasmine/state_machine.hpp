//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_MACHINE_0DD08953_1A90_4992_A22E_118A42B1E45A
#define STATE_MACHINE_0DD08953_1A90_4992_A22E_118A42B1E45A


#include <string>


#include "state_machine_introspection.hpp"
#include "composite_state.hpp"
#include "transition_kind.hpp"
#include "constraint_fwd.hpp"
#include "behavior_fwd.hpp"


namespace sxy
{


class event_processing_callback;
class uri;
class region;

//!\class state_machine
//!\brief Class for the "single-threaded version" of the state machine. It provides the methods to start the state
//!machine, to fire events, to check the state machine for possible defects and to get the root state reference.
class state_machine:
	private state_machine_introspection
{
public:
	//!\brief Constructor of state_machine.
	//!\param _name Name of the state machine.
	//!\param _event_processing_callback Event processing callback interface pointer. It can be a nullptr if no callback
	//!interface should be used.
	explicit state_machine( const std::string& _name,
		event_processing_callback* const _event_processing_callback = nullptr );
	virtual ~state_machine() noexcept override;
	state_machine( const state_machine& ) = delete;
	state_machine& operator=( const state_machine& ) = delete;

	//!\brief Returns the root state of the state machine. Commonly used to add regions to the root state.
	//!\return Reference to the root state of the state machine.
	composite_state& get_root_state() const;

	//!\brief Add a transition to the state machine. The state machine takes ownership of the transition.
	//!\param _transition A transition.
	//!\return transition Reference to the added transition.
	virtual transition& add_transition( transition_uptr _transition );

	//!\brief Creates a transition with the given name, kind, event, guard and behavior between the given source and
	// target and adds it to the state machine given as parameter.
	//!\param _event_id ID of the event for which the transition will be enabled.
	//!\param _source The source vertex.
	//!\param _target The target vertex.
	//!\param _kind Transition kind. Default is EXTERNAL.
	//!\param _guard The guard of the transition. Default is an empty function.
	//!\param _behavior The behavior of the transition. Default is an empty function.
	//!\return a reference to the new created transition.
	virtual transition& add_transition(	const event_id _event_id, vertex& _source,	vertex& _target,	
		const sxy::transition_kind _kind = transition_kind::EXTERNAL,
		const constraint_function& _guard = constraint_function(),	
		const behavior_function& _behavior = behavior_function() );

	//!\brief Creates a transition with the given name, kind, event, guard and behavior between the given source and
	// target and adds it to the state machine given as parameter.	
	//!\param event_ids List of IDs of the events for which the transition will be enabled.
	//!\param _source The source vertex.
	//!\param _target The target vertex.
	//!\param _kind Transition kind. Default is EXTERNAL.
	//!\param _guard The guard of the transition. Default is an empty function.
	//!\param _behavior The behavior of the transition. Default is an empty function.
	//!\return a reference to the new created transition.
	virtual transition& add_transition( const event_ids _event_ids,	vertex& _source, vertex& _target, 
		const sxy::transition_kind _kind = transition_kind::EXTERNAL,	
		const constraint_function& _guard = constraint_function(),
		const behavior_function& _behavior = behavior_function() );

	//!\brief Creates a transition with the given name, kind, event, guard between the given source and
	// target and adds it to the state machine given as parameter. There is no behavior provided.	
	//!\param _event_id ID of the event for which the transition will be enabled.
	//!\param _source The source vertex.
	//!\param _target The target vertex.
	//!\param _guard The guard of the transition.
	//!\param _kind Transition kind. Default is EXTERNAL.
	//!\return a reference to the new created transition.
	virtual transition& add_transition( const event_id _event_id, vertex& _source, vertex& _target, 
		const constraint_function& _guard, const sxy::transition_kind _kind = transition_kind::EXTERNAL );

	//!\brief Creates a transition with the given name, kind, event, guard and behavior between the given source and
	// target and adds it to the state machine given as parameter.	
	//!\param _event_id ID of the event for which the transition will be enabled.
	//!\param _source The source vertex.
	//!\param _target The target vertex.	
	//!\param _guard The guard of the transition.
	//!\param _behavior The behavior of the transition.
	//!\param _kind Transition kind. Default is EXTERNAL.
	//!\return a reference to the new created transition.
	virtual transition& add_transition( const event_id _event_id,	vertex& _source, vertex& _target, 
		const constraint_function& _guard, const behavior_function& _behavior,	
		const sxy::transition_kind _kind = transition_kind::EXTERNAL );

	//!\brief Creates a transition with the given name, kind, event and behavior between the given source and
	// target and adds it to the state machine given as parameter. There is no guard provided.	
	//!\param _event_id ID of the event for which the transition will be enabled.
	//!\param _source The source vertex.
	//!\param _target The target vertex.
	//!\param _behavior The behavior of the transition.
	//!\param _kind Transition kind. Default is EXTERNAL.
	//!\return a reference to the new created transition.
	virtual transition& add_transition( const event_id _event_id, vertex& _source, vertex& _target, 
		const behavior_function& _behavior,	const sxy::transition_kind _kind = transition_kind::EXTERNAL );
	
	//!\brief Fire the given event.
	//!\param _event Event to be fired.	
	//!\return true if event was successfully fired, else false what means that a terminate pseudostate has been reached,
	//!the state machine was stopped and no further events can be fired.
	virtual bool fire_event( const event_sptr& _event );

	//!\brief Check the state machine for defects by checking the constraints of each component.
	//!\param _defects Collected for all found defects.
	//!\return bool true if there are no defects, else false.
	bool check( state_machine_defects& _defects ) const;	

	//!\brief Starts the state machine.	
	//!\return bool true if state machine can be started, else false what means that a terminate pseudostate has been
	//!reached and the state machine is stopped.
	virtual bool start_state_machine();

	//!\brief Stops the state machine. It checks for active asynchronous simple states and stops their do behaviors.
	virtual void stop_state_machine();


protected:
	std::string get_name() const;

	//!\brief Starts the state machine.
	//!\param _async_event_handler Pointer to an asynchronous event handler. For example, it's necessary for
	//!the asynchronous state machine if it is needed to process the asynchronous errors that occurs in the 
	//!asynchronous behavior of asynchronous simple states.
	//!\return bool true if state machine can be started, else false what means that a terminate pseudostate has been
	//!reached and the state machine is stopped.
	bool start_state_machine( async_event_handler* const _async_event_handler );
	bool process_event( const event_sptr& _event, async_event_handler* const _async_event_handler );
	static void stop_all_async_states( state& _state );


private:
	virtual const events& get_deferred_events() const override;	
	virtual raw_const_states get_active_state_configuration() const override;
	void get_active_states_from_region(	raw_const_states& _active_state_configuration, const region& _region ) const;
	void check_regions_for_active_states(	raw_const_states& _active_state_configuration, const state& _state ) const;
	void add_deferred_event( const event_sptr& _event_id );	
	bool process_deferred_events( async_event_handler* const _async_event_handler );
	static void stop_all_async_states_from_region( region_uptr& _region );
		
	const std::string name_;
	event_processing_callback* event_processing_callback_;
	composite_state_uptr root_state_;
	transitions transitions_;
	events deferred_events_;
	bool state_machine_is_running_;
};


}


#endif
