//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_IVENT_B4FC96AB_1446_49FA_96EE_A3341BBACCDF
#define I_IVENT_B4FC96AB_1446_49FA_96EE_A3341BBACCDF


#include "t_event_id.h"


namespace sxy
{


class i_event
{
public:

	i_event
	(
	) = default;


	virtual ~i_event
	(
	) = default;


	i_event
	(
		const i_event&
	) = delete;


	i_event&
	operator=
	(
		const i_event&
	) = delete;


	virtual t_event_id
	get_id
	(
	) const = 0;


};


}


#endif
