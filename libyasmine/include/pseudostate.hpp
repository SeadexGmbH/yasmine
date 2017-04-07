//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef PSEUDOSTATE_595E5B94_1CE0_41B8_AD35_F0DB43C647B2
#define PSEUDOSTATE_595E5B94_1CE0_41B8_AD35_F0DB43C647B2


#include "vertex.hpp"
#include "pseudostate_fwd.hpp"


namespace sxy
{


class pseudostate_visitor;


class pseudostate:
	public virtual vertex
{
public:
	pseudostate()
	{
		// Nothing to do...
	}


	virtual ~pseudostate() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(pseudostate)
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const = 0;
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE = 0;
};


}


#endif
