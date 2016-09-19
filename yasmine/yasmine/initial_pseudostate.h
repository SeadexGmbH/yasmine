//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef INITIAL_PSEUDOSTATE_D6A63505_2F02_4013_8A3E_A471096DE40E
#define INITIAL_PSEUDOSTATE_D6A63505_2F02_4013_8A3E_A471096DE40E


#include "pseudostate.h"
#include "region_pseudostate.h"


namespace sxy
{


class transition;


class initial_pseudostate:
	public virtual region_pseudostate
{
public:
	initial_pseudostate() = default;
	virtual ~initial_pseudostate() override = default;
	initial_pseudostate( const initial_pseudostate& ) = delete;
	initial_pseudostate& operator=( const initial_pseudostate& ) = delete;
	virtual transition * get_transition() const = 0;
};


}


#endif
