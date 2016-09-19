//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_ENTRY_POINT_A89D8062_12B7_44EC_8ACF_C3F54611609F
#define I_ENTRY_POINT_A89D8062_12B7_44EC_8ACF_C3F54611609F


#include "i_pseudostate.h"
#include "i_state_pseudostate.h"
 

namespace sxy
{


class i_entry_point: public virtual i_state_pseudostate
{
public:
	i_entry_point
	(
	) = default;

		
	virtual 
	~i_entry_point
	(
	) override = default;


	i_entry_point
	(
		const i_entry_point&
	) = delete;


	i_entry_point& operator=
	(
		const i_entry_point&
	) = delete;


};


}


#endif
