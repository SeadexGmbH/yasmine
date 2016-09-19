//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TRANSITION_EXECUTOR_IMPL_040388C2_842E_4A0A_B854_6FCFB61F3988
#define T_TRANSITION_EXECUTOR_IMPL_040388C2_842E_4A0A_B854_6FCFB61F3988


#include "i_state_fwd.h"
#include "i_region_fwd.h"
#include "i_choice_fwd.h"
#include "t_compound_transition_fwd.h"
#include "i_transition_step_fwd.h"
#include "i_execution_step_fwd.h"


namespace sxy
{


class i_event_processing_callback;
class i_event;
class i_composite_state;


namespace impl
{


class t_transition_executor_impl
{


public:
	t_transition_executor_impl
	(
	);


	~t_transition_executor_impl
	(
	);


	t_transition_executor_impl
	(
		const t_transition_executor_impl&
	) = delete;


	t_transition_executor_impl&
	operator=
	(
		const t_transition_executor_impl&
	) = delete;


	void
	get_active_states_from_region
	(
		i_region& p_region,
		t_raw_states_by_nesting_level_ascending& p_states
	);


	void
	get_active_states_from_regions
	(
		const i_state* const p_state,
		t_raw_states_by_nesting_level_ascending& p_states
	);


	void
	get_all_states_to_enter_from_regions_that_are_not_explicitly_entered
	(
		i_compound_transition_consumer& p_compound_transition,
		t_raw_const_region_set& p_entered_regions,
		t_raw_states_by_nesting_level& p_states_to_enter,
		const i_event& p_event
	);


	void
	merge_transitions_steps_with_exit_state_steps
	(
		t_execution_steps& p_execution_steps,
		i_compound_transition_consumer& p_compound_transition,
		const t_raw_states_by_nesting_level_ascending& p_states_to_exit,
		t_transition_steps::const_iterator& p_transition_start,
		t_transition_steps::const_iterator& p_transition_end
	);


	void
	merge_transitions_steps_with_enter_states_steps
	(
		t_execution_steps& p_execution_steps,
		i_compound_transition_consumer& p_compound_transition,
		const t_raw_states_by_nesting_level& p_states_to_enter,
		t_transition_steps::const_iterator& p_transition_start,
		t_transition_steps::const_iterator& p_transition_end
	);


	void
	calculate_execution_steps
	(
		i_compound_transition_consumer& p_compound_transition,
		const t_raw_states_by_nesting_level_ascending& p_states_to_exit,
		const t_raw_states_by_nesting_level& p_states_to_enter,
		t_execution_steps& p_execution_steps,
		t_raw_const_region_set& p_entered_regions,
		const i_event& p_event
	);


	static bool
	run_execution_steps
	(
		const t_execution_steps& p_execution_steps,
		i_event_processing_callback* const p_event_processing_callback,
		const i_event& p_event
	);


	void
	conflict_check
	(
		const t_compound_transitions& p_compound_transitions
	) const;


	static t_raw_compound_transitions
	sort_compound_transitions
	(
		const t_compound_transitions& p_unsorted_compound_transitions
	);


	void
	find_all_states_to_exit
	(
		i_compound_transition_consumer& p_compound_transition,
		t_raw_states_by_nesting_level_ascending& p_states_to_exit
	);


	void
	find_all_states_to_enter
	(
		i_compound_transition_consumer& p_compound_transition,
		t_raw_states_by_nesting_level& p_states_to_enter,
		t_raw_const_region_set& p_regions_to_enter,
		const i_event& p_event
	);


	void
	add_remaining_states_to_enter
	(
		const t_raw_states_by_nesting_level::const_iterator p_state_start,
		const t_raw_states_by_nesting_level& p_states_to_enter,
		t_execution_steps &p_execution_steps
	);


	void
	add_remaining_states_to_exit
	(
		const t_raw_states_by_nesting_level_ascending::const_iterator p_state_start,
		const t_raw_states_by_nesting_level_ascending& p_states,
		t_execution_steps& p_execution_steps
	);


	void
	add_remained_transitions
	(
		t_transition_steps::const_iterator& p_transition_start,
		const t_transition_steps::const_iterator& p_transition_end,
		t_execution_steps& p_execution_steps
	);


	void
	fill_vector_of_choices
	(
		t_raw_const_choices& p_choices,
		const t_compound_transitions& p_compound_transitions
	);


	void
	find_all_states_to_enter_and_exit
	(
		i_compound_transition& l_new_compound_transition,
		t_raw_const_region_set& p_entered_regions,
		const i_event& p_event
	);


	void
	find_states_to_enter_and_to_exit_and_calculate_execution_steps
	(
		i_compound_transition_consumer& compound_transition,
		t_execution_steps& p_execution_steps,
		t_raw_const_region_set& p_entered_regions,
		const i_event& p_event
	);


	void
	check_conflicts_from_source_state_up_to_LCA
	(
		const i_state& p_state,
		t_raw_const_state_set& p_unique_exit_states,
		const i_composite_state* p_LCA
	) const;


private:
};


}


}


#endif
