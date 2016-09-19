//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_86504172_8E66_4DF4_945F_A76FC04D3BEF
#define BEHAVIOR_86504172_8E66_4DF4_945F_A76FC04D3BEF


#include "behavior_fwd.h"


namespace sxy
{


class event;


class behavior
{
public:
	behavior() = default;
	virtual ~behavior() = default;
	behavior( const behavior& ) = delete;
	behavior& operator=( const behavior& ) = delete;
	virtual void operator()( const event& ) const = 0;
};


}


#endif
