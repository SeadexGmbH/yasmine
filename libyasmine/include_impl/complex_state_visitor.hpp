//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPLEX_STATE_VISITOR_A1E31C49_08E0_400B_A6A9_20A333A8FD42
#define COMPLEX_STATE_VISITOR_A1E31C49_08E0_400B_A6A9_20A333A8FD42


#include "essentials/non_copyable.hpp"


namespace sxy
{


class composite_state;
class simple_state;


class complex_state_visitor
{
public:
	complex_state_visitor()
	{
		// Nothing to do...
	}


	virtual ~complex_state_visitor() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY(complex_state_visitor)
	virtual void visit( const composite_state& _composite_state ) = 0;
	virtual void visit( const simple_state& _simple_state ) = 0;	
};


}


#endif
