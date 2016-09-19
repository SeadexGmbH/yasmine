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


#include "pseudostate.h"
#include "state_pseudostate.h"


namespace sxy
{


class history:
	public virtual state_pseudostate
{
public:
	history() = default;
	virtual ~history() override = default;
	history( const history& ) = delete;
	history& operator=( const history& ) = delete;
	virtual raw_transitions get_default_transitions() const = 0;
	virtual void add_default_transition( transition& _default_transition ) = 0;
	virtual bool check_if_state_was_active_before() const = 0;
};


}


#endif
