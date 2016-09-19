//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef JOIN_712B59B9_F9E6_4E4B_9427_477A4782E70E
#define JOIN_712B59B9_F9E6_4E4B_9427_477A4782E70E


#include "region_pseudostate.hpp"
#include "join_fwd.hpp"


namespace sxy
{


class join:
	public virtual region_pseudostate
{
public:
	join() = default;
	virtual ~join() noexcept override = default;
	join( const join& ) = delete;
	join& operator=( const join& ) = delete;
	virtual bool check_if_all_source_states_of_incoming_transitions_are_active() const = 0;
};


}


#endif
