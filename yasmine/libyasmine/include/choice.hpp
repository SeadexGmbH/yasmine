//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CHOICE_31837C1D_B3FD_41D7_94FB_CD7B16FEBD73
#define CHOICE_31837C1D_B3FD_41D7_94FB_CD7B16FEBD73


#include "region_pseudostate.hpp"
#include "choice_fwd.hpp"


namespace sxy
{


class choice:
	public virtual region_pseudostate
{
public:
	choice()
	{
		// Nothing to do...
	}


	virtual ~choice() Y_NOEXCEPT Y_OVERRIDE
	{
		// Nothing to do...
	}


	Y_NO_COPY(choice)
};


}


#endif
