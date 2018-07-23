//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_PSEUDOSTATE_73003664_F128_436A_8412_B1453D067026
#define STATE_PSEUDOSTATE_73003664_F128_436A_8412_B1453D067026


#include "pseudostate.hpp"
#include "composite_state.hpp"


namespace sxy
{


class state_pseudostate:
	public virtual pseudostate
{
public:
	state_pseudostate()
	{
		// Nothing to do...
	}


	virtual ~state_pseudostate() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(state_pseudostate)
	virtual composite_state& get_parent_state() const = 0;
	virtual void set_parent_state( composite_state* const _parent_state ) = 0;
};


}

#endif
