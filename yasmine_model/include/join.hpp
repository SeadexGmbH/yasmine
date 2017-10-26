//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef JOIN_712B59B9_F9E6_4E4B_9427_477A4782E70E
#define JOIN_712B59B9_F9E6_4E4B_9427_477A4782E70E


#include "region_pseudostate.hpp"
#include "join_fwd.hpp"


namespace sxy
{


class join:
	public virtual region_pseudostate
{
public:
	join()
	{
		// Nothing to do...
	}


	virtual ~join() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(join)
	virtual bool check_if_all_source_states_of_incoming_transitions_are_active() const = 0;
};


}


#endif
