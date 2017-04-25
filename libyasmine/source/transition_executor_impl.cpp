//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_executor_impl.hpp"

#include <algorithm>

#include "hermes/log_and_throw.hpp"

#include "state.hpp"
#include "region.hpp"
#include "initial_pseudostate.hpp"
#include "composite_state.hpp"
#include "choice.hpp"
#include "exit_point.hpp"
#include "entry_point.hpp"
#include "transition.hpp"
#include "terminate_pseudostate.hpp"
#include "event.hpp"
#include "transition_step.hpp"
#include "compound_transition_impl.hpp"
#include "execution_transition_step.hpp"
#include "execution_state_exit_step.hpp"
#include "execution_state_enter_step.hpp"
#include "execution_state_do_step.hpp"
#include "transition_priority.hpp"
#include "states_to_enter_visitor_impl.hpp"
#include "compound_transition_consumer.hpp"
#include "algorithm_parameters.hpp"


namespace sxy
{


namespace impl
{


transition_executor_impl::transition_executor_impl()
{
	// Nothing to do...
}


transition_executor_impl::~transition_executor_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


void transition_executor_impl::get_active_states_from_region( region& _region, 
	raw_states_by_nesting_level_ascending& _states )
{
	SX_LOG( hermes::log_level::LL_SPAM, "Checking for active state in region '%' of state '%'.",
		_region.get_name(), _region.get_parent_state().get_name() );
	state* const active_state = _region.get_active_state();
	if( active_state )
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Active state '%' found in region '%'.", active_state->get_name(),
			_region.get_name() );
		get_active_states_from_regions( active_state, _states );
		_states.insert( active_state );
	}
	else
	{
		SX_LOG( hermes::log_level::LL_SPAM, "No active state found in region '%'.", _region.get_name() );
	}
}


void transition_executor_impl::get_active_states_from_regions( const state* const _state,
	raw_states_by_nesting_level_ascending& _states )
{
	SX_FOR(const region_uptr& region, _state->get_regions())
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Checking for active state in region '%' of state '%'.",
			region->get_name(), _state->get_name() );
		state* const active_state = region->get_active_state();
		if( active_state )
		{
			SX_LOG( hermes::log_level::LL_SPAM, "Active state '%' found in region '%'.",
				active_state->get_name(), region->get_name() );
			get_active_states_from_regions( active_state, _states );
			_states.insert( active_state );
		}
		else
		{
			SX_LOG( hermes::log_level::LL_SPAM, "No active state found in region '%'.", region->get_name() );
		}
	}
}


void transition_executor_impl::get_all_states_to_enter_from_regions_that_are_not_explicitly_entered(
	compound_transition_consumer& _compound_transition, raw_const_region_set& _entered_regions,
	raw_states_by_nesting_level& _states_to_enter, const event& _event, event_collector& _event_collector )
{
	SX_FOR( const state* const state, _states_to_enter )
	{
		SX_FOR( const region_uptr& region, state->get_regions() )
		{
			const std::pair<raw_const_region_set::const_iterator, bool> inserted_region_iterator = 
				_entered_regions.insert( region.get() );
			if( false == inserted_region_iterator.second )
			{
				SX_LOG( hermes::log_level::LL_TRACE, "Region '%' was already entered.", region->get_name() );
			}
			else
			{
				const initial_pseudostate* const initial_pseudostate = region->get_initial_pseudostate();
				if( initial_pseudostate )
				{
					SX_LOG( hermes::log_level::LL_TRACE, "Found initial pseudostate '%' in region '%'.",
						initial_pseudostate->get_name(), region->get_name() );

					sxe::SX_UNIQUE_PTR< compound_transition_impl > new_compound_transition = SX_MAKE_UNIQUE< compound_transition_impl >();

					SX_LOG( hermes::log_level::LL_TRACE, "New compound transition created for event with ID %.", _event.get_id() );
					const bool built_compound_transition = new_compound_transition->create_and_check_transition_path(
						*initial_pseudostate->get_transition(), _event, _event_collector );
					SX_ASSERT( built_compound_transition,
						"Transition of initial pseudostate could not be built in compound transition!" );
					if( built_compound_transition )
					{
						SX_LOG( hermes::log_level::LL_TRACE, "Build sub compound transition for '%' transition.",
							initial_pseudostate->get_name() );
						find_already_entered_regions( *new_compound_transition, _entered_regions, _event, _event_collector );
						compound_transition_impl* const compound_transition = 
							dynamic_cast< compound_transition_impl* >( &_compound_transition );

						compound_transition->add_sub_compound_transition( sxe::move( new_compound_transition ) );
						SX_LOG( hermes::log_level::LL_SPAM, 
							"New compound transition added to compound transition as a sub compound transition." );
					}
				}
			}
		}
	}
}


