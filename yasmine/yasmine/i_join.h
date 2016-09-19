//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_JOIN_712B59B9_F9E6_4E4B_9427_477A4782E70E
#define I_JOIN_712B59B9_F9E6_4E4B_9427_477A4782E70E


#include "i_region_pseudostate.h"


namespace sxy
{


class i_join:
	public virtual i_region_pseudostate
{
public:
	i_join() = default;
	virtual ~i_join() override = default;
	i_join( const i_join& ) = delete;
	i_join& operator=( const i_join& ) = delete;
	virtual bool check_if_all_source_states_of_incoming_transitions_are_active() const = 0;
};


}


#endif
