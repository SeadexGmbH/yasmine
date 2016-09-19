//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_CREATION_REQUEST_05BAD27E_EBBD_405D_B23D_00670DF91241
#define EVENT_CREATION_REQUEST_05BAD27E_EBBD_405D_B23D_00670DF91241


#include <chrono>

#include "t_event_id.h"
#include "log.h"
#include "i_event_fwd.h"


namespace sxy
{


class t_event_creation_request final
{
public:

	
	t_event_creation_request
	(
		const std::chrono::time_point< std::chrono::system_clock >& p_time,
		const t_event_sptr p_event,
		const int p_handle
	);
																

	~t_event_creation_request
	(
	);


	t_event_creation_request
	(
		const t_event_creation_request&
	) = delete;


	t_event_creation_request&
	operator=
	(
		const t_event_creation_request&
	) = delete;


	std::chrono::time_point< std::chrono::system_clock >
	get_time
	(
	) const;


	int
	get_handle
	(
	) const;


	t_event_sptr
	get_event
	(
	) const;


private:
	std::chrono::time_point< std::chrono::system_clock > m_time;
	const t_event_sptr m_event;
	int m_handle;								


};


}


#endif