void transition_executor_impl::merge_transitions_steps_with_exit_state_steps( execution_steps& _execution_steps,
	compound_transition_consumer& _compound_transition, 
	const raw_states_by_nesting_level_ascending& _states_to_exit, 
	transition_steps::const_iterator& _transition_start, transition_steps::const_iterator& _transition_end )
{
	SX_LOG( hermes::log_level::LL_TRACE, "There are % states to exit.", _states_to_exit.size() );
	if( !_states_to_exit.empty() )
	{
		raw_states_by_nesting_level_ascending::const_iterator state_to_exit_start = _states_to_exit.begin();
		raw_states_by_nesting_level_ascending::const_iterator state_to_exit_end = _states_to_exit.begin();
		while( _transition_end != _compound_transition.get_transition_steps().end() &&
					 state_to_exit_end != _states_to_exit.end() )
		{
			const exit_point* const exit_point = _transition_start->get()->get_exit_point();
			if( exit_point )
			{
				composite_state& exit_point_parent_state = exit_point->get_parent_state();
				SX_LOG( hermes::log_level::LL_TRACE, "Found exit point '%' with parent state '%'.",
					exit_point->get_name(), exit_point_parent_state.get_name() );
				state* state_from_list = *( state_to_exit_end );
				SX_LOG( hermes::log_level::LL_SPAM, "The state from the list of 'states to exit' is '%'",
							 state_from_list->get_name() );
				while( state_from_list != &exit_point_parent_state )
				{
					SX_LOG( hermes::log_level::LL_SPAM, "Add state '%' to execution steps as 'state to exit'.",
								 state_from_list->get_name() );
					sxe::SX_UNIQUE_PTR< execution_state_exit_step > execution_state_step =
						SX_MAKE_UNIQUE< execution_state_exit_step >( sxe::ref( *state_from_list ) );
					_execution_steps.push_back( sxe::move( execution_state_step ) );
					++state_to_exit_end;
					state_from_list = *( state_to_exit_end );
				}

				while( _transition_start != _transition_end )
				{
					sxe::SX_UNIQUE_PTR< execution_transition_step > l_execution_transition_step =
						SX_MAKE_UNIQUE< execution_transition_step >( sxe::ref( **_transition_start ) );
					_execution_steps.push_back( sxe::move( l_execution_transition_step ) );
					++_transition_start;
				}

				state_to_exit_start = state_to_exit_end;
			}
			else
			{
				// Nothing to do...
			}

			if( _transition_end != _compound_transition.get_transition_steps().end() )
			{
				++_transition_end;
			}
		}

		add_remaining_states_to_exit( state_to_exit_start, _states_to_exit, _execution_steps );
	}
}


