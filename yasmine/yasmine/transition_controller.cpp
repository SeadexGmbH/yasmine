//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_controller.h"

#include "log.h"
#include "composite_state.h"
#include "transition_finder.h"
#include "transition_executor.h"
#include "event_impl.h"
#include "event_processing_callback.h"
#include "compound_transition_impl.h"
#include "log_and_throw.h"
#include "behavior_exception.h"
#include "conversion.h"


namespace sxy
{


transition_controller::transition_controller() = default;


transition_controller::~transition_controller() = default;


bool transition_controller::process_event( const event& _event, const composite_state& _main_composite_state,
	event_processing_callback* const _event_processing_callback,	bool& _event_is_deferred, 
	async_event_handler* const _async_event_handler )
{
	Y_LOG( sxy::log_level::LL_INFO, "Processing event '%'.", _event.get_id() );
	auto reached_terminate_pseudostate = false;
	compound_transitions enabled_compound_transitions;
	Y_LOG( log_level::LL_SPAM, "Search for enabled transition(s) for event '%'.", _event.get_id() );
	transition_finder transition_finder;
	transition_finder.search_for_enabled_transitions_in_all_regions( _main_composite_state, _event,
		enabled_compound_transitions, _event_is_deferred );
	if( enabled_compound_transitions.empty() )
	{
		Y_LOG( sxy::log_level::LL_TRACE, "There are no compound transition to execute for the event '%'.",
			_event.get_id() );
	}
	else
	{
		Y_LOG( log_level::LL_TRACE, "Found % enabled transition(s) for event '%'.",
			enabled_compound_transitions.size(), _event.get_id() );
		Y_LOG( log_level::LL_SPAM,  "Start executing transition(s) for event '%'.", _event.get_id() );
		reached_terminate_pseudostate = execute_transitions( _main_composite_state, enabled_compound_transitions,
			_event_processing_callback, _event, _async_event_handler );
		_event_is_deferred = false;
	}

	Y_LOG( sxy::log_level::LL_INFO, "Processed event '%'.", _event.get_id() );
	return( reached_terminate_pseudostate );
}


bool transition_controller::start_state_machine( const composite_state& _main_composite_state,
	event_processing_callback* const _event_processing_callback, async_event_handler* const _async_event_handler )
{
	auto terminate_pseudostate_has_been_reached = false;
	compound_transitions enabled_compound_transitions;
	transition_finder transition_finder;
	Y_LOG( log_level::LL_TRACE, "Searching for initial transitions." );
	transition_finder.search_initial_transitions( _main_composite_state, enabled_compound_transitions );
	if( enabled_compound_transitions.empty() )
	{
		Y_LOG( sxy::log_level::LL_TRACE, "No initial transitions found." );
	}
	else
	{
		Y_LOG( log_level::LL_TRACE, "Found % compound transition(s) after searching for initial transitions.",
			enabled_compound_transitions.size() );
		event_impl event( COMPLETION_EVENT );
		Y_LOG( log_level::LL_TRACE, "Executing transitions." );
		if( execute_transitions( _main_composite_state, enabled_compound_transitions, _event_processing_callback,
					event, _async_event_handler ) )
		{
			Y_LOG( log_level::LL_INFO, "Terminate pseudostate has been reached." );
			terminate_pseudostate_has_been_reached = true;
		}
	}

	return( terminate_pseudostate_has_been_reached );
}


bool transition_controller::execute_transitions( const composite_state& _main_composite_state,
	compound_transitions& compound_transitions,	event_processing_callback* const _event_processing_callback,	
	const event& _event, async_event_handler* const _async_event_handler )
{
	auto terminate_pseudostate_has_been_reached = false;
	transition_executor transition_executor;
	behavior_exceptions behavior_exceptions = {};

	while( !compound_transitions.empty() )
	{
		raw_const_choices choices;
		if( _event_processing_callback )
		{
			_event_processing_callback->before_event_processings_stage();
		}

		Y_LOG( log_level::LL_TRACE, "Check sort and execute transitions." );		
		terminate_pseudostate_has_been_reached = transition_executor.check_sort_and_execute_transitions(
			compound_transitions, choices, _event_processing_callback, _event, behavior_exceptions, _async_event_handler );
		if( terminate_pseudostate_has_been_reached )
		{
			Y_LOG( log_level::LL_INFO, "Terminate pseudostate has been reached. The execution is stopping." );
			break;
		}

		compound_transitions.clear();
		Y_LOG( log_level::LL_SPAM, "Search for choice transitions." );
		search_choice_transitions( choices, compound_transitions, _event );	
		Y_LOG( log_level::LL_TRACE, "Found % transition(s) after searched for choice transitions.",
			compound_transitions.size() );

		if( compound_transitions.empty() )
		{
			if(!choices.empty() )
			{
				LOG_AND_THROW( sxy::log_level::LL_FATAL, "There are choices and no choice-transitions!" );
			}

			while(!behavior_exceptions.empty())
			{		
				if( _event_processing_callback )
				{
					_event_processing_callback->after_event_processings_stage( choices );
				}

				auto& first_behavior_exception = behavior_exceptions.front();
				auto error_event = first_behavior_exception->get_error_event();
				transition_finder transition_finder;
				auto event_is_deferred = false;

				if( _event_processing_callback )
				{
					_event_processing_callback->before_event( error_event->get_id() );
				}

				transition_finder.search_for_enabled_transitions_in_all_regions( _main_composite_state, *error_event, compound_transitions, event_is_deferred );
				execute_transitions( _main_composite_state, compound_transitions, _event_processing_callback, *error_event, _async_event_handler );
				behavior_exceptions.erase( behavior_exceptions.begin(), behavior_exceptions.begin() + 1 );


				if( _event_processing_callback )
				{
					_event_processing_callback->after_event( error_event->get_id() );
				}

			}

			Y_LOG( log_level::LL_TRACE, "Searching for completion event transition." );
			search_completion_event_transitions( _main_composite_state, compound_transitions );
		}

		if( _event_processing_callback )
		{
			_event_processing_callback->after_event_processings_stage( choices );
		}
	}

	return( terminate_pseudostate_has_been_reached );
}


void transition_controller::search_choice_transitions( const raw_const_choices& _choices, 
	compound_transitions& compound_transitions,	const event& _event )
{
	transition_finder transition_finder;
	transition_finder.search_choice_transitions( _choices, compound_transitions, _event );
}


void transition_controller::search_completion_event_transitions( const composite_state& _main_composite_state,
	compound_transitions& compound_transitions )
{
	auto event_is_deferred = false;
	transition_finder transition_finder;
	transition_finder.search_for_enabled_completion_transitions_in_all_regions( _main_composite_state,	
		compound_transitions,	event_is_deferred );
	Y_ASSERT( !event_is_deferred, "An completion transition was deferred!" );
}


}
