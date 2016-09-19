//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_PSEUDOSTATE_73003664_F128_436A_8412_B1453D067026
#define STATE_PSEUDOSTATE_73003664_F128_436A_8412_B1453D067026


#include "pseudostate.h"
#include "composite_state.h"


namespace sxy
{


class state_pseudostate:
	public virtual pseudostate
{
public:
	state_pseudostate() = default;
	virtual ~state_pseudostate() override = default;
	state_pseudostate( const state_pseudostate& ) = delete;
	state_pseudostate& operator=( const state_pseudostate& ) = delete;
	virtual composite_state& get_parent_state() const = 0;
	virtual void set_parent_state( composite_state* const _parent_state ) = 0;
};


}

#endif
