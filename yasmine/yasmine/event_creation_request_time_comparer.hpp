//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_CREATION_REQUEST_TIME_COMPARER_348858A8_8897_4A44_B2C8_A253190C9C1A
#define EVENT_CREATION_REQUEST_TIME_COMPARER_348858A8_8897_4A44_B2C8_A253190C9C1A


#include <memory>

#include "event_creation_request.hpp"


namespace sxy
{


struct event_creation_request_time_comparer
{
public:
	bool operator()( const std::unique_ptr< event_creation_request >& _lhs, 
		const std::unique_ptr< event_creation_request >& _rhs ) const;
};


}


#endif
