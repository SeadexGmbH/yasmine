//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_JUNCTION_BC0836CF_393C_49D0_ACF2_7BE5EF15BD07
#define T_JUNCTION_BC0836CF_393C_49D0_ACF2_7BE5EF15BD07


#include "i_junction.h"
#include "t_region_pseudostate.h"


namespace sxy
{


class t_junction final:
	public virtual i_junction, public t_region_pseudostate
{
public:
	explicit t_junction( const std::string& p_name );
	virtual ~t_junction() override;
	t_junction( const t_junction& ) = delete;
	t_junction& operator=( const t_junction& ) = delete;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const override;
};


}


#endif
