//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPLEX_STATE_VISITOR_A1E31C49_08E0_400B_A6A9_20A333A8FD42
#define COMPLEX_STATE_VISITOR_A1E31C49_08E0_400B_A6A9_20A333A8FD42


#include "compatibility.hpp"


namespace sxy
{


class composite_state;
class simple_state;


class complex_state_visitor
{
public:
	complex_state_visitor() = default;
	virtual ~complex_state_visitor() noexcept = default;
	complex_state_visitor( const complex_state_visitor& ) = delete;
	complex_state_visitor& operator=( const complex_state_visitor& ) = delete;
	virtual void visit( const composite_state& _composite_state ) = 0;
	virtual void visit( const simple_state& _simple_state ) = 0;	
};


}


#endif
