//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_2A20341F_93C3_409E_8792_B05E0D83C7D1
#define BEHAVIOR_2A20341F_93C3_409E_8792_B05E0D83C7D1


#include "essentials/non_copyable.hpp"

#include "behavior_fwd.hpp"
#include "event_fwd.hpp"


namespace sxy
{


class behavior
{
public:
	behavior()
	{
		// Nothing to do...
	}


	virtual ~behavior() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY(behavior)
	virtual void operator()( const event&, event_collector& ) const = 0;
};


}


#endif
