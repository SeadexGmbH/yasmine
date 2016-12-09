//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef HISTORY_8019EFCB_44B8_4B81_A578_46C97A9B4E81
#define HISTORY_8019EFCB_44B8_4B81_A578_46C97A9B4E81


#include "pseudostate.hpp"
#include "state_pseudostate.hpp"


namespace sxy
{


class history:
	public virtual state_pseudostate
{
public:
	history()
	{
		// Nothing to do...
	}


	virtual ~history() Y_NOEXCEPT Y_OVERRIDE
	{
		// Nothing to do...
	}


	Y_NO_COPY(history)
	virtual raw_transitions get_default_transitions() const = 0;
	virtual void add_default_transition( transition& _default_transition ) = 0;
	virtual bool check_if_state_was_active_before() const = 0;
};


}


#endif
