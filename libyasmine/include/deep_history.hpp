//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef DEEP_HISTORY_4B2625A9_6406_4084_B3D3_7D67EDE09048
#define DEEP_HISTORY_4B2625A9_6406_4084_B3D3_7D67EDE09048


#include "history.hpp"
#include "deep_history_fwd.hpp"


namespace sxy
{


class deep_history:
	public virtual history
{
public:
	deep_history()
	{
		// Nothing to do...
	}


	virtual ~deep_history() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(deep_history)
};


}


#endif
