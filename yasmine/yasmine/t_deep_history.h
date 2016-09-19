//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_DEEP_HISTORY_13FD682E_D549_4934_A7E9_106EF0B390FA
#define T_DEEP_HISTORY_13FD682E_D549_4934_A7E9_106EF0B390FA


#include "i_deep_history.h"
#include "t_history.h"


namespace sxy
{


class t_deep_history final:
	public virtual i_deep_history, public t_history
{
public:
	explicit t_deep_history( const std::string& p_name );
	virtual ~t_deep_history() override;
	t_deep_history( const t_deep_history& ) = delete;
	t_deep_history& operator=( const t_deep_history& ) = delete;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const override;
};


}


#endif
