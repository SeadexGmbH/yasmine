//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SIMPLE_STATE_FE75D8CB_F61A_4291_94EC_206E43F291AA
#define SIMPLE_STATE_FE75D8CB_F61A_4291_94EC_206E43F291AA


#include "complex_state.hpp"


namespace sxy
{


class simple_state:
	public virtual complex_state
{
public:
	simple_state()
	{
		// Nothing to do...
	}


	virtual ~simple_state() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(simple_state)
};


}


#endif
