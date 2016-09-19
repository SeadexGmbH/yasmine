//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_REGION_PSEUDOSTATE_B33005D7_D302_495D_9118_F45EA4443736
#define I_REGION_PSEUDOSTATE_B33005D7_D302_495D_9118_F45EA4443736


#include "i_pseudostate.h"


namespace sxy
{


class i_region_pseudostate:
	public virtual i_pseudostate
{
public:
	i_region_pseudostate() = default;
	virtual ~i_region_pseudostate() override = default;
	i_region_pseudostate( const i_region_pseudostate& ) = delete;
	i_region_pseudostate& operator=( const i_region_pseudostate& ) = delete;
	virtual i_region* get_parent_region() const = 0;
	virtual void set_parent_region( i_region* const p_parent_region ) = 0;
};


}

#endif
