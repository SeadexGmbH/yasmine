//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef IVENT_B4FC96AB_1446_49FA_96EE_A3341BBACCDF
#define IVENT_B4FC96AB_1446_49FA_96EE_A3341BBACCDF


#include "event_id.h"


namespace sxy
{


class event
{
public:
	event() = default;
	virtual ~event() = default;
	event( const event& ) = delete;
	event& operator=( const event& ) = delete;
	virtual event_id get_id() const = 0;
};


}


#endif
