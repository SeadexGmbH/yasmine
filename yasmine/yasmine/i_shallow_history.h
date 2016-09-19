//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_SHALLOW_HISTORY_2F18336E_AEBD_4040_B40D_E96E0738B83E
#define I_SHALLOW_HISTORY_2F18336E_AEBD_4040_B40D_E96E0738B83E


#include "i_history.h"


namespace sxy
{


class i_shallow_history: public virtual i_history
{
public:
	i_shallow_history
	(
	) = default;


	virtual 
	~i_shallow_history
	(
	)	override = default;


	i_shallow_history
	(
		const i_shallow_history&
	) = delete;


	i_shallow_history&
	operator=
	(
		const i_shallow_history&
	) = delete;


};


}


#endif
