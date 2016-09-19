//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef REGION_PSEUDOSTATE_IMPL_4F059791_948F_4CB6_9EDA_5CD4338F2255
#define REGION_PSEUDOSTATE_IMPL_4F059791_948F_4CB6_9EDA_5CD4338F2255


#include "region_pseudostate.h"
#include "pseudostate_impl.h"


namespace sxy
{


class region_pseudostate_impl:
	public virtual region_pseudostate, public pseudostate_impl
{
public:
	explicit region_pseudostate_impl( const std::string& _name );
	virtual ~region_pseudostate_impl() override;
	virtual const state_machine_element * get_parent() const override;
	virtual region * get_parent_region() const override;
	virtual void set_parent_region( region* const _parent_region ) override;
	virtual raw_composite_states get_ancestors( composite_state* const _final_ancestor ) const override;
	virtual raw_regions get_ancestors_as_regions() const override;


private:
	region* parent_;
};


}

#endif