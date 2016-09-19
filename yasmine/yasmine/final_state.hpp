//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
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
	final_state() = default;
	virtual ~final_state() noexcept override = default;
	final_state( const final_state& ) = delete;
	final_state& operator=( const final_state& ) = delete;
};


}


#endif
