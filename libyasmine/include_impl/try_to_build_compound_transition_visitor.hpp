//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRY_TO_BUILD_COMPOUND_TRANSITION_VISITOR_92B11137_6B55_4D84_9ABB_7EE0FB784120
#define TRY_TO_BUILD_COMPOUND_TRANSITION_VISITOR_92B11137_6B55_4D84_9ABB_7EE0FB784120


#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "compound_transition_fwd.hpp"


namespace sxy
{


class transition;
class event;
class event_collector;


class try_to_build_compound_transition_visitor:
	public const_vertex_visitor
{
public:
	try_to_build_compound_transition_visitor(	transition& _enabled_transition,	
		compound_transitions& _enabled_compound_transitions,	bool& _is_built,	const event& _event, 
		event_collector& _event_collector );
	virtual ~try_to_build_compound_transition_visitor() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(try_to_build_compound_transition_visitor)
	virtual void visit( const composite_state& _composite_state ) SX_OVERRIDE;
	virtual void visit( const simple_state& _simple_state ) SX_OVERRIDE;
	virtual void visit( const final_state& _final_state ) SX_OVERRIDE;
	virtual void visit( const initial_pseudostate& _initial_pseudostate ) SX_OVERRIDE;
	virtual void visit( const choice& _choice ) SX_OVERRIDE;
	virtual void visit( const junction& _junction ) SX_OVERRIDE;
	virtual void visit( const join& _join ) SX_OVERRIDE;
	virtual void visit( const fork& _fork ) SX_OVERRIDE;
	virtual void visit( const entry_point& _entry_point ) SX_OVERRIDE;
	virtual void visit( const exit_point& _exit_point ) SX_OVERRIDE;
	virtual void visit( const deep_history& _deep_history ) SX_OVERRIDE;
	virtual void visit( const shallow_history& _shallow_history ) SX_OVERRIDE;
	virtual void visit( const terminate_pseudostate& _terminate_pseudostate ) SX_OVERRIDE;


private:
	void build_compound_transition_and_insert_in_container();
	void check_if_join_is_active_and_was_not_processed_yet( const join& _join );
	static bool check_if_transition_was_already_used(	const transition& _transition,	
		compound_transitions& _compound_transitions );


	transition& enabled_transition_;
	compound_transitions& enabled_compound_transitions_;
	bool& is_built_;
	const event& event_;
	event_collector& event_collector_;
};


}


#endif