void transition_executor_impl::merge_transitions_steps_with_enter_states_steps( execution_steps& _execution_steps,
	compound_transition_consumer& _compound_transition, const raw_states_by_nesting_level& _states_to_enter,
	transition_steps::const_iterator& _transition_start, transition_steps::const_iterator& _transition_end )
{
	if( !_states_to_enter.empty() )
	{
		raw_states_by_nesting_level::const_iterator state_to_enter_start = _states_to_enter.begin();
		raw_states_by_nesting_level::const_iterator state_to_enter_end = _states_to_enter.begin();
		while( _transition_end != _compound_transition.get_transition_steps().end() &&
					 state_to_enter_end != _states_to_enter.end() )
		{
			const entry_point* const entry_point = _transition_end->get()->get_entry_point();
			if( entry_point )
			{
				while( _transition_start < _transition_end )
				{
					sxe::SX_UNIQUE_PTR< execution_transition_step > l_execution_transition_step =
						SX_MAKE_UNIQUE< execution_transition_step >( sxe::ref( **_transition_start ) );
					_execution_steps.push_back( sxe::move( l_execution_transition_step ) );
					++_transition_start;
				}

				const composite_state* const parent_state_of_entry_point = &entry_point->get_parent_state();
				state* state_from_list = *( state_to_enter_end );
				while( parent_state_of_entry_point != state_from_list )
				{
					sxe::SX_UNIQUE_PTR< execution_state_enter_step > execution_state_step =
						SX_MAKE_UNIQUE< execution_state_enter_step >( sxe::ref( *state_from_list ) );
					_execution_steps.push_back( sxe::move( execution_state_step ) );
					sxe::SX_UNIQUE_PTR< execution_state_do_step > l_execution_state_do_step =
						SX_MAKE_UNIQUE< execution_state_do_step >( sxe::ref( *state_from_list ) );
					_execution_steps.push_back( sxe::move( l_execution_state_do_step ) );
					++state_to_enter_end;
					state_from_list = *( state_to_enter_end );
				}

				if( parent_state_of_entry_point == state_from_list )
				{
					sxe::SX_UNIQUE_PTR< execution_state_enter_step > execution_state_step =
						SX_MAKE_UNIQUE< execution_state_enter_step >( sxe::ref( *state_from_list ) );
					_execution_steps.push_back( sxe::move( execution_state_step ) );
					sxe::SX_UNIQUE_PTR< execution_state_do_step > l_execution_state_do_step =
						SX_MAKE_UNIQUE< execution_state_do_step >( sxe::ref( *state_from_list ) );
					_execution_steps.push_back( sxe::move( l_execution_state_do_step ) );
				}

				state_to_enter_start = ++state_to_enter_end;
			}
			else
			{
				// Nothing to do...
			}

			++_transition_end;
		}

		add_remained_transitions( _transition_start, _transition_end, _execution_steps );
		add_remaining_states_to_enter( state_to_enter_start, _states_to_enter, _execution_steps );
	}
	else
	{
		SX_LOG( hermes::log_level::LL_TRACE, "There are no states to enter." );
		if( _transition_start == _transition_end )
		{
			const vertex& target = _transition_end->get()->get_unique_target();
			if( dynamic_cast< const terminate_pseudostate* >( &target ) )
			{
				_execution_steps.push_back( SX_MAKE_UNIQUE< execution_transition_step >( sxe::ref( **_transition_start ) ) );
			}
			else
			{
				add_remained_transitions( _transition_start, ++_transition_end, _execution_steps );
				transition* const last_transition = _compound_transition.get_transition_steps().back()->get_transitions().back();
				const vertex& last_target = last_transition->get_target();
				const state* state_to_execute = dynamic_cast< const state* >( &last_target );
				if( state_to_execute )
				{
					_execution_steps.push_back( SX_MAKE_UNIQUE< execution_state_do_step >( sxe::ref( *state_to_execute ) ) );
				}
			}
		}
	}
}


