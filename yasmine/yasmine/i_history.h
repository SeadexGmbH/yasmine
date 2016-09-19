//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_HISTORY_8019EFCB_44B8_4B81_A578_46C97A9B4E81
#define I_HISTORY_8019EFCB_44B8_4B81_A578_46C97A9B4E81


#include "i_pseudostate.h"
#include "i_state_pseudostate.h"


namespace sxy
{


class i_history : public virtual i_state_pseudostate
{
public:
	i_history
	(
	) = default;


	virtual 
	~i_history
	(
	)	override = default;


	i_history
	(
		const i_history&
	) = delete;


	i_history&
	operator=
	(
		const i_history&
	) = delete;


	virtual t_raw_transitions
	get_default_transitions
	(
	) const = 0;


	virtual void
	add_default_transition
	(			
		i_transition& p_default_transition
	) = 0;


	virtual bool
	check_if_state_was_active_before
	(
	) const = 0;


};


}


#endif
