//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_CONTROLLER_FDB88C02_ECF6_4BB5_B99A_3F45813BF357
#define TRANSITION_CONTROLLER_FDB88C02_ECF6_4BB5_B99A_3F45813BF357


#include "essentials/non_copyable.hpp"

#include "choice_fwd.hpp"
#include "compound_transition_fwd.hpp"
#include "event_id.hpp"
#include "behavior_exception_fwd.hpp"
#include "event_fwd.hpp"


namespace sxy
{


	class composite_state;
	class event_processing_callback;
	class async_event_handler;
	class event_collector;
	class interruptible;


	class transition_controller SX_FINAL
	{
	public:
		transition_controller();
		~transition_controller() SX_NOEXCEPT;
		SX_NO_COPY( transition_controller )
			static bool process_event( const event& _event, const composite_state& _main_composite_state,
				event_processing_callback* const _event_processing_callback, bool& _event_is_deferred,
				async_event_handler* const _async_event_handler, event_collector& _event_collector,
				const interruptible& _interruptible, bool& _event_was_unhandled );
		static bool start_state_machine( const composite_state& _main_composite_state,
			event_processing_callback* const _event_processing_callback, async_event_handler* const _async_event_handler,
			event_collector& _event_collector, const interruptible& _interruptible );


	private:
		static bool execute_transitions( const composite_state& _main_composite_state,
			compound_transitions& compound_transitions, event_processing_callback* const _event_processing_callback,
			const event& _event, async_event_handler* const _async_event_handler, event_collector& _event_collector,
			const interruptible& _interruptible );
		static void handle_execution_events( events& _exception_events, event_processing_callback* const _event_processing_callback,
			const composite_state& _main_composite_state, compound_transitions& _compound_transitions,
			async_event_handler* const _async_event_handler, event_collector& _event_collector,
			const interruptible& _interruptible );
		static void search_choice_transitions( const raw_const_choices& _choices,
			compound_transitions& compound_transitions, const event& _event, event_collector& _event_collector );
		static void search_completion_event_transitions( const composite_state& _main_composite_state,
			compound_transitions& compound_transitions, event_collector& _event_collector );
	};


}


#endif
