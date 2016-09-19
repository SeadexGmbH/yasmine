//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_JOIN_6F104C2D_43B7_4CED_AB9E_86BA15E16996
#define T_JOIN_6F104C2D_43B7_4CED_AB9E_86BA15E16996


#include "i_join.h"
#include "t_region_pseudostate.h"

namespace sxy
{


class t_join final:
	public virtual i_join, public t_region_pseudostate
{
public:
	explicit t_join( const std::string& p_name );
	virtual ~t_join() override;
	t_join( const t_join& ) = delete;
	t_join& operator=( const t_join& ) = delete;
	virtual bool check_if_all_source_states_of_incoming_transitions_are_active() const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const override;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void add_outgoing_transition( i_transition& p_outgoing_transition ) override;
};


}


#endif
