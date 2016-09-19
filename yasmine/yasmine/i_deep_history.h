//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_DEEP_HISTORY_4B2625A9_6406_4084_B3D3_7D67EDE09048
#define I_DEEP_HISTORY_4B2625A9_6406_4084_B3D3_7D67EDE09048


#include "i_history.h"


namespace sxy
{


class i_deep_history: public virtual i_history
{
public:
	i_deep_history
	(
	) = default;

		
	virtual 
	~i_deep_history
	(
	) override = default;


	i_deep_history
	(
		const i_deep_history&
	) = delete;


	i_deep_history&
	operator=
	(
		const i_deep_history&
	) = delete;


	virtual bool
	check
	(
		t_state_machine_defects& p_defects
	) const override = 0;

};


}


#endif
