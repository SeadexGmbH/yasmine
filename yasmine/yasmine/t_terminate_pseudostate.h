//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TERMINATE_PSEUDOSTATE_31365C4B_E657_4227_B9C1_D14A3A6B01EB
#define T_TERMINATE_PSEUDOSTATE_31365C4B_E657_4227_B9C1_D14A3A6B01EB


#include "i_terminate_pseudostate.h"
#include "t_region_pseudostate.h"


namespace sxy
{


class t_terminate_pseudostate final:
	public virtual i_terminate_pseudostate, public t_region_pseudostate
{
public:
	explicit t_terminate_pseudostate( const std::string& p_name );
	virtual ~t_terminate_pseudostate() override;
	t_terminate_pseudostate( const t_terminate_pseudostate& ) = delete;
	t_terminate_pseudostate& operator=( const t_terminate_pseudostate& ) = delete;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const override;
	virtual void add_outgoing_transition( i_transition& p_outgoing_transition ) override;
};


}


#endif
