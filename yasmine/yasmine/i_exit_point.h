//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_EXIT_POINT_5F80CE76_2E5B_488A_B9C4_BF7529E2A712
#define I_EXIT_POINT_5F80CE76_2E5B_488A_B9C4_BF7529E2A712


#include "i_pseudostate.h"
#include "i_state_pseudostate.h"


namespace sxy
{


class i_exit_point:
	public virtual i_state_pseudostate
{
public:
	i_exit_point() = default;
	virtual ~i_exit_point() override = default;
	i_exit_point( const i_exit_point& ) = delete;
	i_exit_point& operator=( const i_exit_point& ) = delete;
};


}


#endif
