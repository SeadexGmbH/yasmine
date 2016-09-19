//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_INITIAL_PSEUDOSTATE_204C4E8B_25BE_4315_8F70_D0F35DD02074
#define T_INITIAL_PSEUDOSTATE_204C4E8B_25BE_4315_8F70_D0F35DD02074


#include "i_initial_pseudostate.h"
#include "t_region_pseudostate.h"


namespace sxy
{


class t_initial_pseudostate final:
	public virtual i_initial_pseudostate, public t_region_pseudostate
{
public:
	explicit t_initial_pseudostate( const std::string& p_name );
	virtual ~t_initial_pseudostate() override;
	t_initial_pseudostate( const t_initial_pseudostate& ) = delete;
	t_initial_pseudostate& operator=( const t_initial_pseudostate& ) = delete;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const override;
	virtual i_transition * get_transition() const override;
	virtual void add_incoming_transition( i_transition& p_incoming_transition ) override;
};


}


#endif
