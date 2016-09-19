//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_transition_executor_impl.h"

#include <algorithm>

#include "t_log_and_throw.h"
#include "i_state.h"
#include "i_region.h"
#include "i_initial_pseudostate.h"
#include "i_composite_state.h"
#include "i_choice.h"
#include "i_exit_point.h"
#include "i_entry_point.h"
#include "i_transition.h"
#include "i_terminate_pseudostate.h"
#include "i_event.h"

#include "i_transition_step.h"
#include "i_transition_step_fwd.h"
#include "t_compound_transition.h"
#include "t_execution_transition_step.h"
#include "t_execution_state_exit_step.h"
#include "t_execution_state_enter_step.h"
#include "t_execution_state_do_step.h"
#include "t_transition_priority.h"

#include "t_states_to_enter_visitor.h"

#include "i_compound_transition_consumer.h"


namespace sxy
{


namespace impl
{


t_transition_executor_impl::t_transition_executor_impl
(
) = default;


t_transition_executor_impl::~t_transition_executor_impl
(
) = default;


void 
t_transition_executor_impl::get_active_states_from_region
(
	i_region& p_region,
	t_raw_states_by_nesting_level_ascending& p_states
)
{
	Y_LOG( t_log_level::LL_SPAM, "Checking for active state in region '%' of state '%'.", p_region.get_name(), p_region.get_parent_state().get_name() );
	auto l_active_state = p_region.get_active_state();	

	if( l_active_state )
	{			
		Y_LOG( t_log_level::LL_SPAM, "Active state '%' found in region '%'.", l_active_state->get_name(), p_region.get_name() );			
		get_active_states_from_regions( l_active_state, p_states );					
		p_states.insert( l_active_state );		
	}
	else
	{
		Y_LOG( t_log_level::LL_SPAM, "Active state NOT found in region '%'.", p_region.get_name() );
	}
}


void
t_transition_executor_impl::get_active_states_from_regions
(
	const i_state* const p_state,
	t_raw_states_by_nesting_level_ascending& p_states
)
{
	for( const auto& l_region : p_state->get_regions() )
	{
		Y_LOG( t_log_level::LL_SPAM, "Checking for active state in region '%' of state '%'.", l_region->get_name(), p_state->get_name() );
		auto l_active_state = l_region->get_active_state();

		if( l_active_state )
		{
			Y_LOG( t_log_level::LL_SPAM, "Active state '%' found in region '%'.", l_active_state->get_name(), l_region->get_name() );			
			get_active_states_from_regions( l_active_state, p_states );
			p_states.insert( l_active_state );
		}
		else
		{
			Y_LOG( t_log_level::LL_SPAM, "Active state NOT found in region '%'.", l_region->get_name() );
		}
	}
}


void
t_transition_executor_impl::get_all_states_to_enter_from_regions_that_are_not_explicitly_entered
(
	i_compound_transition_consumer& p_compound_transition,
	t_raw_const_region_set& p_entered_regions,
	t_raw_states_by_nesting_level& p_states_to_enter,
	const i_event& p_event
)
{
	for( const auto l_state : p_states_to_enter )
	{
		for( const auto& l_region : l_state->get_regions() )
		{
			const auto l_inserted_region_iterator = p_entered_regions.insert( l_region.get() );
			if( false == l_inserted_region_iterator.second )
			{					
				Y_LOG( t_log_level::LL_DEBUG, "Region '%' was already entered.", l_region->get_name() );
			}
			else
			{
				auto l_initial_pseudostate = l_region->get_initial_pseudostate();
				if( l_initial_pseudostate )
				{
					Y_LOG( t_log_level::LL_DEBUG, "Found initial pseudostate '%' in the region '%'.", l_initial_pseudostate->get_name(), l_region->get_name() );

#ifdef _MSC_VER
#if _MSC_VER>=1900
					auto l_new_compound_transition = std::make_unique< t_compound_transition >();
#elif _MSC_VER<=1800
					auto l_new_compound_transition = std::make_shared< t_compound_transition >();
#endif
#else
					auto l_new_compound_transition = std::make_unique< t_compound_transition >();
#endif

					Y_LOG( t_log_level::LL_INFO, "New compound transition created." );
					const auto built_compound_transition = l_new_compound_transition->create_and_check_transition_path( *l_initial_pseudostate->get_transition(), p_event );

					Y_ASSERT( built_compound_transition, "Transition of initial pseudostate could not be built in composite state!" );

					if( built_compound_transition )
					{
						Y_LOG( t_log_level::LL_DEBUG, "Build subcompound transition for '%' transition.", l_initial_pseudostate->get_name() );

						find_all_states_to_enter_and_exit( *l_new_compound_transition, p_entered_regions, p_event );

						auto l_compound_transition = dynamic_cast< t_compound_transition* >( &p_compound_transition );

						//DONE Is this needed here? Isn't it the same code? -> a shared pointer is not moved
#ifdef _MSC_VER
#if _MSC_VER>=1900
						l_compound_transition->add_sub_compound_transition( std::move( l_new_compound_transition ) );
#elif _MSC_VER<=1800
						l_compound_transition->add_sub_compound_transition( l_new_compound_transition );
#endif
#else
						l_compound_transition->add_sub_compound_transition( std::move( l_new_compound_transition ) );
#endif						
						Y_LOG( t_log_level::LL_INFO, "New compound transition added to compound transition as a sub compound transition." );
					}
				}
			}
		}
	}
}


void
t_transition_executor_impl::merge_transitions_steps_with_exit_state_steps
(
	t_execution_steps& p_execution_steps,
	i_compound_transition_consumer& p_compound_transition,
	const t_raw_states_by_nesting_level_ascending& p_states_to_exit,
	t_transition_steps::const_iterator& p_transition_start,
	t_transition_steps::const_iterator& p_transition_end
)
{
	Y_LOG( t_log_level::LL_TRACE, "There are % states to exit.", p_states_to_exit.size() );

	if( !p_states_to_exit.empty() )
	{
		auto l_state_to_exit_start = p_states_to_exit.begin();
		auto l_state_to_exit_end = p_states_to_exit.begin();

		while( p_transition_end != p_compound_transition.get_transition_steps().end() && l_state_to_exit_end != p_states_to_exit.end() )
		{
			const auto l_exit_point = p_transition_start->get()->get_exit_point();
			if( l_exit_point )
			{
				auto& l_exit_point_parent_state = l_exit_point->get_parent_state();
				Y_LOG( t_log_level::LL_SPAM, "Found exit point '%' with parent state '%'.", l_exit_point->get_name(), l_exit_point_parent_state.get_name() );

				auto l_state_from_list = *( l_state_to_exit_end );

				Y_LOG( t_log_level::LL_SPAM, "The state from the list of 'states to exit' is '%'", l_state_from_list->get_name() );

				while( l_state_from_list != &l_exit_point_parent_state )
				{
					Y_LOG( t_log_level::LL_SPAM, "Add state '%' to execution steps as 'state to exit'.", l_state_from_list->get_name() );
					auto l_execution_state_step = std::make_unique< t_execution_state_exit_step >( *l_state_from_list );
					p_execution_steps.push_back( std::move( l_execution_state_step ) );

					++l_state_to_exit_end;
					l_state_from_list = *( l_state_to_exit_end );
				}

				while( p_transition_start != p_transition_end )
				{
					auto l_execution_transition_step = std::make_unique< t_execution_transition_step >( **p_transition_start );
					p_execution_steps.push_back( std::move( l_execution_transition_step ) );
					++p_transition_start;
				}

				l_state_to_exit_start = l_state_to_exit_end;
			}
			else
			{
				// Nothing to do...
			}

			if( p_transition_end != p_compound_transition.get_transition_steps().end() )
			{
				++p_transition_end;
			}
		}

		add_remaining_states_to_exit( l_state_to_exit_start, p_states_to_exit, p_execution_steps );
	}
}


void
t_transition_executor_impl::merge_transitions_steps_with_enter_states_steps
(
	t_execution_steps& p_execution_steps,
	i_compound_transition_consumer& p_compound_transition,
	const t_raw_states_by_nesting_level& p_states_to_enter,
	t_transition_steps::const_iterator& p_transition_start,
	t_transition_steps::const_iterator& p_transition_end
)
{
	if( !p_states_to_enter.empty() )
	{
		auto l_state_to_enter_start = p_states_to_enter.begin();
		auto l_state_to_enter_end = p_states_to_enter.begin();

		while( p_transition_end != p_compound_transition.get_transition_steps().end() && l_state_to_enter_end != p_states_to_enter.end() )
		{
			const auto l_entry_point = p_transition_end->get()->get_entry_point();

			if( l_entry_point )
			{
				while( p_transition_start < p_transition_end )
				{
					auto l_execution_transition_step = std::make_unique< t_execution_transition_step >( **p_transition_start );
					p_execution_steps.push_back( std::move( l_execution_transition_step ) );
					++p_transition_start;
				}

				const auto l_parent_state_of_entry_point = &l_entry_point->get_parent_state();
				auto l_state_from_list = *( l_state_to_enter_end );

				while( l_parent_state_of_entry_point != l_state_from_list )
				{
					auto l_execution_state_step = std::make_unique< t_execution_state_enter_step >( *l_state_from_list );
					p_execution_steps.push_back( std::move( l_execution_state_step ) );

					auto l_execution_state_do_step = std::make_unique< t_execution_state_do_step >( *l_state_from_list );
					p_execution_steps.push_back( std::move( l_execution_state_do_step ) );

					++l_state_to_enter_end;
					l_state_from_list = *( l_state_to_enter_end );
				}

				if( l_parent_state_of_entry_point  == l_state_from_list )
				{
					auto l_execution_state_step = std::make_unique< t_execution_state_enter_step >( *l_state_from_list );
					p_execution_steps.push_back( std::move( l_execution_state_step ) );

					auto l_execution_state_do_step = std::make_unique< t_execution_state_do_step >( *l_state_from_list );
					p_execution_steps.push_back( std::move( l_execution_state_do_step ) );
				}

				l_state_to_enter_start = ++l_state_to_enter_end;
			}
			else
			{
				// Nothing to do...
			}

			++p_transition_end;
		}

		add_remained_transitions( p_transition_start, p_transition_end, p_execution_steps );
		add_remaining_states_to_enter( l_state_to_enter_start, p_states_to_enter, p_execution_steps );
	}
	else
	{
		Y_LOG( t_log_level::LL_DEBUG, "There are no states to enter." );
		if(p_transition_start == p_transition_end)
		{
			auto& l_target = p_transition_end->get()->get_unique_target();
			if( dynamic_cast< const i_terminate_pseudostate* >( &l_target ) )
			{					
				p_execution_steps.push_back( std::make_unique< t_execution_transition_step >( **p_transition_start ) );
			}
			else
			{					
				add_remained_transitions( p_transition_start, ++p_transition_end, p_execution_steps );				

				auto l_last_transition = p_compound_transition.get_transition_steps().back()->get_transitions().back();
				auto& l_last_target = l_last_transition->get_target();
				auto l_state_to_execute = dynamic_cast< const i_state* >( &l_last_target );
				if( l_state_to_execute )
				{												
					p_execution_steps.push_back( std::make_unique< t_execution_state_do_step >( *l_state_to_execute ) );
				}
			}

		}
	}
}


void
t_transition_executor_impl::calculate_execution_steps
(
	i_compound_transition_consumer& p_compound_transition,
	const t_raw_states_by_nesting_level_ascending& p_states_to_exit,
	const t_raw_states_by_nesting_level& p_states_to_enter,
	t_execution_steps& p_execution_steps,
	t_raw_const_region_set& p_entered_regions,
	const i_event& p_event
)
{
	Y_LOG( t_log_level::LL_SPAM, "Compound transition has % step(s).", p_compound_transition.get_transition_steps().size() );
	auto l_transition_start = p_compound_transition.get_transition_steps().begin();
	auto l_transition_end = p_compound_transition.get_transition_steps().begin();

	merge_transitions_steps_with_exit_state_steps( p_execution_steps, p_compound_transition, p_states_to_exit, l_transition_start, l_transition_end );
	if( l_transition_end == p_compound_transition.get_transition_steps().end() )
	{
		l_transition_end = l_transition_start;
	}

	merge_transitions_steps_with_enter_states_steps( p_execution_steps, p_compound_transition, p_states_to_enter, l_transition_start, l_transition_end );

	for( const auto& l_sub_compound_transition : p_compound_transition.get_sub_compound_transitions() )
	{
		Y_LOG( t_log_level::LL_SPAM, "Compound transition has % subcompound transition(s).", p_compound_transition.get_sub_compound_transitions().size() );
		find_states_to_enter_and_to_exit_and_calculate_execution_steps( *l_sub_compound_transition, p_execution_steps, p_entered_regions, p_event );
	}
}


bool
t_transition_executor_impl::run_execution_steps
(
	const t_execution_steps& p_execution_steps,
	i_event_processing_callback* const p_event_processing_callback,
	const i_event& p_event
)
{
	Y_LOG( t_log_level::LL_INFO, "Start executing % steps.", p_execution_steps.size() );
	auto l_run_reached_terminate_pseudostate = false;

	for( const auto& l_execution_step : p_execution_steps )
	{
		if( l_execution_step->execute_behavior( p_event_processing_callback, p_event ) )
		{
			l_run_reached_terminate_pseudostate = true;
			break;
		}
	}

	Y_LOG( t_log_level::LL_INFO, "Finish executing % steps.", p_execution_steps.size() );
	return( l_run_reached_terminate_pseudostate );
}


void
t_transition_executor_impl::conflict_check
(
	const t_compound_transitions& p_compound_transitions
) const
{
	t_raw_const_state_set unique_exit_states;

	for( const auto& l_compound_transition : p_compound_transitions )
	{
		const auto& l_transition_steps = l_compound_transition->get_transition_steps();
		Y_LOG( t_log_level::LL_TRACE, "Found % transition step(s) for compound transition.", l_transition_steps.size() );

		Y_LOG( t_log_level::LL_SPAM, "Getting the source of compound transition." );
		auto& l_transition_step = l_transition_steps.front();
		auto& l_transition = l_transition_step->get_transitions().front();
		const auto& l_vertex = l_transition->get_source();
		Y_LOG( t_log_level::LL_TRACE, "Source of compound transition is '%'.", l_vertex.get_name() );

		const auto l_state = dynamic_cast< const i_state* >( &l_vertex );
		if( l_state )
		{
			Y_LOG( t_log_level::LL_TRACE, "Source of compound transition is a state ( '%' ).", l_state->get_name() );
			check_conflicts_from_source_state_up_to_LCA( *l_state, unique_exit_states, &l_compound_transition->get_LCA_region()->get_parent_state() );
		}
	}
}


t_raw_compound_transitions
t_transition_executor_impl::sort_compound_transitions
(
	const t_compound_transitions& p_unsorted_compound_transitions
)
{
	std::vector< t_transition_priority > transitions_priorities;

	for( const auto& compound_transition : p_unsorted_compound_transitions )
	{
		t_transition_priority order_object( *compound_transition );

		transitions_priorities.push_back( order_object );
	}

	std::sort( transitions_priorities.begin(), transitions_priorities.end() );

	t_raw_compound_transitions sorted_compound_transitions;

	for( const auto& transition_priority : transitions_priorities )
	{
		auto& compound_transition = transition_priority.get_compound_transition();
		sorted_compound_transitions.push_back( &compound_transition );
	}

	return( sorted_compound_transitions );
}


void
t_transition_executor_impl::find_all_states_to_exit
(
	i_compound_transition_consumer& p_compound_transition,
	t_raw_states_by_nesting_level_ascending& p_states_to_exit
)
{
	const auto l_compound_transition_kind = p_compound_transition.get_transition_kind();

	if( t_transition_kind::INTERNAL != l_compound_transition_kind )
	{
		auto l_least_common_ancestor = p_compound_transition.get_LCA_region();

		if( t_transition_kind::EXTERNAL == l_compound_transition_kind )
		{
			if( l_least_common_ancestor->get_parent_state().is_active() )
			{
				get_active_states_from_region( *l_least_common_ancestor, p_states_to_exit );
				Y_LOG( t_log_level::LL_TRACE, "Number of states to exit: %.", p_states_to_exit.size() );
			}
			else
			{
				Y_LOG( t_log_level::LL_SPAM, "Least common ancestor '%' of compound transition is not active. No states to exit.", l_least_common_ancestor->get_parent_state().get_name() );
			}
		}
		else
			if( t_transition_kind::LOCAL == l_compound_transition_kind )
			{	
				if( l_least_common_ancestor->get_active_state() )
				{
					for( auto& l_region : l_least_common_ancestor->get_active_state()->get_regions() )
					{
						get_active_states_from_region( *l_region, p_states_to_exit );
						Y_LOG( t_log_level::LL_TRACE, "Number of states to exit: %.", p_states_to_exit.size() );
					}
				}
				else
				{
					Y_LOG( t_log_level::LL_TRACE, "Least common ancestor '%' of compound transition, has no active state. .", l_least_common_ancestor->get_name() );
				}
			}
	}
	else
	{
		Y_LOG( t_log_level::LL_SPAM, "Transitions of compound transition are 'INTERNAL'. There are no states to exit." );
	}
}


void
t_transition_executor_impl::find_all_states_to_enter
(
	i_compound_transition_consumer& p_compound_transition,  
	t_raw_states_by_nesting_level& p_states_to_enter,
	t_raw_const_region_set& p_regions_to_enter,
	const i_event& p_event
)
{

	const auto l_compound_transition_kind = p_compound_transition.get_transition_kind();

	if( t_transition_kind::INTERNAL != l_compound_transition_kind )
	{
		auto& l_last_transition_step = p_compound_transition.get_transition_steps().back();

		for( auto& l_transition : l_last_transition_step->get_transitions() )
		{	
			auto& l_vertex = l_transition->get_target();

			Y_LOG( t_log_level::LL_DEBUG, "Target of transition is '%'.", l_vertex.get_name() );
			if( t_transition_kind::LOCAL == l_compound_transition_kind )
			{
				auto l_active_state_as_composite_state = dynamic_cast< i_composite_state* > ( p_compound_transition.get_LCA_region()->get_active_state() );
				if( l_active_state_as_composite_state )
				{
					t_states_to_enter_visitor l_visitor( p_states_to_enter, p_regions_to_enter, *l_active_state_as_composite_state );
					l_vertex.accept_vertex_visitor( l_visitor );
					p_states_to_enter.erase( l_active_state_as_composite_state );
				}
			}
			else
			{
				t_states_to_enter_visitor l_visitor( p_states_to_enter, p_regions_to_enter, p_compound_transition.get_LCA_region()->get_parent_state() );
				l_vertex.accept_vertex_visitor( l_visitor );
			}
		}

		get_all_states_to_enter_from_regions_that_are_not_explicitly_entered( p_compound_transition, p_regions_to_enter, p_states_to_enter, p_event );	}
	else
	{
		Y_LOG( t_log_level::LL_SPAM, "Transitions of compound transition are 'INTERNAL'. There are no states to enter." );
	}
}


void
t_transition_executor_impl::add_remaining_states_to_enter
(
	const t_raw_states_by_nesting_level::const_iterator p_state_start,
	const t_raw_states_by_nesting_level& p_states_to_enter,
	t_execution_steps& p_execution_steps
)
{	
	t_raw_states_by_nesting_level::const_iterator l_state_start = p_state_start;

	while( l_state_start != p_states_to_enter.end() )
	{
		auto l_state_from_list = *l_state_start;
		Y_LOG( t_log_level::LL_SPAM, "State '%' added to execution steps as 'state to enter'.", l_state_from_list->get_name() );
		p_execution_steps.push_back( std::make_unique< t_execution_state_enter_step >( *l_state_from_list ) );
		p_execution_steps.push_back( std::make_unique< t_execution_state_do_step >( *l_state_from_list ) );
		++l_state_start;
	}
}


void
t_transition_executor_impl::add_remaining_states_to_exit
(
	const t_raw_states_by_nesting_level_ascending::const_iterator p_state_start,
	const t_raw_states_by_nesting_level_ascending& p_states,
	t_execution_steps& p_execution_steps
)
{
	t_raw_states_by_nesting_level_ascending::const_iterator l_state_start = p_state_start;

	while( l_state_start != p_states.end() )
	{
		auto l_state_from_list = *l_state_start;
		Y_LOG( t_log_level::LL_SPAM, "Add remaining state '%' to execution steps as 'state to exit'.", l_state_from_list->get_name() );
		p_execution_steps.push_back( std::make_unique< t_execution_state_exit_step >( *l_state_from_list ) );
		++l_state_start;
	}
}


void
t_transition_executor_impl::add_remained_transitions
(
	t_transition_steps::const_iterator& p_transition_start,
	const t_transition_steps::const_iterator& p_transition_end,
	t_execution_steps& p_execution_steps
)
{
	while( p_transition_start != p_transition_end )
	{
		auto l_execution_transition_step = std::make_unique< t_execution_transition_step >( **p_transition_start );
		p_execution_steps.push_back( std::move( l_execution_transition_step ) );
		++p_transition_start;
	}
}


void
t_transition_executor_impl::fill_vector_of_choices
(
	t_raw_const_choices& p_choices,
	const t_compound_transitions& p_compound_transitions
)
{
	for( auto& l_compound_transition : p_compound_transitions )
	{
		const auto l_choice = dynamic_cast< const i_choice* >( &l_compound_transition->get_last_target() );
		if( l_choice )
		{
			Y_LOG( t_log_level::LL_INFO, "Found one choice ( '%' ).", l_choice->get_name() );
			p_choices.push_back( l_choice );
		}

		Y_LOG( t_log_level::LL_INFO, "Fill vector of choices for one compound transition." );
		fill_vector_of_choices( p_choices, l_compound_transition->get_sub_compound_transitions() );
		Y_LOG( t_log_level::LL_INFO, "Found % choice(s) for one compound transition.", p_choices.size() );
	}
}


void
t_transition_executor_impl::find_all_states_to_enter_and_exit
(
	i_compound_transition& l_new_compound_transition,
	t_raw_const_region_set& p_entered_regions,
	const i_event& p_event
)
{
	t_raw_states_by_nesting_level_ascending l_states_to_exit = {};
	Y_LOG( t_log_level::LL_INFO, "Find state(s) to exit." );
	find_all_states_to_exit( l_new_compound_transition, l_states_to_exit );
	Y_LOG( t_log_level::LL_INFO, "Found % state(s) to exit.", l_states_to_exit.size() );

	t_raw_states_by_nesting_level l_states_to_enter = {};

	Y_LOG( t_log_level::LL_INFO, "Find state(s) to enter." );
	find_all_states_to_enter( l_new_compound_transition, l_states_to_enter, p_entered_regions, p_event );
	Y_LOG( t_log_level::LL_INFO, "Found % state(s) to enter.", l_states_to_enter.size() );
}


void
t_transition_executor_impl::find_states_to_enter_and_to_exit_and_calculate_execution_steps
(
	i_compound_transition_consumer& p_compound_transition,
	t_execution_steps& p_execution_steps,
	t_raw_const_region_set& p_entered_regions,
	const i_event& p_event
)
{
	t_raw_states_by_nesting_level_ascending l_states_to_exit = {};
	Y_LOG( t_log_level::LL_TRACE, "Find state(s) to exit." );
	find_all_states_to_exit( p_compound_transition, l_states_to_exit );
	Y_LOG( t_log_level::LL_TRACE, "Found % state(s) to exit.", l_states_to_exit.size() );

	t_raw_states_by_nesting_level l_states_to_enter = {};

	Y_LOG( t_log_level::LL_TRACE, "Find state(s) to enter." );
	find_all_states_to_enter( p_compound_transition, l_states_to_enter, p_entered_regions, p_event );
	Y_LOG( t_log_level::LL_TRACE, "Found % state(s) to enter.", l_states_to_enter.size() );

	Y_LOG( t_log_level::LL_TRACE, "Calculate the execution step(s)." );
	calculate_execution_steps( p_compound_transition, l_states_to_exit, l_states_to_enter, p_execution_steps, p_entered_regions, p_event );
	Y_LOG( t_log_level::LL_TRACE, "% execution step(s) calculated.", p_execution_steps.size() );
}


void
t_transition_executor_impl::check_conflicts_from_source_state_up_to_LCA
(
	const i_state& p_state,
	t_raw_const_state_set& p_unique_exit_states,
	const i_composite_state* p_LCA
) const
{
	Y_LOG( t_log_level::LL_TRACE, "Checking conflicts from source '%' up to lca '%'.", p_state.get_name(), p_LCA->get_name() );

	const auto insert_result = p_unique_exit_states.insert( &p_state );
	if( !insert_result.second )
	{
		LOG_AND_THROW( t_log_level::LL_FATAL, "There are conflicts. The intersection of states '%' and '%' is not empty.", p_state.get_name(), p_LCA->get_name() );
	}
	else
	{
		Y_LOG( t_log_level::LL_TRACE, "There are no conflicts. The intersection of states '%' and '%' is empty.", p_state.get_name(), p_LCA->get_name() );
	}

	Y_ASSERT( p_state.get_parent_region(), "State has no parent region!" );
	auto& l_parent_state = p_state.get_parent_region()->get_parent_state();
	Y_LOG( t_log_level::LL_SPAM, "Parent state of the state '%' is '%'.", p_state.get_name(), l_parent_state.get_name() );

	if( &l_parent_state != p_LCA )
	{
		check_conflicts_from_source_state_up_to_LCA( l_parent_state, p_unique_exit_states, p_LCA );
	}
}


}


}
