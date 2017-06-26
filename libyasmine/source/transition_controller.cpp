//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_controller.hpp"

#include "essentials/conversion.hpp"
#include "hermes/log.hpp"
#include "hermes/log_and_throw.hpp"

#include "composite_state.hpp"
#include "transition_finder.hpp"
#include "transition_executor.hpp"
#include "event_impl.hpp"
#include "event_processing_callback.hpp"
#include "compound_transition_impl.hpp"
#include "behavior_exception.hpp"
#include "algorithm_parameters.hpp"
#include "completion_event.hpp"
#include "interruptible.hpp"


namespace sxy
{


	transition_controller::transition_controller()
	{
		// Nothing to do...
	}


	transition_controller::~transition_controller() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	bool transition_controller::process_event( const event& _event, const composite_state& _main_composite_state,
		event_processing_callback* const _event_processing_callback, bool& _event_is_deferred,
		async_event_handler* const _async_event_handler, event_collector& _event_collector,
		const interruptible& _interruptible, bool& _event_was_unhandled )
	{
		_event_was_unhandled = false;

		SX_LOG( hermes::log_level::LL_TRACE, "Begin processing event '%'.", _event.get_id() );
		bool reached_terminate_pseudostate = false;
		compound_transitions enabled_compound_transitions;
		enabled_compound_transitions.reserve( COMPOUND_TRANSITIONS_VECTOR_SIZE );
		SX_LOG( hermes::log_level::LL_SPAM, "Search for enabled transition(s) for event '%'.", _event.get_id() );
		transition_finder transition_finder;
		transition_finder.search_for_enabled_transitions_in_all_regions( _main_composite_state, _event,
			enabled_compound_transitions, _event_is_deferred, _event_collector );
		if( enabled_compound_transitions.empty() )
		{
			SX_LOG( hermes::log_level::LL_TRACE, "There are no compound transitions to execute for the event '%'.",
				_event.get_id() );
		}
		else
		{
			SX_LOG( hermes::log_level::LL_TRACE, "Found % enabled transition(s) for event '%'.",
				enabled_compound_transitions.size(), _event.get_id() );
			SX_LOG( hermes::log_level::LL_SPAM, "Start executing transition(s) for event '%'.", _event.get_id() );
			reached_terminate_pseudostate = execute_transitions( _main_composite_state, enabled_compound_transitions,
				_event_processing_callback, _event, _async_event_handler, _event_collector, _interruptible );
			_event_is_deferred = false;
			_event_was_unhandled = true;
		}

		SX_LOG( hermes::log_level::LL_TRACE, "End of processing event '%'.", _event.get_id() );
		return( reached_terminate_pseudostate );
	}


	bool transition_controller::start_state_machine( const composite_state& _main_composite_state,
		event_processing_callback* const _event_processing_callback, async_event_handler* const _async_event_handler,
		event_collector& _event_collector, const interruptible& _interruptible )
	{
		bool terminate_pseudostate_has_been_reached = false;
		compound_transitions enabled_compound_transitions;
		enabled_compound_transitions.reserve( ENABLED_COMPOUND_TRANSITION_VECTOR_SIZE );
		transition_finder transition_finder;
		SX_LOG( hermes::log_level::LL_TRACE, "Searching for initial transitions on state machine start." );
		transition_finder.search_initial_transitions( _main_composite_state, enabled_compound_transitions, _event_collector );
		if( enabled_compound_transitions.empty() )
		{
			SX_LOG( hermes::log_level::LL_TRACE, "No initial transitions found." );
		}
		else
		{
			SX_LOG( hermes::log_level::LL_TRACE, "Found % compound transition(s) after searching for initial transitions.",
				enabled_compound_transitions.size() );
			SX_LOG( hermes::log_level::LL_TRACE, "Executing transitions." );
			if( execute_transitions( _main_composite_state, enabled_compound_transitions, _event_processing_callback,
				*completion_event::create(), _async_event_handler, _event_collector, _interruptible ) )
			{
				SX_LOG( hermes::log_level::LL_DEBUG, "Terminate pseudostate has been reached." );
				terminate_pseudostate_has_been_reached = true;
			}
		}

		return( !terminate_pseudostate_has_been_reached );
	}


