//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef PSEUDOSTATE_595E5B94_1CE0_41B8_AD35_F0DB43C647B2
#define PSEUDOSTATE_595E5B94_1CE0_41B8_AD35_F0DB43C647B2


#include "vertex.h"
#include "pseudostate_fwd.h"


namespace sxy
{


class pseudostate_visitor;


class pseudostate:
	public virtual vertex
{
public:
	pseudostate() = default;
	virtual ~pseudostate() override = default;
	pseudostate( const pseudostate& ) = delete;
	pseudostate& operator=( const pseudostate& ) = delete;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const = 0;
	virtual bool check( state_machine_defects& _defects ) const override = 0;
};


}


#endif
