//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_SHALLOW_HISTORY_B662C9B1_431B_4EEB_8F8B_CCA98B34D7DF
#define T_SHALLOW_HISTORY_B662C9B1_431B_4EEB_8F8B_CCA98B34D7DF


#include "i_shallow_history.h"
#include "t_history.h"


namespace sxy
{


class t_shallow_history:
	public virtual i_shallow_history, public t_history
{
public:
	explicit t_shallow_history( const std::string& p_name );
	virtual ~t_shallow_history() override;
	t_shallow_history( const t_shallow_history& ) = delete;
	t_shallow_history& operator=( const t_shallow_history& ) = delete;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const override;
};


}


#endif
