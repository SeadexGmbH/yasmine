//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_CREATION_REQUEST_TIME_COMPARER_348858A8_8897_4A44_B2C8_A253190C9C1A
#define EVENT_CREATION_REQUEST_TIME_COMPARER_348858A8_8897_4A44_B2C8_A253190C9C1A


namespace sxy
{


class event_creation_request;


struct event_creation_request_time_comparer
{
public:
	bool operator()( const event_creation_request& _lhs, const event_creation_request& _rhs ) const;
};


}


#endif
