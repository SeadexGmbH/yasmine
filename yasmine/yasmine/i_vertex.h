//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_VERTEX_126F87F3_2278_4867_B69F_ABEE5AB88A61
#define I_VERTEX_126F87F3_2278_4867_B69F_ABEE5AB88A61


#include "i_state_machine_element.h"
#include "i_vertex_fwd.h"
#include "i_transition_fwd.h"
#include "i_region_fwd.h"
#include "i_composite_state_fwd.h"
#include "t_event_id.h"


namespace sxy
{


class i_const_vertex_visitor;
class i_vertex_visitor;
class t_uri;
class i_event;


class i_vertex:
	public virtual i_state_machine_element
{
public:
	i_vertex() = default;
	virtual ~i_vertex() override = default;
	i_vertex( const i_vertex& ) = delete;
	i_vertex& operator=( const i_vertex& ) = delete;
	virtual void add_outgoing_transition( i_transition& p_outgoing_transition ) = 0;
	virtual void add_incoming_transition( i_transition& p_incoming_transition ) = 0;
	virtual void remove_outgoing_transition( const i_transition& p_outgoing_transition ) = 0;
	virtual void remove_incoming_transition( const i_transition& p_incoming_transition ) = 0;
	virtual const t_raw_transitions& get_outgoing_transitions() const = 0;
	virtual const t_raw_transitions& get_incoming_transitions() const = 0;
	virtual t_raw_regions get_ancestors_as_regions() const = 0;
	virtual t_raw_composite_states get_ancestors( i_composite_state* const p_final_ancestor ) const = 0;
	virtual i_transition * search_transition( const i_event& p_event ) const = 0;
	virtual i_region * LCA_region( const i_vertex& p_target_vertex ) const = 0;
	virtual i_composite_state * LCA_composite_state( const i_vertex& p_rhs ) const = 0;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const = 0;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) = 0;
	virtual bool check( t_state_machine_defects& p_defects ) const override = 0;
};


}


#endif
