//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TERMINATE_PSEUDOSTATE_86477850_30F8_412F_B194_45E54964DF7B
#define TERMINATE_PSEUDOSTATE_86477850_30F8_412F_B194_45E54964DF7B


#include "region_pseudostate.hpp"
#include "terminate_pseudostate_fwd.hpp"


namespace sxy
{


class terminate_pseudostate:
	public virtual region_pseudostate
{
public:
	terminate_pseudostate()
	{
		// Nothing to do...
	}


	virtual ~terminate_pseudostate() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(terminate_pseudostate)
};


}


#endif
