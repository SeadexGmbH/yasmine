//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_REGION_06648EA9_E80A_49B8_9814_1723273908D2
#define I_REGION_06648EA9_E80A_49B8_9814_1723273908D2


#include "i_state_machine_element.h"
#include "i_state_fwd.h"
#include "i_region_fwd.h"
#include "i_pseudostate_fwd.h"
#include "i_initial_pseudostate_fwd.h"
#include "i_choice_fwd.h"
#include "i_fork_fwd.h"
#include "i_join_fwd.h"
#include "i_junction_fwd.h"
#include "i_terminate_pseudostate_fwd.h"
#include "i_behavior_fwd.h"
#include "t_event_id.h"



namespace sxy
{


class i_vertex;
class i_composite_state;
class i_simple_state;
class i_final_state;


class i_region : public virtual i_state_machine_element
{
public:
	i_region
	(
	) = default;


	virtual
	~i_region
	(
	) override = default;


	i_region
	(
		const i_region&
	) = delete;


	i_region&
	operator=
	(
		const i_region&
	) = delete;


	virtual void
	set_parent_state
	(
		i_composite_state* const p_composite_state
	) = 0;


	virtual const i_composite_state&
	get_parent_state
	(
	) const = 0;


	virtual i_composite_state&
	get_parent_state
	(
	) = 0;


	virtual t_raw_const_states
	get_states
	(
	) const = 0;
	

	virtual size_t
	get_pseudostate_count
	(
	) const = 0;


	virtual i_vertex*
	get_pseudostate
	(
		const std::string& p_name
	) const = 0;
	

	virtual i_vertex*
	get_vertex
	(
		const std::string& p_vertex_name
	) const = 0;

	
	virtual t_raw_const_pseudostates
	get_pseudostates
	(
	) const = 0;


	virtual i_initial_pseudostate*
	get_initial_pseudostate
	(
	) const = 0;


	virtual i_initial_pseudostate&
	add_initial_pseudostate
	(
		i_initial_pseudostate_uptr p_initial_state
	) = 0;


	virtual i_initial_pseudostate&
	add_initial_pseudostate
	(
		const std::string& p_initial_state_name
	) = 0;


	virtual i_state&
	add_state
	(
		i_state_uptr p_state
	) = 0;


	virtual i_choice&
	add_choice
	(
		i_choice_uptr p_choice
	) = 0;


	virtual i_choice&
	add_choice
	(
		const std::string& p_choice_name
	) = 0;


	virtual i_fork&
	add_fork
	(
		i_fork_uptr p_fork
	) = 0;


	virtual i_fork&
	add_fork
	(
		const std::string& p_fork_name
	) = 0;


	virtual i_join&
	add_join
	(
		i_join_uptr p_join
	) = 0;


	virtual i_join&
	add_join
	(
		const std::string& p_join_name
	) = 0;


	virtual i_junction&
	add_junction
	(
		i_junction_uptr p_junction
	) = 0;


	virtual i_junction&
	add_junction
	(
		const std::string& p_junction_name
	) = 0;


	virtual i_terminate_pseudostate&
	add_terminate_pseudostate
	(
		const i_terminate_pseudostate_uptr p_terminate_pseudostate
	) = 0;


	virtual i_terminate_pseudostate&
	add_terminate_pseudostate
	(
		const std::string& p_terminate_pseudostate_name
	) = 0;


	virtual i_simple_state&
	add_simple_state
	(
		const std::string& p_name, 
		const t_behavior_function& p_behavior = t_behavior_function(),
		const t_behavior_function& p_entry_behavior = t_behavior_function(),
		const t_behavior_function& p_exit_behavior = t_behavior_function()
	) = 0;


	virtual i_simple_state&
	add_simple_state
	(
		const std::string& p_name,
		const t_event_ids& p_deferred_events,
		const t_behavior_function& p_behavior = t_behavior_function(),
		const t_behavior_function& p_entry_behavior = t_behavior_function(),
		const t_behavior_function& p_exit_behavior = t_behavior_function()
	) = 0;


	virtual i_composite_state&
	add_composite_state
	(
		const std::string& p_name,
		const t_behavior_function& p_entry_action = t_behavior_function(),
		const t_behavior_function& p_exit_action = t_behavior_function()
	) = 0;


	virtual i_composite_state&
	add_composite_state
	(
		const std::string& p_name,
		const t_event_ids& p_deferred_events,
		const t_behavior_function& p_entry_action = t_behavior_function(),
		const t_behavior_function& p_exit_action = t_behavior_function()
	) = 0;


	virtual i_final_state&
	add_final_state
	(
		const std::string& p_name
	) = 0;


	virtual size_t
	get_state_count
	(
	) const = 0;


	virtual i_state*
	get_state
	(
		const std::string& p_name
	) const = 0;


	virtual const i_state*
	get_active_state
	(
	) const = 0;


	virtual i_state*
	get_active_state
	(
	) = 0;


	virtual void
	set_active_state
	(			
		i_state* const p_active_state
	) = 0;


	virtual void
	set_state_was_active
	(
		i_state* const p_active_state
	) = 0;


	virtual const i_state*
	get_last_active_state
	(
	) const = 0;


	virtual i_state*
	get_last_active_state
	(
	) = 0;


	virtual bool
	is_active_state_final
	(
	) const = 0;

		
	virtual bool
	check
	(
		t_state_machine_defects& p_defects
	) const override = 0;
};


}


#endif
