//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_PSEUDOSTATE_595E5B94_1CE0_41B8_AD35_F0DB43C647B2
#define I_PSEUDOSTATE_595E5B94_1CE0_41B8_AD35_F0DB43C647B2


#include "i_vertex.h"
#include "i_pseudostate_fwd.h"


namespace sxy
{


class i_pseudostate_visitor;


class i_pseudostate: public virtual i_vertex
{
public:
	i_pseudostate
	(
	) = default;


	virtual 
	~i_pseudostate
	(
	) override = default;


	i_pseudostate
	(
		const i_pseudostate&
	) = delete;


	i_pseudostate&
	operator=
	(
		const i_pseudostate&
	) = delete;
		

	virtual void
	accept_pseudostate_visitor
	(
		i_pseudostate_visitor& p_visitor
	) const = 0;


	virtual bool
	check
	(
		t_state_machine_defects& p_defects
	) const override = 0;


};


}


#endif
