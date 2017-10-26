//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CONSTRAINT_DFC0FBD5_ACF7_4863_BB5F_129E8620FAB3
#define CONSTRAINT_DFC0FBD5_ACF7_4863_BB5F_129E8620FAB3


#include "essentials/non_copyable.hpp"

#include "constraint_fwd.hpp"


namespace sxy
{


class event;


class constraint
{
public:
	constraint()
	{
		// Nothing to do...
	}


	virtual ~constraint() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY(constraint)	
	virtual bool operator()( const event& _event, event_collector& _event_collector ) const = 0;
};


}


#endif