void transition_executor_impl::calculate_execution_steps( compound_transition_consumer& _compound_transition,
	const raw_states_by_nesting_level_ascending& _states_to_exit, 
	const raw_states_by_nesting_level& _states_to_enter, execution_steps& _execution_steps,
	raw_const_region_set& _entered_regions, const event& _event, event_collector& _event_collector )
{
	SX_LOG( hermes::log_level::LL_SPAM, "Compound transition has % step(s).", 
		_compound_transition.get_transition_steps().size() );
#ifndef SX_CPP03_BOOST
	transition_steps::const_iterator transition_start = _compound_transition.get_transition_steps().cbegin();
	transition_steps::const_iterator transition_end = _compound_transition.get_transition_steps().cbegin();
#else
	transition_steps::const_iterator transition_start = _compound_transition.get_transition_steps().begin();
	transition_steps::const_iterator transition_end = _compound_transition.get_transition_steps().begin();
#endif
	merge_transitions_steps_with_exit_state_steps( _execution_steps, _compound_transition, _states_to_exit,
		transition_start, transition_end );
#ifndef SX_CPP03_BOOST
	if( transition_end == _compound_transition.get_transition_steps().cend() )
#else
	if( transition_end == _compound_transition.get_transition_steps().end() )
#endif
	{
		transition_end = transition_start;
	}

	merge_transitions_steps_with_enter_states_steps( _execution_steps, _compound_transition, _states_to_enter,
		transition_start, transition_end );

	SX_FOR( const compound_transition_uptr& sub_compound_transition, _compound_transition.get_sub_compound_transitions() )
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Compound transition has % sub compound transition(s).",
			_compound_transition.get_sub_compound_transitions().size() );
		find_states_to_enter_and_to_exit_and_calculate_execution_steps( *sub_compound_transition, _execution_steps,
			_entered_regions, _event, false, _event_collector );
	}
}


bool transition_executor_impl::run_execution_steps( const execution_steps& _execution_steps,
	event_processing_callback* const _event_processing_callback, const event& _event,
	events& _exception_events, async_event_handler* const _async_event_handler,
	event_collector& _event_collector )
{
	SX_LOG( hermes::log_level::LL_TRACE, "Start executing % steps.", _execution_steps.size() );
	bool run_reached_terminate_pseudostate = false;

	SX_FOR( const execution_step_uptr& execution_step, _execution_steps )
	{
		if( execution_step->execute_behavior( _event_processing_callback, _event, _exception_events, _async_event_handler, _event_collector ) )
		{
			run_reached_terminate_pseudostate = true;
			break;
		}
	}

	SX_LOG( hermes::log_level::LL_TRACE, "Finished executing % steps.", _execution_steps.size() );
	return( run_reached_terminate_pseudostate );
}


void transition_executor_impl::conflict_check( const compound_transitions& _compound_transitions ) const
{
	raw_const_state_set unique_exit_states;

	SX_FOR( const compound_transition_uptr& compound_transition, _compound_transitions )
	{
		const transition_steps& transition_steps = compound_transition->get_transition_steps();
		SX_LOG( hermes::log_level::LL_TRACE, "Found % transition step(s) for compound transition.", transition_steps.size() );
		SX_LOG( hermes::log_level::LL_SPAM, "Getting the source of the compound transition." );
		const transition_step_uptr& transition_step = transition_steps.front();
		const transition*const transition = transition_step->get_transitions().front();
		const vertex& vertex = transition->get_source();
		SX_LOG( hermes::log_level::LL_TRACE, "Source of compound transition is '%'.", vertex.get_name() );
		const state* const l_state = dynamic_cast< const state* >( &vertex );
		if( l_state )
		{
			SX_LOG( hermes::log_level::LL_TRACE, "Source of compound transition is a state ( '%' ).", l_state->get_name() );
			const region* LCA_region = compound_transition->get_LCA_region();
			const composite_state* parent_state = SX_NULLPTR;
			if( LCA_region )
			{
				parent_state = &LCA_region->get_parent_state();
			}
			else
			{
				parent_state = l_state->get_root_state();
			}
			check_conflicts_from_source_state_to_LCA( *l_state, unique_exit_states, parent_state );
		}
	}
}


