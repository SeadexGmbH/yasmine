//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_REGION_B29B82DA_571D_4A73_BF97_5E9DCCA916AB
#define T_REGION_B29B82DA_571D_4A73_BF97_5E9DCCA916AB


#include "i_region.h"
#include "t_state_machine_element.h"


namespace sxy
{


class t_region: public virtual i_region, public t_state_machine_element
{
public:
	explicit t_region
	(
		const std::string& p_name
	);
	
	
	virtual
	~t_region
	(
	) override;
	
	
	t_region
	(
		const t_region&
	) = delete;
	
	
	t_region&
	operator=
	(
		const t_region&
	) = delete;


	void
	set_parent_state
	(
		i_composite_state* const p_composite_state
	) override;


	virtual t_raw_const_states
	get_states
	(
	) const override;
	

	virtual const i_composite_state&
	get_parent_state
	(
	) const override;


	virtual i_composite_state&
	get_parent_state
	(
	) override;
	

	virtual i_vertex*
	get_vertex
	(
		const std::string& p_vertex_name
	) const override;


	virtual size_t
	get_pseudostate_count
	(
	) const override;


	virtual i_vertex*
	get_pseudostate
	(
		const std::string& p_name
	) const override;


	virtual t_raw_const_pseudostates
	get_pseudostates
	(
	) const override;


	virtual i_initial_pseudostate*
	get_initial_pseudostate
	(
	) const override;


	virtual size_t
	get_state_count
	(
	) const override;


	virtual i_state*
	get_state
	(
		const std::string& p_name
	) const override;

	
	virtual const i_state*
	get_active_state
	(
	) const override;


	virtual i_state*
	get_active_state
	(
	) override;


	virtual void
	set_active_state
	(
		i_state* const p_active_state
	) override;


	virtual void
	set_state_was_active
	(
		i_state* const p_active_state
	) override;


	virtual const i_state*
	get_last_active_state
	(
	) const override;


	virtual i_state*
	get_last_active_state
	(
	) override;


	virtual i_initial_pseudostate&
	add_initial_pseudostate
	(
		i_initial_pseudostate_uptr p_initial_state
	) override;


	//!\brief Creates an initial pseudostate with the given name and adds it to the parent region.
	//!\param p_initial_state_name Name of the initial pseudostate.	
	//!\return A reference to the newly created initial pseudostate.
	virtual i_initial_pseudostate&
	add_initial_pseudostate
	(
		const std::string& p_initial_state_name
	) override;


	virtual i_state&
	add_state
	(
		i_state_uptr p_state
	) override;


	virtual i_simple_state&
	add_simple_state
	(
		const std::string& p_name,
		const t_behavior_function& p_behavior = t_behavior_function(),
		const t_behavior_function& p_entry_behavior = t_behavior_function(),
		const t_behavior_function& p_exit_behavior = t_behavior_function()
	) override;


	virtual i_simple_state&
	add_simple_state
	(
		const std::string& p_name,
		const t_event_ids& p_deferred_events,
		const t_behavior_function& p_behavior = t_behavior_function(),
		const t_behavior_function& p_entry_behavior = t_behavior_function(),
		const t_behavior_function& p_exit_behavior = t_behavior_function()
	) override;


	virtual i_composite_state&	
	add_composite_state
	(
		const std::string& p_name,
		const t_behavior_function& p_entry_action = t_behavior_function(),
		const t_behavior_function& p_exit_action = t_behavior_function()
	) override;


	virtual i_composite_state&
	add_composite_state
	(
		const std::string& p_name,
		const t_event_ids& p_deferred_events,
		const t_behavior_function& p_entry_action = t_behavior_function(),
		const t_behavior_function& p_exit_action = t_behavior_function()
	) override;


	virtual i_final_state&
	add_final_state
	(
		const std::string& p_name
	) override;



	virtual i_choice&
	add_choice
	(
		i_choice_uptr p_choice
	) override;


	//!\brief Creates a choice with the given name and adds it to the parent region.
	//!\param p_choice_name Name of the choice.	
	//!\return A reference to the newly created choice.
	virtual i_choice&
	add_choice
	(
		const std::string& p_choice_name
	) override;


	virtual i_fork&
	add_fork
	(
		i_fork_uptr p_fork
	) override;


	//!\brief Creates a fork with the given name and adds it to the parent region.
	//!\param p_fork_name Name of the fork.	
	//!\return A reference to the newly created fork.
	virtual i_fork&
	add_fork
	(
		const std::string& p_fork_name
	) override;


	virtual i_join&
	add_join
	(
		i_join_uptr p_join
	) override;


	//!\brief Creates a join with the given name and adds it to the parent region.
	//!\param p_join_name Name of the join.
	//!\return A reference to the newly created join.
	virtual i_join&
	add_join
	(
		const std::string& p_join_name
	) override;


	virtual i_junction&
	add_junction
	(
		i_junction_uptr p_junction
	) override;


	//!\brief Creates a junction with the given name and adds it to the parent region.
	//!\param p_junction_name Name of the junction.	
	//!\return A reference to the newly created junction.
	virtual i_junction&
	add_junction
	(
		const std::string& p_junction_name
	) override;


	virtual i_terminate_pseudostate&
	add_terminate_pseudostate
	(
		const i_terminate_pseudostate_uptr p_terminate_pseudostate
	) override;


	//!\brief Creates a terminate pseudostate with the given name and adds it to the parent region.
	//!\param p_terminate_pseudostate_name Name of the terminate pseudostate.	
	//!\return A reference to the newly created terminate pseudostate.
	virtual i_terminate_pseudostate&
	add_terminate_pseudostate
	(
		const std::string& p_terminate_pseudostate_name
	) override;


	t_uri
	get_uri
	(
	) const override;


	void
	add_ancestor_uri
	(
		t_uri& p_uri
	)	const override;
 

	virtual bool
	is_active_state_final
	(
	) const override;


	virtual bool
	check
	(
		t_state_machine_defects& p_defects
	) const override;


private:	
	i_composite_state* m_parent_state;
	t_states m_states;
	t_pseudostates m_pseudostates;
	i_initial_pseudostate* m_initial_pseudostate;	
	i_state* m_active_state;
	i_state* m_last_active_state;
};


}


#endif
