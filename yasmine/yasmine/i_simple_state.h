//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_SIMPLE_STATE_FE75D8CB_F61A_4291_94EC_206E43F291AA
#define I_SIMPLE_STATE_FE75D8CB_F61A_4291_94EC_206E43F291AA


#include "i_complex_state.h"


namespace sxy
{


class i_simple_state:
	public virtual i_complex_state
{
public:
	i_simple_state() = default;
	virtual ~i_simple_state() override = default;
	i_simple_state( const i_simple_state& ) = delete;
	i_simple_state& operator=( const i_simple_state& ) = delete;
	virtual const i_behavior * get_do() const = 0;
};


}


#endif
