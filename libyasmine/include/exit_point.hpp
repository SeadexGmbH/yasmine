//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXIT_POINT_5F80CE76_2E5B_488A_B9C4_BF7529E2A712
#define EXIT_POINT_5F80CE76_2E5B_488A_B9C4_BF7529E2A712


#include "state_pseudostate.hpp"
#include "exit_point_fwd.hpp"


namespace sxy
{


class exit_point:
	public virtual state_pseudostate
{
public:
	exit_point()
	{
		// Nothing to do...
	}


	virtual ~exit_point() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(exit_point)
};


}


#endif
