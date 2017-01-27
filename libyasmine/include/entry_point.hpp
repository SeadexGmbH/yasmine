//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ENTRY_POINT_A89D8062_12B7_44EC_8ACF_C3F54611609F
#define ENTRY_POINT_A89D8062_12B7_44EC_8ACF_C3F54611609F


#include "state_pseudostate.hpp"
#include "entry_point_fwd.hpp"


namespace sxy
{


class entry_point:
	public virtual state_pseudostate
{
public:
	entry_point()
	{
		// Nothing to do...
	}


	virtual ~entry_point() Y_NOEXCEPT Y_OVERRIDE
	{
		// Nothing to do...
	}


	Y_NO_COPY(entry_point)
};


}


#endif
