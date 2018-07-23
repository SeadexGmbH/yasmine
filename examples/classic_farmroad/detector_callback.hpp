//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef DETECTOR_CALLBACK_0AF0AB58_4818_48B8_A10D_3894B6652355
#define DETECTOR_CALLBACK_0AF0AB58_4818_48B8_A10D_3894B6652355


#include "essentials/non_copyable.hpp"
#include "essentials/compatibility/compatibility.hpp"


namespace examples
{


class detector_callback
{
public:
	detector_callback()
	{
		// Nothing to do...
	}
	virtual ~detector_callback() SX_NOEXCEPT
	{
		// Nothing to do...
	}

	SX_NO_COPY( detector_callback )
	virtual void detector_on() = 0;
	virtual void detector_off() = 0;
};


}


#endif
