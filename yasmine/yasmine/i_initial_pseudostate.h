//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_INITIAL_PSEUDOSTATE_D6A63505_2F02_4013_8A3E_A471096DE40E
#define I_INITIAL_PSEUDOSTATE_D6A63505_2F02_4013_8A3E_A471096DE40E


#include "i_pseudostate.h"
#include "i_region_pseudostate.h"


namespace sxy
{


class i_transition;


class i_initial_pseudostate:
	public virtual i_region_pseudostate
{
public:
	i_initial_pseudostate() = default;
	virtual ~i_initial_pseudostate() override = default;
	i_initial_pseudostate( const i_initial_pseudostate& ) = delete;
	i_initial_pseudostate& operator=( const i_initial_pseudostate& ) = delete;
	virtual i_transition * get_transition() const = 0;
};


}


#endif
