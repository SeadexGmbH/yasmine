//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_CONTROLLER_FDB88C02_ECF6_4BB5_B99A_3F45813BF357
#define TRANSITION_CONTROLLER_FDB88C02_ECF6_4BB5_B99A_3F45813BF357


#include "choice_fwd.h"
#include "compound_transition_fwd.h"
#include "event_id.h"
#include "behavior_exception_fwd.h"


namespace sxy
{


class event;
class composite_state;
class event_processing_callback;
class async_event_handler;


class transition_controller final
{
public:
	transition_controller();
	~transition_controller();
	transition_controller( const transition_controller& ) = delete;
	transition_controller& operator=( const transition_controller& ) = delete;
	static bool process_event( const event& _event, const composite_state& _main_composite_state,
		event_processing_callback* const _event_processing_callback, bool& _event_is_deferred, 
		async_event_handler* const _async_event_handler );
	static bool start_state_machine( const composite_state& _main_composite_state,
		event_processing_callback* const _event_processing_callback, async_event_handler* const _async_event_handler );


private:
	static bool execute_transitions( const composite_state& _main_composite_state,	
		compound_transitions& compound_transitions,	event_processing_callback* const _event_processing_callback,
		const event& _event, async_event_handler* const _async_event_handler );
	static void search_choice_transitions( const raw_const_choices& _choices, 
		compound_transitions& compound_transitions,	const event& _event );
	static void search_completion_event_transitions( const composite_state& _main_composite_state,
		compound_transitions& compound_transitions );
};


}


#endif
