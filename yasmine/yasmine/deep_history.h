//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef DEEP_HISTORY_4B2625A9_6406_4084_B3D3_7D67EDE09048
#define DEEP_HISTORY_4B2625A9_6406_4084_B3D3_7D67EDE09048


#include "history.h"


namespace sxy
{


class deep_history:
	public virtual history
{
public:
	deep_history() = default;
	virtual ~deep_history() override = default;
	deep_history( const deep_history& ) = delete;
	deep_history& operator=( const deep_history& ) = delete;
	virtual bool check( state_machine_defects& _defects ) const override = 0;
};


}


#endif