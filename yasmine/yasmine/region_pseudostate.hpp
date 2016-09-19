//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef REGION_PSEUDOSTATE_B33005D7_D302_495D_9118_F45EA4443736
#define REGION_PSEUDOSTATE_B33005D7_D302_495D_9118_F45EA4443736


#include "pseudostate.hpp"


namespace sxy
{


class region_pseudostate:
	public virtual pseudostate
{
public:
	region_pseudostate() = default;
	virtual ~region_pseudostate() noexcept override = default;
	region_pseudostate( const region_pseudostate& ) = delete;
	region_pseudostate& operator=( const region_pseudostate& ) = delete;
	virtual region* get_parent_region() const = 0;
	virtual void set_parent_region( region* const _parent_region ) = 0;
};


}

#endif
