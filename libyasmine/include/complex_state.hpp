//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPLEX_STATE_91053A02_65AF_40C3_B9F9_C283A743A85F
#define COMPLEX_STATE_91053A02_65AF_40C3_B9F9_C283A743A85F


#include "state.hpp"


namespace sxy
{


class complex_state_visitor;


class complex_state:
	public virtual state
{
public:
	complex_state()
	{
		// Nothing to do...
	}


	virtual ~complex_state() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(complex_state)
	virtual void accept_complex_state_visitor( complex_state_visitor& _visitor ) const = 0;
	virtual void add_deferred_event( const event_id& _event_id ) = 0;
};


}


#endif
