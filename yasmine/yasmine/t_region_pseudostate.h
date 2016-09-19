//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_REGION_PSEUDOSTATE_3D777EF6_CDB6_47EB_A57F_0536365353CB
#define T_REGION_PSEUDOSTATE_3D777EF6_CDB6_47EB_A57F_0536365353CB


#include "i_region_pseudostate.h"
#include "t_pseudostate.h"


namespace sxy
{


class t_region_pseudostate:
	public virtual i_region_pseudostate, public t_pseudostate
{
public:
	explicit t_region_pseudostate( const std::string& p_name );
	virtual ~t_region_pseudostate() override;
	virtual const i_state_machine_element * get_parent() const override;
	virtual i_region * get_parent_region() const override;
	virtual void set_parent_region( i_region* const p_parent_region ) override;
	virtual t_raw_composite_states get_ancestors( i_composite_state* const p_final_ancestor ) const override;
	virtual t_raw_regions get_ancestors_as_regions() const override;


private:
	i_region* m_parent;
};


}

#endif
