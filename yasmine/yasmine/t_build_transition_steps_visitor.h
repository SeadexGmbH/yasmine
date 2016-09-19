//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_BUILD_TRANSITION_STEPS_VISITOR_H
#define T_BUILD_TRANSITION_STEPS_VISITOR_H


#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_transition_step_fwd.h"
#include "i_transition_fwd.h"


namespace sxy
{


class i_transition;																															
class i_pseudostate;
class i_history;
class i_event;


class t_build_transition_steps_visitor final: public virtual i_const_vertex_visitor
{
public:
	t_build_transition_steps_visitor
	(
		i_transition& p_current_transition,
		t_transition_steps& p_transitions_steps,
		const i_event& p_event
	);


	virtual
	~t_build_transition_steps_visitor
	(
	) override;


	t_build_transition_steps_visitor
	(
		const t_build_transition_steps_visitor&
	) = delete;


	t_build_transition_steps_visitor&
	operator=
	(
		const t_build_transition_steps_visitor&
	) = delete;


	virtual void
	visit
	(
		const i_composite_state& p_composite_state
	) override;


	virtual void
	visit
	(
		const i_simple_state& p_simple_state
	) override;


	virtual void
	visit
	(
		const i_final_state& p_final_state
	) override;


	virtual void
	visit
	(
		const i_initial_pseudostate& p_initial_pseudostate
	) override;


	virtual void
	visit
	(
		const i_choice& p_choice
	) override;


	virtual void
	visit
	(
		const i_junction& p_junction
	) override;


	virtual void
	visit
	(
		const i_join& p_join
	) override;


	virtual void
	visit
	(
		const i_fork& p_fork
	) override;


	virtual void
	visit
	(
		const i_entry_point& p_entry_point
	) override;


	virtual void
	visit
	(
		const i_exit_point& p_exit_point
	) override;


	virtual void
	visit
	(
		const i_deep_history& p_deep_history
	) override;


	virtual void
	visit
	(
		const i_shallow_history& p_shallow_history
	) override;


	virtual void
	visit
	(
		const i_terminate_pseudostate& p_terminate_pseudostate
	) override;
	
	
	i_transition*
	get_next_transition
	(
	) const;


	bool
	reached_end_of_transition
	(
	) const;


private:
	i_transition*
	find_next_transition
	(
		const i_pseudostate& p_target_pseudostate,
		const i_event& p_event
	);


	static t_raw_transitions
	get_default_transition_if_state_was_not_active_before
	(
		const i_history& p_history
	);


	void
	handle_history_pseudostate
	(
		const i_history& p_history_pseudostate
	);


	void
	handle_as_junction
	(
		const i_pseudostate& p_pseudostate
	);


	void
	handle_as_fork
	(
		const i_pseudostate& p_fork
	) const;


	void
	handle_as_join
	(
		const i_pseudostate& p_pseudostate
	);


	void
	handle_entry_point
	(
		const i_entry_point& p_entry_point
	);


	void
	handle_exit_point
	(
		const i_exit_point& p_exit_point
	);


	void
	create_simple_transition_step
	(
	);


	i_transition& m_current_transition;
	t_transition_steps& m_transition_steps;
	i_transition* m_next_transition;	
	bool m_reached_end_of_transition;
	const i_event& m_event;


};


}


#endif
