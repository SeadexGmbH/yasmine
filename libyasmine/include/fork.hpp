//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FORK_AE64610F_E053_4011_9005_1CB9698FDE30
#define FORK_AE64610F_E053_4011_9005_1CB9698FDE30


#include "region_pseudostate.hpp"
#include "fork_fwd.hpp"


namespace sxy
{


class fork:
	public virtual region_pseudostate
{
public:
	fork()
	{
		// Nothing to do...
	}


	virtual ~fork() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(fork)
};


}


#endif
