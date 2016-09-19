//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXIT_POINT_5F80CE76_2E5B_488A_B9C4_BF7529E2A712
#define EXIT_POINT_5F80CE76_2E5B_488A_B9C4_BF7529E2A712


#include "pseudostate.h"
#include "state_pseudostate.h"


namespace sxy
{


class exit_point:
	public virtual state_pseudostate
{
public:
	exit_point() = default;
	virtual ~exit_point() override = default;
	exit_point( const exit_point& ) = delete;
	exit_point& operator=( const exit_point& ) = delete;
};


}


#endif
