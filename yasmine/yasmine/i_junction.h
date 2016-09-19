//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_JUNCTION_C9792E4F_85DB_4377_AFE4_E1A1B9F101E0
#define I_JUNCTION_C9792E4F_85DB_4377_AFE4_E1A1B9F101E0


#include "i_region_pseudostate.h"


namespace sxy
{


class i_junction: public virtual i_region_pseudostate
{
public:
	i_junction
	(
	) = default;


	virtual 
	~i_junction
	(
	) override = default;


	i_junction
	(
		const i_junction&
	) = delete;


	i_junction&
	operator=
	(
		const i_junction&
	) = delete;


};


}


#endif
