//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TRY_TO_BUILD_COMPOUND_TRANSITION_VISITOR_92B11137_6B55_4D84_9ABB_7EE0FB784120
#define T_TRY_TO_BUILD_COMPOUND_TRANSITION_VISITOR_92B11137_6B55_4D84_9ABB_7EE0FB784120


#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "t_compound_transition_fwd.h"


namespace sxy
{


class i_transition;
class i_event;


class t_try_to_build_compound_transition_visitor: public virtual i_const_vertex_visitor
{
public:
	t_try_to_build_compound_transition_visitor
	(
		i_transition& p_enabled_transition,
		t_compound_transitions& p_enabled_compound_transitions,
		bool& p_is_built,
		const i_event& p_event
	);


	virtual
	~t_try_to_build_compound_transition_visitor
	(
	) override;


	t_try_to_build_compound_transition_visitor
	(
		const t_try_to_build_compound_transition_visitor&
	) = delete;


	t_try_to_build_compound_transition_visitor&
	operator=
	(
		const t_try_to_build_compound_transition_visitor&
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


private:
	void
	build_compound_transition_and_insert_in_container
	(
	);


	void
	check_if_join_is_active_and_was_not_processed_yet
	(
		const i_join& p_join
	);


	static bool
	check_if_transition_was_already_used
	(
		const i_transition& p_transition,
		t_compound_transitions& p_compound_transitions
	);


	i_transition& m_enabled_transition;
	t_compound_transitions& m_enabled_compound_transitions;
	bool& m_is_built;
	const i_event& m_event;


};


}


#endif
