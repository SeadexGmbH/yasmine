//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_PROCESSING_CALLBACK_7D1528DE_08BA_4C56_90DF_290C3353040B
#define EVENT_PROCESSING_CALLBACK_7D1528DE_08BA_4C56_90DF_290C3353040B


#include "essentials/non_copyable.hpp"

#include "event_id.hpp"
#include "event_priority.hpp"
#include "state_fwd.hpp"
#include "choice_fwd.hpp"


namespace sxy
{


class state;
class transition;
class execution_step;
class choice;
class state_machine_introspection;

//!\interface event_processing_callback
//!\brief Callback interface that is called by a state machine during event processing. See the different methods to
//!find out which events can be monitored.
class event_processing_callback
{
public:
	event_processing_callback()
	{
		// Nothing to do...
	}


	virtual ~event_processing_callback() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY(event_processing_callback)

	//!\brief Adds a state machine introspection interface.
	//!\param _state_machine The state machine which is monitored.
	//!\return void
	virtual void add_state_machine_introspection( state_machine_introspection& _state_machine ) = 0;

	//!\brief Callback before an event is processed.
	//!\param _event_id ID of the event.
	//!\return void
	virtual void before_event( const event_id _event_id, const event_priority _event_priority = DEFAULT_EVENT_PRIORITY ) = 0;

	//!\brief Callback after an event is processed.
	//!\param _event_id ID of the event.
	//!\return void
	virtual void after_event( const event_id _event_id, const event_priority _event_priority = DEFAULT_EVENT_PRIORITY ) = 0;

	//!\brief Callback before a event execution stage.
	//!\return void
	virtual void before_event_processings_stage() = 0;

	//!\brief Callback after a event execution stage.
	//!\param _choices List of choices that need to be processed after the last execution stage.
	//!\return void
	virtual void after_event_processings_stage( const raw_const_choices& _choices ) = 0;

	//!\brief Callback before the processing of a compound transition.
	//!\return void
	virtual void before_compound_transition() = 0;

	//!\brief Callback after the processing of a compound transition.
	//!\return void
	virtual void after_compound_transition() = 0;

	//!\brief Callback before exiting a state.
	//!\param _state State that will be exited.
	//!\return void
	virtual void before_exit( const state& _state ) = 0;

	//!\brief Callback after exiting a state.
	//!\param _state State that was exited.
	//!\return void
	virtual void after_exit( const state& _state ) = 0;

	//!\brief Callback before entering a state.
	//!\param _state State that will be entered.
	//!\return void.
	virtual void before_enter( const state& _state ) = 0;

	//!\brief Callback after entering a state.
	//!\param _state State that was entered.
	//!\return void
	virtual void after_enter( const state& _state ) = 0;

	//!\brief Callback before execution of a state behavior ("do behavior").
	//!\param _state State whose behavior will be executed.
	//!\return void
	virtual void before_do( const state& _state ) = 0;

	//!\brief Callback after execution of a state behavior ("do behavior").
	//!\param _state State whose behavior was executed.
	//!\return void
	virtual void after_do( const state& _state ) = 0;

	//!\brief Callback before execution of a transition behavior.
	//!\param _transition Transition whose behavior will be executed.
	//!\return void
	virtual void before_transition( const transition& _transition ) = 0;

	//!\brief Callback after execution of a transition behavior.
	//!\param _transition Transition whose behavior was executed.
	//!\return void
	virtual void after_transition( const transition& _transition ) = 0;
};


}


#endif
