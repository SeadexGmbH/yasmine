//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_EXIT_POINT_F7A1E78B_D3FB_4B47_9400_62AF44527456
#define T_EXIT_POINT_F7A1E78B_D3FB_4B47_9400_62AF44527456


#include "i_exit_point.h"
#include "t_state_pseudostate.h"


namespace sxy
{


class t_exit_point final:
	public virtual i_exit_point, public t_state_pseudostate
{
public:
	explicit t_exit_point( const std::string& p_name );
	virtual ~t_exit_point() override;
	t_exit_point( const t_exit_point& ) = delete;
	t_exit_point& operator=( const t_exit_point& ) = delete;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const override;
};


}


#endif
