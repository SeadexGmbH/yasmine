//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOUR_86504172_8E66_4DF4_945F_A76FC04D3BEF
#define BEHAVIOUR_86504172_8E66_4DF4_945F_A76FC04D3BEF


#include "non_copyable.hpp"
#include "behaviour_fwd.hpp"
#include "event_fwd.hpp"


namespace sxy
{


class behaviour
{
public:
	behaviour()
	{
		// Nothing to do...
	}


	virtual ~behaviour() Y_NOEXCEPT
	{
		// Nothing to do...
	}


	Y_NO_COPY(behaviour)
	virtual void operator()( const event& ) const = 0;
};


}


#endif
