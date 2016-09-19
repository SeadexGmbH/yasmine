//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_TERMINATE_PSEUDOSTATE_86477850_30F8_412F_B194_45E54964DF7B
#define I_TERMINATE_PSEUDOSTATE_86477850_30F8_412F_B194_45E54964DF7B


#include "i_region_pseudostate.h"


namespace sxy
{


class i_terminate_pseudostate:
	public virtual i_region_pseudostate
{
public:
	i_terminate_pseudostate() = default;
	virtual ~i_terminate_pseudostate() override = default;
	i_terminate_pseudostate( const i_terminate_pseudostate& ) = delete;
	i_terminate_pseudostate& operator=( const i_terminate_pseudostate& ) = delete;
};


}


#endif
