//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FINAL_STATE_029A393C_1CDD_45AC_8FBD_860D1EC631D4
#define FINAL_STATE_029A393C_1CDD_45AC_8FBD_860D1EC631D4


#include "state.hpp"


namespace sxy
{


class final_state:
	public virtual state
{
public:
	final_state()
	{
		// Nothing to do...
	}


	virtual ~final_state() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(final_state)
	
};


}


#endif
