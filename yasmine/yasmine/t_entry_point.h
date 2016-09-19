//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_ENTRY_POINT_B4BD7BED_1393_4B24_82D2_BEB2392EAF83
#define T_ENTRY_POINT_B4BD7BED_1393_4B24_82D2_BEB2392EAF83


#include "i_entry_point.h"
#include "t_state_pseudostate.h"


namespace sxy
{


class t_vertex_visitor;


class t_entry_point final:
	public virtual i_entry_point, public t_state_pseudostate
{
public:
	explicit t_entry_point( const std::string& p_name );
	virtual ~t_entry_point() override;
	t_entry_point( const t_entry_point& ) = delete;
	t_entry_point& operator=( const t_entry_point& ) = delete;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const override;
};


}


#endif
