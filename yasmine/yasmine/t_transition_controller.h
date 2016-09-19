//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TRANSITION_CONTROLLER_FDB88C02_ECF6_4BB5_B99A_3F45813BF357
#define T_TRANSITION_CONTROLLER_FDB88C02_ECF6_4BB5_B99A_3F45813BF357


#include "i_choice_fwd.h"
#include "t_compound_transition_fwd.h"
#include "t_event_id.h"


namespace sxy
{


class i_event;
class i_composite_state;
class i_event_processing_callback;


class t_transition_controller	final
{
public:
	t_transition_controller
	(
	);


	~t_transition_controller
	(
	);


	t_transition_controller
	(
		const t_transition_controller&
	) = delete;


	t_transition_controller& operator=
	(
		const t_transition_controller&
	) = delete;


	static
	bool 
	process_event
	(			
		const i_event& p_event,
		const i_composite_state& p_main_composite_state,
		i_event_processing_callback* const p_event_processing_callback,
		bool& p_event_is_deferred
	);


	static
	bool
	start_state_machine
	(
		const i_composite_state& p_main_composite_state,
		i_event_processing_callback* const p_event_processing_callback
	);
					

private:
	static
	bool
	execute_transitions
	( 
		const i_composite_state& p_main_composite_state, 
		t_compound_transitions& compound_transitions,
		i_event_processing_callback* const p_event_processing_callback,
		const i_event& p_event
	);


	static
	void 
	search_choice_transitions
	( 
		const t_raw_const_choices& p_choices,
		t_compound_transitions& compound_transitions,
		const i_event& p_event
	);


	static
	void 
	search_completion_event_transitions
	( 
		const i_composite_state& p_main_composite_state,
		t_compound_transitions& compound_transitions		
	);


};


}


#endif