raw_compound_transitions transition_executor_impl::sort_compound_transitions(
	const compound_transitions& _unsorted_compound_transitions )
{
	std::vector< transition_priority > transitions_priorities;
	transitions_priorities.reserve( TRANSITION_PRIORITIES_VECTOR_SIZE );

	SX_FOR( const compound_transition_uptr& compound_transition, _unsorted_compound_transitions )
	{
		transition_priority order_object( *compound_transition );
		transitions_priorities.push_back( order_object );
	}

	std::sort( transitions_priorities.begin(), transitions_priorities.end() );
	raw_compound_transitions sorted_compound_transitions;
	sorted_compound_transitions.reserve( transitions_priorities.size() );

	// cppcheck-suppress duplicateExpression
	SX_FOR( const transition_priority& transition_priority, transitions_priorities )
	{
		compound_transition& compound_transition = transition_priority.get_compound_transition();
		sorted_compound_transitions.push_back( &compound_transition );
	}

	return( sorted_compound_transitions );
}


void transition_executor_impl::find_all_states_to_exit( compound_transition_consumer& _compound_transition,
	raw_states_by_nesting_level_ascending& _states_to_exit )
{
	const transition_kind compound_transition_kind = _compound_transition.get_transition_kind();
	if( !( transition_kind::INTERNAL == compound_transition_kind ) )
	{
		region* LCA_region = _compound_transition.get_LCA_region();
		if( !LCA_region )
		{
			const composite_state* const root_state = _compound_transition.get_last_target().get_root_state();
			LCA_region = root_state->get_regions().front().get();
		}
		fill_vector_of_states_to_exit( LCA_region, _states_to_exit, compound_transition_kind );
	}
	else
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Transitions of compound transition are 'INTERNAL'. There are no states to exit." );
	}
}


void transition_executor_impl::find_all_states_to_enter( compound_transition_consumer& _compound_transition,
	raw_states_by_nesting_level& _states_to_enter, raw_const_region_set& _regions_to_enter, const event& _event, 
	event_collector& _event_collector )
{
	const transition_kind compound_transition_kind = _compound_transition.get_transition_kind();
	if( !( transition_kind::INTERNAL == compound_transition_kind ) )
	{
		transition_step_uptr& last_transition_step = _compound_transition.get_transition_steps().back();

		SX_FOR( transition* const transition, last_transition_step->get_transitions() )
		{
			vertex& vertex = transition->get_target();
			SX_LOG( hermes::log_level::LL_SPAM, "Target of transition '%' is '%'.", transition->get_name(), vertex.get_name() );
			if( transition_kind::LOCAL == compound_transition_kind )
			{
				region* LCA_region = _compound_transition.get_LCA_region();
				composite_state* active_state_as_composite_state = SX_NULLPTR;
				if( LCA_region )
				{
					active_state_as_composite_state = dynamic_cast< composite_state* >( LCA_region->get_active_state() );
				}
				else
				{
					active_state_as_composite_state = vertex.get_root_state();
				}

				if( active_state_as_composite_state )
				{
					states_to_enter_visitor_impl visitor( _states_to_enter, _regions_to_enter, *active_state_as_composite_state, 
						transition->get_source() );
					vertex.accept_vertex_visitor( visitor );
					_states_to_enter.erase( active_state_as_composite_state );
				}
			}
			else
			{
				region* LCA_region = _compound_transition.get_LCA_region();
				composite_state* parent_state = SX_NULLPTR;
				if( LCA_region )
				{
					parent_state = &LCA_region->get_parent_state();
				}
				else
				{
					parent_state = vertex.get_root_state();
				}
				states_to_enter_visitor_impl visitor( _states_to_enter, _regions_to_enter, *parent_state, 
					transition->get_source() );
				vertex.accept_vertex_visitor( visitor );
			}
		}

		get_all_states_to_enter_from_regions_that_are_not_explicitly_entered( _compound_transition, _regions_to_enter,
			_states_to_enter, _event, _event_collector );
	}
	else
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Transitions of compound transition are 'INTERNAL'. There are no states to enter." );
	}
}


