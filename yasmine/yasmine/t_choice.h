//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_CHOICE_0F1CBE30_ECBB_4B29_ACCB_876AD3A821A1
#define T_CHOICE_0F1CBE30_ECBB_4B29_ACCB_876AD3A821A1


#include "i_choice.h"
#include "t_region_pseudostate.h"


namespace sxy
{


class t_choice final:
	public virtual i_choice, public t_region_pseudostate
{
public:
	explicit t_choice( const std::string& p_name );
	virtual ~t_choice() override;
	t_choice( const t_choice& ) = delete;
	t_choice& operator=( const t_choice& ) = delete;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const override;
};


}


#endif
