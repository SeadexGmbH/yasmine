//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERTEX_126F87F3_2278_4867_B69F_ABEE5AB88A61
#define VERTEX_126F87F3_2278_4867_B69F_ABEE5AB88A61


#include "state_machine_element.hpp"
#include "vertex_fwd.hpp"
#include "transition_fwd.hpp"
#include "region_fwd.hpp"
#include "composite_state_fwd.hpp"
#include "event_id.hpp"
#include "event_priority.hpp"


namespace sxy
{


class const_vertex_visitor;
class vertex_visitor;
class uri;
class event;
class event_collector;


class vertex:
	public virtual state_machine_element
{
public:
	vertex()
	{
		// Nothing to do...
	}


	virtual ~vertex() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( vertex )
	virtual composite_state* get_root_state() = 0;
	virtual const composite_state* get_root_state() const = 0;
	virtual void add_outgoing_transition( transition& _outgoing_transition ) = 0;
	virtual void add_incoming_transition( transition& _incoming_transition ) = 0;
	virtual void remove_outgoing_transition( const transition& _outgoing_transition ) = 0;
	virtual void remove_incoming_transition( const transition& _incoming_transition ) = 0;
	virtual const raw_transitions& get_outgoing_transitions() const = 0;
	virtual const raw_transitions& get_incoming_transitions() const = 0;
	virtual raw_regions get_ancestors_as_regions() const = 0;
	virtual raw_composite_states get_ancestors( composite_state* const _final_ancestor, 
		bool _include_final_ancestor = true ) const = 0;
	virtual transition * search_transition( const event& _event, event_collector& _event_collector ) const = 0;
	virtual region * LCA_region( const vertex& _target_vertex ) const = 0;
	virtual composite_state * LCA_composite_state( const vertex& _rhs ) const = 0;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const = 0;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) = 0;
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE = 0;
};


}


#endif
