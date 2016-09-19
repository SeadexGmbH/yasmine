//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_PSEUDOSTATE_3198565A_DA5E_4E46_B91A_144462122F9B
#define T_PSEUDOSTATE_3198565A_DA5E_4E46_B91A_144462122F9B


#include "i_pseudostate.h"
#include "t_vertex.h"


namespace sxy
{


class t_pseudostate: public virtual i_pseudostate, public t_vertex
{
public:
	explicit t_pseudostate
	(			
		const std::string& p_name
	);


	virtual
	~t_pseudostate
	(
	) override;


	t_pseudostate
	(
		const t_pseudostate&
	) = delete;


	t_pseudostate&
	operator=
	(
		const t_pseudostate&
	) = delete;


	virtual bool
	check
	( 
		t_state_machine_defects& p_defects 
	) const  override;


};


}


#endif
