//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_STATE_PSEUDOSTATE_73003664_F128_436A_8412_B1453D067026
#define I_STATE_PSEUDOSTATE_73003664_F128_436A_8412_B1453D067026


#include "i_pseudostate.h"
#include "i_composite_state.h"


namespace sxy
{


class i_state_pseudostate : public virtual i_pseudostate
{
public:
	i_state_pseudostate
	(
	) = default;



	virtual 
	~i_state_pseudostate
	(
	) override = default;


	i_state_pseudostate
	(
		const i_state_pseudostate&
	) = delete;


	i_state_pseudostate&
	operator=
	(
		const i_state_pseudostate&
	) = delete;

											 
	virtual i_composite_state&
	get_parent_state
	(
	) const = 0;


	virtual void
	set_parent_state
	(
		i_composite_state* const p_parent_state
	) = 0;
	

private:
};


}

#endif