void transition_executor_impl::add_remaining_states_to_enter(
	const raw_states_by_nesting_level::const_iterator _state_start, 
	const raw_states_by_nesting_level& _states_to_enter, execution_steps& _execution_steps )
{
	raw_states_by_nesting_level::const_iterator state_start = _state_start;
	while( state_start != _states_to_enter.end() )
	{
		state* const state_from_list = *state_start;
		SX_LOG( hermes::log_level::LL_SPAM, "State '%' added to execution steps as 'state to enter'.",
			state_from_list->get_name() );
		_execution_steps.push_back( SX_MAKE_UNIQUE< execution_state_enter_step >( sxe::ref( *state_from_list ) ) );
		_execution_steps.push_back( SX_MAKE_UNIQUE< execution_state_do_step >( sxe::ref( *state_from_list ) ) );
		++state_start;
	}
}


void transition_executor_impl::add_remaining_states_to_exit( 
	const raw_states_by_nesting_level_ascending::const_iterator _state_start,
	const raw_states_by_nesting_level_ascending& _states, execution_steps& _execution_steps )
{
	raw_states_by_nesting_level_ascending::const_iterator state_start = _state_start;
	while( state_start != _states.end() )
	{
		state* const state_from_list = *state_start;
		SX_LOG( hermes::log_level::LL_SPAM, "Add remaining state '%' to execution steps as 'state to exit'.",
			state_from_list->get_name() );
		_execution_steps.push_back( SX_MAKE_UNIQUE< execution_state_exit_step >( sxe::ref( *state_from_list ) ) );
		++state_start;
	}
}


void transition_executor_impl::add_remained_transitions( transition_steps::const_iterator& _transition_start,
	const transition_steps::const_iterator& _transition_end, execution_steps& _execution_steps )
{
	while( _transition_start != _transition_end )
	{
		sxe::SX_UNIQUE_PTR< execution_transition_step > l_execution_transition_step 
			= SX_MAKE_UNIQUE< execution_transition_step >( sxe::ref( **_transition_start ) );
		_execution_steps.push_back( sxe::move( l_execution_transition_step ) );
		++_transition_start;
	}
}


void transition_executor_impl::fill_vector_of_choices( raw_const_choices& _choices,
	const compound_transitions& _compound_transitions )
{
	SX_FOR( const compound_transition_uptr& compound_transition, _compound_transitions )
	{
		const choice* const l_choice = dynamic_cast< const choice* >( &compound_transition->get_last_target() );
		if( l_choice )
		{
			SX_LOG( hermes::log_level::LL_TRACE, "Found one choice ( '%' ) as target of compound transition.", l_choice->get_name() );
			_choices.push_back( l_choice );
		}

		SX_LOG( hermes::log_level::LL_TRACE, "Fill vector of choices for one compound transition." );
		fill_vector_of_choices( _choices, compound_transition->get_sub_compound_transitions() );
		SX_LOG( hermes::log_level::LL_TRACE, "Found % choice(s) for one compound transition.", _choices.size() );
	}
}


void transition_executor_impl::find_already_entered_regions( compound_transition& new_compound_transition,
	raw_const_region_set& _entered_regions, const event& _event, event_collector& _event_collector )
{	
	raw_states_by_nesting_level states_to_enter;
	find_all_states_to_enter( new_compound_transition, states_to_enter, _entered_regions, _event, _event_collector );
}


