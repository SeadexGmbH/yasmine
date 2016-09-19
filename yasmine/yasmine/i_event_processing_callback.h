//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_EVENT_PROCESSING_CALLBACK_7D1528DE_08BA_4C56_90DF_290C3353040B
#define I_EVENT_PROCESSING_CALLBACK_7D1528DE_08BA_4C56_90DF_290C3353040B


#include "t_event_id.h"
#include "i_state_fwd.h"
#include "i_choice_fwd.h"


namespace sxy
{


class i_state;
class i_transition;
class i_execution_step;
class i_choice;
class i_state_machine_introspection;


//!\interface i_event_processing_callback
//!\brief Callback interface that is called by a state machine during event processing. See the different methods to find out
//!\brief which events can be monitored.
class i_event_processing_callback
{
public:
	i_event_processing_callback
	(
	) = default;


	virtual
	~i_event_processing_callback
	(
	) = default;


	i_event_processing_callback
	(
		const i_event_processing_callback&
	) = delete;


	i_event_processing_callback&
	operator=
	(
		const i_event_processing_callback&
	) = delete;


	//!\brief Adds a state machine introspection interface.
	//!\param	p_state_machine The state machine which will be monitored.
	//!\return void
	virtual void
	add_state_machine_introspection
	(
		i_state_machine_introspection& p_state_machine
	) = 0;


	//!\brief Callback before an event is processed.
	//!\param p_event_id ID of the event.
	//!\return void
	virtual void
	before_event
	(
		const t_event_id p_event_id
	) = 0;


	//!\brief Callback after an event is processed.
	//!\param p_event_id ID of the event.
	//!\return void
	virtual void
	after_event
	(
		const t_event_id p_event_id
	) = 0;


	//!\brief Callback before a event execution stage.	
	//!\return void
	virtual void
	before_event_processings_stage
	(			
	) = 0;


	//!\brief Callback after a event execution stage.	
	//!\param p_choices List of choices that need to be processed after the last execution stage.
	//!\return void
	virtual void
	after_event_processings_stage
	(	
		const t_raw_const_choices& p_choices
	) = 0;


	//!\brief Callback before the processing of a compound transition.	
	//!\return void
	virtual void
	before_compound_transition
	(
	) = 0;

	//!\brief Callback after the processing of a compound transition.	
	//!\return void
	virtual void
	after_compound_transition
	(
	) = 0;


	//!\brief Callback before exiting a state.
	//!\param p_state State that will be exited.
	//!\return void
	virtual void
	before_exit
	(
		const i_state& p_state
	) = 0;


	//!\brief Callback after exiting a state.
	//!\param p_state State that was exited.
	//!\return void
	virtual void
	after_exit
	(
		const i_state& p_state
	) = 0;


	//!\brief Callback before entering a state.
	//!\param p_state State that will be entered.
	//!\return void.
	virtual void
	before_enter
	(
		const i_state& p_state
	) = 0;


	//!\brief Callback after entering a state.
	//!\param p_state State that was entered.
	//!\return void
	virtual void
	after_enter
	(
		const i_state& p_state
	) = 0;


	//!\brief Callback before execution of a state behavior ("do behavior").
	//!\param p_state State whose behavior will be executed.
	//!\return void
	virtual void
	before_do
	(
		const i_state& p_state
	) = 0;


	//!\brief Callback after execution of a state behavior ("do behavior").
	//!\param p_state State whose behavior was executed.
	//!\return void
	virtual void
	after_do
	(
		const i_state& p_state
	) = 0;
	

	//!\brief Callback before execution of a transition behavior.
	//!\param p_transition Transition whose behavior will be executed.
	//!\return void
	virtual void
	before_transition
	(
		const i_transition& p_transition
	) = 0;


	//!\brief Callback after execution of a transition behavior.
	//!\param p_transition Transition whose behavior was executed.
	//!\return void
	virtual void
	after_transition
	(
		const i_transition& p_transition
	) = 0;


};


}


#endif
