//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_finder.hpp"

#include "essentials/base.hpp"

#include "hermes/log_and_throw.hpp"

#include "composite_state.hpp"
#include "region.hpp"
#include "initial_pseudostate.hpp"
#include "choice.hpp"
#include "transition.hpp"
#include "compound_transition_builder.hpp"
#include "event_impl.hpp"
#include "completion_event.hpp"


namespace sxy
{


transition_finder::transition_finder()
{
	// Nothing to do...
}


transition_finder::~transition_finder() SX_NOEXCEPT
{
	// Nothing to do...
}


void transition_finder::search_for_enabled_transitions_in_all_regions( const state& _current_state, 
	const event& _event, compound_transitions& _enabled_compound_transitions, bool& _event_is_deferred, 
	event_collector& _event_collector ) const
{
	search_for_transition( _current_state, _enabled_compound_transitions, _event, _event_is_deferred, _event_collector );
}


void transition_finder::search_for_enabled_completion_transitions_in_all_regions( const state& _current_state,
	compound_transitions& _enabled_compound_transitions, bool& _event_is_deferred, 
	event_collector& _event_collector ) const
{
	search_for_transition( _current_state, _enabled_compound_transitions, *sxy::completion_event::create(), 
		_event_is_deferred, _event_collector );
}


void transition_finder::search_initial_transitions( const composite_state& _state,
	compound_transitions& _compound_transitions, event_collector& _event_collector )
{
	SX_FOR( const region_uptr& region, _state.get_regions() )
	{
		SX_LOG( hermes::log_level::LL_TRACE, "Searching for initial pseudostate in region '%'.", region->get_name() );
		const initial_pseudostate* const initial_pseudostate = region->get_initial_pseudostate();
		if( initial_pseudostate )
		{
			SX_LOG( hermes::log_level::LL_TRACE, "Initial pseudostate '%' found in region '%'.",
				initial_pseudostate->get_name(), region->get_name() );
			transition* const transition = initial_pseudostate->get_transition();
			if( !try_to_build_compound_transition( *transition, _compound_transitions, *sxy::completion_event::create(), _event_collector ) )
			{	
				std::string message = sxe::sxprintf( 
					"A compound transition could not be built for the initial transition emitting from the initial pseudostate '%'!",
					initial_pseudostate->get_name() );
				SX_ASSERT( false, message.c_str() );
			}
		}
		else
		{
			SX_LOG( hermes::log_level::LL_TRACE, "No initial pseudostate found in region '%'.", region->get_name() );
		}
	}
}


void transition_finder::search_choice_transitions( const raw_const_choices& _choices, 
	compound_transitions& _compound_transitions, const event& _event, event_collector& _event_collector )
{
	SX_FOR( const choice* const choice, _choices )
	{
		SX_ASSERT( choice, "Choice pointer is null. This cannot be a nullptr." );
		SX_LOG( hermes::log_level::LL_SPAM, "Checking outgoing transition(s) of choice '%'. It has % outgoing transitions.",
			choice->get_name(), choice->get_outgoing_transitions().size() );
		bool at_least_one_transition_is_enabled = false;

		SX_FOR( transition* const transition, choice->get_outgoing_transitions())
		{
			SX_ASSERT(transition->can_accept_event( sxy::completion_event::get_event_id() ),
				"Transition leaving choice is not a completion transition!" );
			SX_LOG( hermes::log_level::LL_SPAM, "Checking outgoing transition '%' of choice '%' for guard.",
				transition->get_name(), choice->get_name() );
			const bool guard_evaluated_to_true = transition->check_guard( _event, _event_collector );
			if( guard_evaluated_to_true )
			{
				SX_LOG( hermes::log_level::LL_SPAM, "Guard of outgoing transition '%' of choice '%' evaluates to true.",
					transition->get_name(), choice->get_name() );
				if( !try_to_build_compound_transition( *transition, _compound_transitions, _event, _event_collector ) )
				{
					LOG_AND_THROW( hermes::log_level::LL_FATAL, 
						"Transition following choice '%' could not be built in compound transition!", choice->get_name() );
				}
				else
				{
					at_least_one_transition_is_enabled = true;
				}

				break;
			}
			else
			{
				SX_LOG( hermes::log_level::LL_SPAM, "Guard of outgoing transition '%' of choice '%' evaluates to false.",
					transition->get_name(), choice->get_name() );
			}
		}

		if( !at_least_one_transition_is_enabled )
		{
			LOG_AND_THROW( hermes::log_level::LL_FATAL, "No transition is enabled for choice '%'!", choice->get_name() );
		}
	}
}


transition* transition_finder::search_completion_transition( const state& _state, event_collector& _event_collector )
{
	transition* completion_transition = SX_NULLPTR;
	if( _state.is_complete() )
	{
		SX_LOG( hermes::log_level::LL_SPAM, "State '%' is complete.", _state.get_name() );
		const sxe::shared_ptr< event_impl > completion_event = SX_MAKE_SHARED< event_impl >( sxy::completion_event::get_event_id() );
		completion_transition = _state.search_transition( *completion_event, _event_collector );
	}

	return( completion_transition );
}


bool transition_finder::search_for_transition( const state& _current_state, 
	compound_transitions& _enabled_compound_transitions, const event& _event, bool& _event_is_deferred, 
	event_collector& _event_collector ) const
{
	SX_LOG( hermes::log_level::LL_SPAM, "Search for transition in state '%'.", _current_state.get_name() );
	bool found = false;
	const regions& regions = _current_state.get_regions();

	SX_FOR( const region_uptr& region, regions )
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Search for active state in region '%'.", region->get_name() );
		const state* const active_state = region->get_active_state();
		if( active_state )
		{
			SX_LOG( hermes::log_level::LL_SPAM, "Found active state '%' in region '%'.", active_state->get_name(),
				region->get_name() );
			const bool l_found = search_for_transition( *active_state, _enabled_compound_transitions, _event, 
				_event_is_deferred, _event_collector );
			if( l_found )
			{
				SX_LOG( hermes::log_level::LL_SPAM, "Transition found in active state '%'.", active_state->get_name() );
				found = l_found;
			}
			else
			{
				SX_LOG( hermes::log_level::LL_SPAM, "No transition found in active state '%'.", active_state->get_name() );
			}
		}
		else
		{
			SX_LOG( hermes::log_level::LL_SPAM, "No active state found in region '%'.", region->get_name() );
		}
	}