void transition_executor_impl::find_states_to_enter_and_to_exit_and_calculate_execution_steps(
	compound_transition_consumer& _compound_transition, execution_steps& _execution_steps, 
	raw_const_region_set& _entered_regions, const event& _event, bool _find_states_to_exit, 
	event_collector& _event_collector )
{
	raw_states_by_nesting_level_ascending states_to_exit;
	SX_LOG( hermes::log_level::LL_TRACE, "Start searching states to exit." );
		
	if( _find_states_to_exit )
	{
		find_all_states_to_exit( _compound_transition, states_to_exit );
		SX_LOG( hermes::log_level::LL_TRACE, "Found % state(s) to exit.", states_to_exit.size() );
	}
	raw_states_by_nesting_level states_to_enter;
	SX_LOG( hermes::log_level::LL_TRACE, "Start searching states to enter." );
	find_all_states_to_enter( _compound_transition, states_to_enter, _entered_regions, _event, _event_collector );
	SX_LOG( hermes::log_level::LL_TRACE, "Found % state(s) to enter.", states_to_enter.size() );
	SX_LOG( hermes::log_level::LL_TRACE, "Calculating the execution steps." );
	calculate_execution_steps( _compound_transition, states_to_exit, states_to_enter, _execution_steps,
		_entered_regions, _event, _event_collector );
	SX_LOG( hermes::log_level::LL_TRACE, "% execution step(s) were calculated.", _execution_steps.size() );
}


void transition_executor_impl::check_conflicts_from_source_state_to_LCA( const state& _state,
	raw_const_state_set& _unique_exit_states, const composite_state* _LCA ) const
{		
	if( &_state != _LCA )
	{
		SX_LOG( hermes::log_level::LL_TRACE, "Checking conflicts from source '%' up to LCA '%'.", _state.get_name(),
			_LCA->get_name() );
		const std::pair< raw_const_state_set::const_iterator, bool > insert_result = _unique_exit_states.insert( &_state );
		if( !insert_result.second )
		{
			LOG_AND_THROW( hermes::log_level::LL_FATAL, "There are conflicts. The intersection of states '%' and '%' is not empty.",
				_state.get_name(), _LCA->get_name() );
		}
		else
		{
			SX_LOG( hermes::log_level::LL_TRACE, "There are no conflicts. The intersection of states '%' and '%' is empty.",
				_state.get_name(), _LCA->get_name() );
		}

		SX_ASSERT( _state.get_parent_region(), "State has no parent region!" );
		const composite_state& parent_state = _state.get_parent_region()->get_parent_state();
		SX_LOG( hermes::log_level::LL_SPAM, "Parent state of the state '%' is '%'.", _state.get_name(), parent_state.get_name() );
		if( &parent_state != _LCA )
		{
			check_conflicts_from_source_state_to_LCA( parent_state, _unique_exit_states, _LCA );
		}
	}
	else
	{
		// Nothing to check. No conflicts.
	}
}


void transition_executor_impl::fill_vector_of_states_to_exit( region* _LCA_region,
	raw_states_by_nesting_level_ascending& _states_to_exit, const transition_kind _compound_transition_kind )
{
	if( transition_kind::EXTERNAL == _compound_transition_kind )
	{
		if( _LCA_region->get_parent_state().is_active() )
		{
			get_active_states_from_region( *_LCA_region, _states_to_exit );
			SX_LOG( hermes::log_level::LL_TRACE, "Number of states to exit: %.", _states_to_exit.size() );
		}
		else
		{
			SX_LOG( hermes::log_level::LL_SPAM,
				"Least common ancestor '%' of compound transition is not active. No states to exit.",
				_LCA_region->get_parent_state().get_name() );
		}
	}
	else
		if( transition_kind::LOCAL == _compound_transition_kind )
		{
			sxy::state* active_state = _LCA_region->get_active_state();
			if( active_state )
			{
				SX_FOR( const region_uptr& region, active_state->get_regions() )
				{
					get_active_states_from_region( *region, _states_to_exit );
					SX_LOG( hermes::log_level::LL_TRACE, "Number of states to exit: %.", _states_to_exit.size() );
				}
			}
			else
			{
				SX_LOG( hermes::log_level::LL_TRACE, "Least common ancestor '%' of compound transition, has no active state. .",
					_LCA_region->get_name() );
			}
		}
}


}


}
