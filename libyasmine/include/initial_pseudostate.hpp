//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef INITIAL_PSEUDOSTATE_D6A63505_2F02_4013_8A3E_A471096DE40E
#define INITIAL_PSEUDOSTATE_D6A63505_2F02_4013_8A3E_A471096DE40E


#include "region_pseudostate.hpp"
#include "initial_pseudostate_fwd.hpp"


namespace sxy
{


class transition;


class initial_pseudostate:
	public virtual region_pseudostate
{
public:
	initial_pseudostate()
	{
		// Nothing to do...
	}


	virtual ~initial_pseudostate() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(initial_pseudostate)
	virtual transition * get_transition() const = 0;
};


}


#endif
