//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_FORK_AE64610F_E053_4011_9005_1CB9698FDE30
#define I_FORK_AE64610F_E053_4011_9005_1CB9698FDE30


#include "i_region_pseudostate.h"


namespace sxy
{


class i_fork:
	public virtual i_region_pseudostate
{
public:
	i_fork() = default;
	virtual ~i_fork() override = default;
	i_fork( const i_fork& ) = delete;
	i_fork& operator=( const i_fork& ) = delete;
};


}


#endif
