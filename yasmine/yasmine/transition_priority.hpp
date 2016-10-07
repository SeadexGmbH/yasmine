//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_PRIORITY_FDB88A02_ECF6_4BB5_B95A_3F45813BF357
#define TRANSITION_PRIORITY_FDB88A02_ECF6_4BB5_B95A_3F45813BF357


#include <cstddef>

#include "compatibility.hpp"


namespace sxy
{


class compound_transition;


class transition_priority final
{
public:
	explicit transition_priority( compound_transition& _compound_transition );
	~transition_priority() noexcept = default;
	std::size_t get_priority() const;
	compound_transition& get_compound_transition() const;
	bool operator<( const transition_priority& _compare_member ) const;


private:
	// Objects of this class have to be copied, so we cannot have a reference member.
	compound_transition* compound_transition_;
	std::size_t priority_;
};


}


#endif
