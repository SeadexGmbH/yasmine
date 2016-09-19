//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BUILD_TRANSITION_STEPS_VISITOR_85FF1B04_191D_4BED_A446_C9280A2883C8
#define BUILD_TRANSITION_STEPS_VISITOR_85FF1B04_191D_4BED_A446_C9280A2883C8


#include "const_vertex_visitor.h"
#include "vertex_visitor.h"
#include "transition_step_fwd.h"
#include "transition_fwd.h"


namespace sxy
{


class transition;
class pseudostate;
class history;
class event;


class build_transition_steps_visitor final:
	public virtual const_vertex_visitor
{
public:
	build_transition_steps_visitor(	transition& _current_transition,	transition_steps& _transitions_steps,
		const event& _event );
	virtual ~build_transition_steps_visitor() override;
	build_transition_steps_visitor( const build_transition_steps_visitor& ) = delete;
	build_transition_steps_visitor& operator=( const build_transition_steps_visitor& ) = delete;
	virtual void visit( const composite_state& _composite_state ) override;
	virtual void visit( const simple_state& _simple_state ) override;
	virtual void visit( const final_state& _final_state ) override;
	virtual void visit( const initial_pseudostate& _initial_pseudostate ) override;
	virtual void visit( const choice& _choice ) override;
	virtual void visit( const junction& _junction ) override;
	virtual void visit( const join& _join ) override;
	virtual void visit( const fork& _fork ) override;
	virtual void visit( const entry_point& _entry_point ) override;
	virtual void visit( const exit_point& _exit_point ) override;
	virtual void visit( const deep_history& _deep_history ) override;
	virtual void visit( const shallow_history& _shallow_history ) override;
	virtual void visit( const terminate_pseudostate& _terminate_pseudostate ) override;
	transition * get_next_transition() const;
	bool reached_end_of_transition() const;


private:
	transition * find_next_transition( const pseudostate& _target_pseudostate,	const event& _event );
	static raw_transitions get_default_transition_if_state_was_not_active_before( const history& _history );
	void handle_history_pseudostate( const history& _history_pseudostate );
	void handle_as_junction( const pseudostate& _pseudostate );
	void handle_as_fork( const pseudostate& _fork ) const;
	void handle_as_join( const pseudostate& _pseudostate );
	void handle_entry_point( const entry_point& _entry_point );
	void handle_exit_point( const exit_point& _exit_point );
	void create_simple_transition_step();


	transition& current_transition_;
	transition_steps& transition_steps_;
	transition* next_transition_;
	bool reached_end_of_transition_;
	const event& event_;
};


}


#endif
