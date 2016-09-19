//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_FINAL_STATE_029A393C_1CDD_45AC_8FBD_860D1EC631D4
#define I_FINAL_STATE_029A393C_1CDD_45AC_8FBD_860D1EC631D4


#include "i_state.h"


namespace sxy
{


class i_final_state: public virtual i_state
{
public:
	i_final_state
	(
	) = default;


	virtual 
	~i_final_state
	(
	) override = default;


	i_final_state
	(
		const i_final_state&
	) = delete;


	i_final_state&
	operator=
	(
		const i_final_state&
	) = delete;


};


}


#endif
