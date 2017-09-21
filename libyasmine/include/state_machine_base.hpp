//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_MACHINE_BASE_484EA235_EEDE_4C19_9C46_C0687D950A13
#define STATE_MACHINE_BASE_484EA235_EEDE_4C19_9C46_C0687D950A13


#include "essentials/compatibility/thread.hpp"

#include "state_machine_introspection.hpp"
#include "event_collector.hpp"
#include "interruptible.hpp"
#include "transition_kind.hpp"
#include "constraint_fwd.hpp"
#include "behavior_fwd.hpp"
#include "transition_fwd.hpp"
#include "composite_state_fwd.hpp"
#include "region_fwd.hpp"
#include "event_id.hpp"
#include "state_machine_defect_fwd.hpp"


namespace sxy
{


	class vertex;
	class async_event_handler;
	class event_processing_callback;
	class uri;
	class region;


	//!\class state_machine
	//!\brief Base class for the state machines. It provides methods to start the state machine, to fire events, 
	//!to add transitions, to check the state machine for possible defects and to get the root state reference.
	class state_machine_base :
		private state_machine_introspection, public event_collector, private interruptible
	{
	public:
		//!\brief Constructor
		//!\param _name Name of the state machine.
		//!\param _event_processing_callback Event processing callback interface pointer. It can be a nullptr if no callback
		//!interface should be used.
		explicit state_machine_base( const std::string& _name,
			event_processing_callback* const _event_processing_callback = SX_NULLPTR );
		virtual ~state_machine_base() SX_NOEXCEPT SX_OVERRIDE;
		SX_NO_COPY( state_machine_base )

			//!\brief Returns the root state of the state machine. Commonly used to add regions to the root state and to create transitions
			//!from and to the root state.
			//!\return Reference to the root state of the state machine.
			composite_state& get_root_state() const;

#ifdef Y_PROFILER
		sxe::uint32_t get_number_of_processed_events() const;
#endif

		//!\brief Add a transition to the state machine. The state machine takes ownership of the transition.
		//!\param _transition A transition.
		//!\return transition Reference to the added transition.
		virtual transition& add_transition( transition_uptr _transition );

		//!\brief Creates a transition with the given name, kind, event, guard and behavior between the given source and
		//! target and adds it to the state machine.
		//!\param _event_id ID of the event for which the transition is enabled.
		//!\param _source The source vertex.
		//!\param _target The target vertex.
		//!\param _kind Transition kind. Default is EXTERNAL.
		//!\param _guard The guard of the transition. Default is an empty function.
		//!\param _behavior The behavior of the transition. Default is an empty function.
		//!\return A reference to the newly created transition.
		virtual transition& add_transition( const event_id _event_id, vertex& _source, vertex& _target,
			const sxy::transition_kind _kind = transition_kind::EXTERNAL,
			const constraint_function& _guard = constraint_function(),
			const behavior_function& _behavior = behavior_function() );

		//!\brief Creates a transition with the given name, kind, event, guard and behavior between the given source and
		//! target and adds it to the state machine.
		//!\param event_ids List of IDs of the events for which the transition is enabled.
		//!\param _source The source vertex.
		//!\param _target The target vertex.
		//!\param _kind Transition kind. Default is EXTERNAL.
		//!\param _guard The guard of the transition. Default is an empty function.
		//!\param _behavior The behavior of the transition. Default is an empty function.
		//!\return A reference to the newly created transition.
		virtual transition& add_transition( const event_ids& _event_ids, vertex& _source, vertex& _target,
			const sxy::transition_kind _kind = transition_kind::EXTERNAL,
			const constraint_function& _guard = constraint_function(),
			const behavior_function& _behavior = behavior_function() );

		//!\brief Creates a transition with the given name, kind, event, guard between the given source and
		//! target and adds it to the state machine. No behavior is provided.
		//!\param _event_id ID of the event for which the transition is enabled.
		//!\param _source The source vertex.
		//!\param _target The target vertex.
		//!\param _guard The guard of the transition.
		//!\param _kind Transition kind. Default is EXTERNAL.
		//!\return A reference to the newly created transition.
		virtual transition& add_transition( const event_id _event_id, vertex& _source, vertex& _target,
			const constraint_function& _guard, const sxy::transition_kind _kind = transition_kind::EXTERNAL );

		//!\brief Creates a transition with the given name, kind, events, guard between the given source and
		//! target and adds it to the state machine. No behavior is provided.
		//!\param _event_ids IDs of the events for which the transition is enabled.
		//!\param _source The source vertex.
		//!\param _target The target vertex.
		//!\param _guard The guard of the transition.
		//!\param _kind Transition kind. Default is EXTERNAL.
		//!\return A reference to the newly created transition.
		virtual transition& add_transition( const event_ids& _event_ids, vertex& _source, vertex& _target,
			const constraint_function& _guard, const sxy::transition_kind _kind = transition_kind::EXTERNAL );

		//!\brief Creates a transition with the given name, kind, event, guard and behavior between the given source and
		//! target and adds it to the state machine.
		//!\param _event_id ID of the event for which the transition is enabled.
		//!\param _source The source vertex.
		//!\param _target The target vertex.
		//!\param _guard The guard of the transition.
		//!\param _behavior The behavior of the transition.
		//!\param _kind Transition kind. Default is EXTERNAL.
		//!\return A reference to the newly created transition.
		virtual transition& add_transition( const event_id _event_id, vertex& _source, vertex& _target,
			const constraint_function& _guard, const behavior_function& _behavior,
			const sxy::transition_kind _kind = transition_kind::EXTERNAL );

		//!\brief Creates a transition with the given name, kind, events, guard and behavior between the given source and
		//! target and adds it to the state machine.
		//!\param _event_ids IDs of the events for which the transition is enabled.
		//!\param _source The source vertex.
		//!\param _target The target vertex.
		//!\param _guard The guard of the transition.
		//!\param _behavior The behavior of the transition.
		//!\param _kind Transition kind. Default is EXTERNAL.
		//!\return A reference to the newly created transition.
		virtual transition& add_transition( const event_ids& _event_ids, vertex& _source, vertex& _target,
			const constraint_function& _guard, const behavior_function& _behavior,
			const sxy::transition_kind _kind = transition_kind::EXTERNAL );

		//!\brief Creates a transition with the given name, kind, event and behavior between the given source and
		//! target and adds it to the state machine. No guard is provided.
		//!\param _event_id ID of the event for which the transition is enabled.
		//!\param _source The source vertex.
		//!\param _target The target vertex.
		//!\param _behavior The behavior of the transition.
		//!\param _kind Transition kind. Default is EXTERNAL.
		//!\return A reference to the newly created transition.
		virtual transition& add_transition( const event_id _event_id, vertex& _source, vertex& _target,
			const behavior_function& _behavior, const sxy::transition_kind _kind = transition_kind::EXTERNAL );

		//!\brief Creates a transition with the given name, kind, events and behavior between the given source and
		//! target and adds it to the state machine. No guard is provided.
		//!\param _event_ids IDs of the events for which the transition is enabled.
		//!\param _source The source vertex.
		//!\param _target The target vertex.
		//!\param _behavior The behavior of the transition.
		//!\param _kind Transition kind. Default is EXTERNAL.
		//!\return A reference to the newly created transition.
		virtual transition& add_transition( const event_ids& _event_ids, vertex& _source, vertex& _target,
			const behavior_function& _behavior, const sxy::transition_kind _kind = transition_kind::EXTERNAL );

		virtual bool fire_event( const event_sptr& _event ) = 0;

		//!\brief Check the state machine for defects by checking the constraints of each component.
		//!\param _defects Collected for all found defects.
		//!\return bool true if there are no defects, else false.
		bool check( state_machine_defects& _defects ) const;

		virtual bool run() = 0;

		//!\brief Stops the state machine. It checks for active asynchronous simple states and stops their do behaviors.
		virtual void halt();

		//!\brief Set the internal flag of the state machine, to interrupt all processes inside the state machine and 
		//!to stop the state machine.
		virtual void interrupt();

		//!\brief Get the internal flag of the state machine that specify if the run of state machine is interrupted.
		//!\return true if the internal flag is set to interrupt the state machine, false otherwise.
		//!\sa interrupt
		virtual bool is_interrupted() const SX_OVERRIDE;

		//!\brief Sets the behavior for handler of unhandled events.
		//!\param _behavior
		virtual void set_behavior_of_unhandled_event_handler( const behavior_function& _behavior );

		//!\brief Get the name of the state machine.
		//!\return name of the state machine
		virtual std::string get_name() const;


	protected:
		//!\brief Starts the state machine.
		//!\param _async_event_handler Pointer to an asynchronous event handler. It's used by
		//!the asynchronous state machine if it has to process asynchronous errors that occur in the 
		//!asynchronous behavior of asynchronous simple states.
		//!\return bool true if state machine can be started, else false what means that a terminate pseudostate has been
		//!reached and the state machine is stopped.
		bool run( async_event_handler* const _async_event_handler );
		bool process_event( const event_sptr& _event, async_event_handler* const _async_event_handler );
		static void stop_all_async_states( state& _state );


	private:
		virtual const events& get_deferred_events() const SX_OVERRIDE;
	public:
		virtual raw_const_states get_active_state_configuration() const SX_OVERRIDE;
	private:
		void get_active_states_from_region( raw_const_states& _active_state_configuration, const region& _region ) const;
		void check_regions_for_active_states( raw_const_states& _active_state_configuration, const state& _state ) const;
		void add_deferred_event( const event_sptr& _event_id );
		bool process_deferred_events( async_event_handler* const _async_event_handler );
		static void stop_all_async_states_from_region( region_uptr& _region );
		virtual void interrupt_impl();
		void handle_unhandled_event( const event_sptr& _event );

		const std::string name_;
		event_processing_callback* event_processing_callback_;
		composite_state_uptr root_state_;
		transitions transitions_;
		events deferred_events_;
		sxe::atomic<bool> state_machine_is_running_;
		sxe::atomic<bool> interrupt_;
#ifdef Y_PROFILER
		sxe::uint32_t processed_events_;
#endif
		behavior_uptr event_handler_behavior_;

	};


}


#endif
