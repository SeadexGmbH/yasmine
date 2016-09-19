//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_COMPLEX_STATE_91053A02_65AF_40C3_B9F9_C283A743A85F
#define I_COMPLEX_STATE_91053A02_65AF_40C3_B9F9_C283A743A85F


#include "i_state.h"


namespace sxy
{


class i_complex_state_visitor;


class i_complex_state:
	public virtual i_state
{
public:
	i_complex_state() = default;
	virtual ~i_complex_state() override = default;
	i_complex_state( const i_complex_state& ) = delete;
	i_complex_state& operator=( const i_complex_state& ) = delete;
	virtual void accept_complex_state_visitor( i_complex_state_visitor& p_visitor ) const = 0;
};


}


#endif