	if( !found )
	{
		transition* transition = SX_NULLPTR;
		if( sxy::completion_event::get_event_id() == _event.get_id() )
		{
			SX_LOG( hermes::log_level::LL_TRACE, "Search completion transition in state '%'.", _current_state.get_name() );
			transition = search_completion_transition( _current_state, _event_collector );
		}
		else
		{
			SX_LOG( hermes::log_level::LL_TRACE, "Search transition with event id % in state '%'.",
				_event.get_id(), _current_state.get_name() );
			transition = _current_state.search_transition( _event, _event_collector );
		}

		if( transition )
		{
			SX_LOG( hermes::log_level::LL_TRACE, "Transition '%' found in the current state '%'.",
				transition->get_name(), _current_state.get_name() );
			found = try_to_build_compound_transition( *transition, _enabled_compound_transitions, _event, _event_collector );
			if( found )
			{
				SX_LOG( hermes::log_level::LL_SPAM, "Compound transition was built for transition '%'.", transition->get_name() );
			}
			else
			{
				SX_LOG( hermes::log_level::LL_SPAM, "Compound transition was not built for transition '%'.", transition->get_name() );
			}
		}
		else
		{
			SX_LOG( hermes::log_level::LL_TRACE, "No transition found in current state '%'.", _current_state.get_name() );
			if( _current_state.is_event_deferred( _event.get_id() ) )
			{
				_event_is_deferred = true;
				found = true;
			}
		}
	}

	return( found );
}


}
