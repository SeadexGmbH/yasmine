//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CONSTRAINT_DFC0FBD5_ACF7_4863_BB5F_129E8620FAB3
#define CONSTRAINT_DFC0FBD5_ACF7_4863_BB5F_129E8620FAB3


#include "compatibility.hpp"
#include "constraint_fwd.hpp"


namespace sxy
{


class event;


class constraint
{
public:
	constraint() = default;
	virtual ~constraint() noexcept = default;
	constraint( const constraint& ) = delete;
	constraint& operator=( const constraint& ) = delete;
	virtual bool operator()( const event& _event ) const = 0;
};


}


#endif
