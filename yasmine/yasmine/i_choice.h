//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_CHOICE_31837C1D_B3FD_41D7_94FB_CD7B16FEBD73
#define I_CHOICE_31837C1D_B3FD_41D7_94FB_CD7B16FEBD73


#include "i_region_pseudostate.h"


namespace sxy
{						


class i_choice: public virtual i_region_pseudostate
{
public:
	i_choice
	(
	) = default;


	virtual 
	~i_choice
	(
	) override = default;


	i_choice
	(
		const i_choice&
	) = delete;


	i_choice&
	operator=
	(
		const i_choice&
	) = delete;


};


}


#endif
