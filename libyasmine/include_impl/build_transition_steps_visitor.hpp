//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BUILD_TRANSITION_STEPS_VISITOR_85FF1B04_191D_4BED_A446_C9280A2883C8
#define BUILD_TRANSITION_STEPS_VISITOR_85FF1B04_191D_4BED_A446_C9280A2883C8


#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "transition_step_fwd.hpp"
#include "transition_fwd.hpp"


namespace sxy
{


class transition;
class pseudostate;
class history;
class event;
class event_collector;


class build_transition_steps_visitor Y_FINAL:
	public virtual const_vertex_visitor
{
public:
	build_transition_steps_visitor(	transition& _current_transition,	transition_steps& _transitions_steps,
		const event& _event, event_collector& _event_collector );
	virtual ~build_transition_steps_visitor() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(build_transition_steps_visitor)
	virtual void visit( const composite_state& _composite_state ) Y_OVERRIDE;
	virtual void visit( const simple_state& _simple_state ) Y_OVERRIDE;
	virtual void visit( const final_state& _final_state ) Y_OVERRIDE;
	virtual void visit( const initial_pseudostate& _initial_pseudostate ) Y_OVERRIDE;
	virtual void visit( const choice& _choice ) Y_OVERRIDE;
	virtual void visit( const junction& _junction ) Y_OVERRIDE;
	virtual void visit( const join& _join ) Y_OVERRIDE;
	virtual void visit( const fork& _fork ) Y_OVERRIDE;
	virtual void visit( const entry_point& _entry_point ) Y_OVERRIDE;
	virtual void visit( const exit_point& _exit_point ) Y_OVERRIDE;
	virtual void visit( const deep_history& _deep_history ) Y_OVERRIDE;
	virtual void visit( const shallow_history& _shallow_history ) Y_OVERRIDE;
	virtual void visit( const terminate_pseudostate& _terminate_pseudostate ) Y_OVERRIDE;
	transition * get_next_transition() const;
	bool reached_end_of_transition() const;


private:
	transition* find_next_transition( const pseudostate& _target_pseudostate, const event& _event );
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
	event_collector& event_collector_;
};


}


#endif
