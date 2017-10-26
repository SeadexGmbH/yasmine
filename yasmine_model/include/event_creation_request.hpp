//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_CREATION_REQUEST_05BAD27E_EBBD_405D_B23D_00670DF91241
#define EVENT_CREATION_REQUEST_05BAD27E_EBBD_405D_B23D_00670DF91241


#include "essentials/compatibility/chrono.hpp"
#include "essentials/non_copyable.hpp"

#include "event_id.hpp"
#include "event_fwd.hpp"
#include "event_handle.hpp"


namespace sxy
{
	

class event_creation_request SX_FINAL
{	
public:	


	event_creation_request(	const sxe::time_point< sxe::system_clock >& _time, const event_sptr _event,	
		const handle_type _handle );
	~event_creation_request() SX_NOEXCEPT;
#ifndef SX_CPP03_BOOST
	SX_NO_COPY(event_creation_request)
	event_creation_request( event_creation_request&& );
	event_creation_request& operator=( event_creation_request&& );
#endif
	sxe::time_point< sxe::system_clock > get_time() const;
	handle_type get_handle() const;
	event_sptr get_event() const;


private:
	sxe::time_point< sxe::system_clock > time_;
	event_sptr event_;
	handle_type handle_;
};


}


#endif
