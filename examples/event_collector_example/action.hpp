//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ACTION_DC893E1A_85B8_4181_AF46_91C00262AB2A
#define ACTION_DC893E1A_85B8_4181_AF46_91C00262AB2A


#include "essentials/non_copyable.hpp"


namespace sxy
{


#ifdef SX_CPP03_BOOST
	class event;
#endif


class event_collector;


}


namespace examples
{


class E4;


class action SX_FINAL
{
public:
	action();
	~action() SX_NOEXCEPT;
	SX_NO_COPY( action )
	void fire_event_E3( sxy::event_collector& _event_collector );
	void fire_event_E4( sxy::event_collector& _event_collector );
	void print_message_from_event( const E4& _event );
};


}


#endif
