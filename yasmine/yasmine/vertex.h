//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERTEX_126F87F3_2278_4867_B69F_ABEE5AB88A61
#define VERTEX_126F87F3_2278_4867_B69F_ABEE5AB88A61


#include "state_machine_element.h"
#include "vertex_fwd.h"
#include "transition_fwd.h"
#include "region_fwd.h"
#include "composite_state_fwd.h"
#include "event_id.h"


namespace sxy
{


class const_vertex_visitor;
class vertex_visitor;
class uri;
class event;


class vertex:
	public virtual state_machine_element
{
public:
	vertex() = default;
	virtual ~vertex() override = default;
	vertex( const vertex& ) = delete;
	vertex& operator=( const vertex& ) = delete;
	virtual void add_outgoing_transition( transition& _outgoing_transition ) = 0;
	virtual void add_incoming_transition( transition& _incoming_transition ) = 0;
	virtual void remove_outgoing_transition( const transition& _outgoing_transition ) = 0;
	virtual void remove_incoming_transition( const transition& _incoming_transition ) = 0;
	virtual const raw_transitions& get_outgoing_transitions() const = 0;
	virtual const raw_transitions& get_incoming_transitions() const = 0;
	virtual raw_regions get_ancestors_as_regions() const = 0;
	virtual raw_composite_states get_ancestors( composite_state* const _final_ancestor ) const = 0;
	virtual transition * search_transition( const event& _event ) const = 0;
	virtual region * LCA_region( const vertex& _target_vertex ) const = 0;
	virtual composite_state * LCA_composite_state( const vertex& _rhs ) const = 0;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const = 0;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) = 0;
	virtual bool check( state_machine_defects& _defects ) const override = 0;
};


}


#endif
