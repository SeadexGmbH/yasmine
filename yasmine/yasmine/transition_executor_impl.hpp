//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_EXECUTOR_IMPL_D556EFC8_A5CE_4750_96D9_BDDBF8FFF10A
#define TRANSITION_EXECUTOR_IMPL_D556EFC8_A5CE_4750_96D9_BDDBF8FFF10A


#include "state_fwd.hpp"
#include "region_fwd.hpp"
#include "choice_fwd.hpp"
#include "compound_transition_fwd.hpp"
#include "transition_step_fwd.hpp"
#include "execution_step_fwd.hpp"
#include "behaviour_exception_fwd.hpp"
#include "event_fwd.hpp"
#include "non_copyable.hpp"


namespace sxy
{


class event_processing_callback;
class composite_state;
class async_event_handler;


namespace impl
{


class transition_executor_impl
{
public:
	transition_executor_impl();
	virtual ~transition_executor_impl() Y_NOEXCEPT;
	Y_NO_COPY(transition_executor_impl)
	void get_active_states_from_region( region& _region, raw_states_by_nesting_level_ascending& _states );
	void get_active_states_from_regions( const state* const _state, 
		raw_states_by_nesting_level_ascending& _states );
	void get_all_states_to_enter_from_regions_that_are_not_explicitly_entered( 
		compound_transition_consumer& _compound_transition, raw_const_region_set& _entered_regions,
		raw_states_by_nesting_level& _states_to_enter, const event& _event );
	void merge_transitions_steps_with_exit_state_steps( execution_steps& _execution_steps,
		compound_transition_consumer& _compound_transition, 
		const raw_states_by_nesting_level_ascending& _states_to_exit, 
		transition_steps::const_iterator& _transition_start, transition_steps::const_iterator& _transition_end );
	void merge_transitions_steps_with_enter_states_steps( execution_steps& _execution_steps, 
		compound_transition_consumer& _compound_transition, const raw_states_by_nesting_level& _states_to_enter,
		transition_steps::const_iterator& _transition_start, transition_steps::const_iterator& _transition_end );
	void calculate_execution_steps( compound_transition_consumer& _compound_transition,
		const raw_states_by_nesting_level_ascending& _states_to_exit, 
		const raw_states_by_nesting_level& _states_to_enter, execution_steps& _execution_steps,
		raw_const_region_set& _entered_regions, const event& _event );
	static bool run_execution_steps( const execution_steps& _execution_steps, 
		event_processing_callback* const _event_processing_callback, const event& _event, 
		events& _exception_events, async_event_handler* const _async_event_handler );
	void conflict_check( const compound_transitions& _compound_transitions ) const;
	static raw_compound_transitions sort_compound_transitions( 
		const compound_transitions& _unsorted_compound_transitions );
	void find_all_states_to_exit( compound_transition_consumer& _compound_transition,
		raw_states_by_nesting_level_ascending& _states_to_exit );
	void find_all_states_to_enter( compound_transition_consumer& _compound_transition, 
		raw_states_by_nesting_level& _states_to_enter, raw_const_region_set& _regions_to_enter, const event& _event );
	void add_remaining_states_to_enter( const raw_states_by_nesting_level::const_iterator _state_start,
		const raw_states_by_nesting_level& _states_to_enter, execution_steps& _execution_steps );
	void add_remaining_states_to_exit( const raw_states_by_nesting_level_ascending::const_iterator _state_start,
		const raw_states_by_nesting_level_ascending& _states, execution_steps& _execution_steps );
	void add_remained_transitions( transition_steps::const_iterator& _transition_start,
		const transition_steps::const_iterator& _transition_end, execution_steps& _execution_steps );
	void fill_vector_of_choices( raw_const_choices& _choices, const compound_transitions& _compound_transitions );
	void find_all_states_to_enter_and_exit( compound_transition& new_compound_transition,
		raw_const_region_set& _entered_regions, const event& _event );
	void find_states_to_enter_and_to_exit_and_calculate_execution_steps( 
		compound_transition_consumer& compound_transition, execution_steps& _execution_steps, 
		raw_const_region_set& _entered_regions, const event& _event );
	void check_conflicts_from_source_state_to_LCA( const state& _state, raw_const_state_set& _unique_exit_states,
		const composite_state* _LCA ) const;
};


}
}

#endif
