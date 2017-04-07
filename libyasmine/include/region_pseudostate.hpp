//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
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
	region_pseudostate()
	{
		// Nothing to do...
	}


	virtual ~region_pseudostate() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(region_pseudostate)
	virtual region* get_parent_region() const = 0;
	virtual void set_parent_region( region* const _parent_region ) = 0;
};


}

#endif
