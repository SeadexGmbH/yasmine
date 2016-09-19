//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_BEHAVIOR_86504172_8E66_4DF4_945F_A76FC04D3BEF
#define I_BEHAVIOR_86504172_8E66_4DF4_945F_A76FC04D3BEF


#include "i_behavior_fwd.h"


namespace sxy
{


class i_event;


class i_behavior
{
public:
	i_behavior() = default;
	virtual ~i_behavior() = default;
	i_behavior( const i_behavior& ) = delete;
	i_behavior& operator=( const i_behavior& ) = delete;
	virtual void operator()( const i_event& ) const = 0;
};


}


#endif
