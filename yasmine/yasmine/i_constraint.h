//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_CONSTRAINT_DFC0FBD5_ACF7_4863_BB5F_129E8620FAB3
#define I_CONSTRAINT_DFC0FBD5_ACF7_4863_BB5F_129E8620FAB3


#include "i_constraint_fwd.h"


namespace sxy
{


class i_event;


class i_constraint
{
public:
	i_constraint() = default;
	virtual ~i_constraint() = default;
	i_constraint( const i_constraint& ) = delete;
	i_constraint& operator=( const i_constraint& ) = delete;
	virtual bool operator()( const i_event& p_event ) const = 0;
};


}


#endif