	bool transition_controller::execute_transitions( const composite_state& _main_composite_state,
		compound_transitions& compound_transitions, event_processing_callback* const _event_processing_callback,
		const event& _event, async_event_handler* const _async_event_handler, event_collector& _event_collector,
		const interruptible& _interruptible )
	{
		bool terminate_pseudostate_has_been_reached = false;
		transition_executor transition_executor;
		events exception_events;
		exception_events.reserve( EXCEPTION_EVENTS_VECTOR_SIZE );

		while( !compound_transitions.empty() && !_interruptible.is_interrupted() )
		{
			raw_const_choices choices;
			choices.reserve( CHOICES_VECTOR_SIZE );
			if( _event_processing_callback )
			{
				_event_processing_callback->before_event_processings_stage();
			}

			SX_LOG( hermes::log_level::LL_TRACE, "Check, sort and execute transitions." );
			terminate_pseudostate_has_been_reached = transition_executor.check_sort_and_execute_transitions(
				compound_transitions, choices, _event_processing_callback, _event, exception_events, _async_event_handler,
				_event_collector, _interruptible );
			if( terminate_pseudostate_has_been_reached )
			{
				SX_LOG( hermes::log_level::LL_DEBUG, "Terminate pseudostate has been reached." );
				break;
			}

			compound_transitions.clear();
			SX_LOG( hermes::log_level::LL_SPAM, "Search for choice transitions." );
			search_choice_transitions( choices, compound_transitions, _event, _event_collector );
			SX_LOG( hermes::log_level::LL_TRACE, "Found % transition(s) after searched for choice transitions.",
				compound_transitions.size() );

			if( compound_transitions.empty() )
			{
				if( !choices.empty() )
				{
					LOG_AND_THROW( hermes::log_level::LL_FATAL, "There are choices but no choice transitions!" );
				}

				while( !exception_events.empty() )
				{
					if( _event_processing_callback )
					{
						_event_processing_callback->after_event_processings_stage( choices );
					}

					handle_execution_events( exception_events, _event_processing_callback, _main_composite_state,
						compound_transitions, _async_event_handler, _event_collector, _interruptible );
				}

				SX_LOG( hermes::log_level::LL_TRACE, "Searching for completion event transitions." );
				search_completion_event_transitions( _main_composite_state, compound_transitions, _event_collector );
			}

			if( _event_processing_callback )
			{
				_event_processing_callback->after_event_processings_stage( choices );
			}
		}

		return( terminate_pseudostate_has_been_reached );
	}


	void transition_controller::handle_execution_events( events& _exception_events,
		event_processing_callback* const _event_processing_callback, const composite_state& _main_composite_state,
		compound_transitions& _compound_transitions, async_event_handler* const _async_event_handler,
		event_collector& _event_collector, const interruptible& _interruptible )
	{
		sxy::event_sptr error_event = _exception_events.front();
		transition_finder transition_finder;
		bool event_is_deferred = false;

		if( _event_processing_callback )
		{
			_event_processing_callback->before_event( error_event->get_id(), error_event->get_priority() );
		}

		transition_finder.search_for_enabled_transitions_in_all_regions( _main_composite_state, *error_event,
			_compound_transitions, event_is_deferred, _event_collector );
		execute_transitions( _main_composite_state, _compound_transitions, _event_processing_callback, *error_event,
			_async_event_handler, _event_collector, _interruptible );
		_exception_events.erase( _exception_events.begin(), _exception_events.begin() + 1 );


		if( _event_processing_callback )
		{
			_event_processing_callback->after_event( error_event->get_id() );
		}
	}


	void transition_controller::search_choice_transitions( const raw_const_choices& _choices,
		compound_transitions& compound_transitions, const event& _event, event_collector& _event_collector )
	{
		transition_finder transition_finder;
		transition_finder.search_choice_transitions( _choices, compound_transitions, _event, _event_collector );
	}


	void transition_controller::search_completion_event_transitions( const composite_state& _main_composite_state,
		compound_transitions& compound_transitions, event_collector& _event_collector )
	{
		bool event_is_deferred = false;
		transition_finder transition_finder;
		transition_finder.search_for_enabled_completion_transitions_in_all_regions( _main_composite_state,
			compound_transitions, event_is_deferred, _event_collector );
		SX_ASSERT( !event_is_deferred, "An completion transition was deferred!" );
	}


}
