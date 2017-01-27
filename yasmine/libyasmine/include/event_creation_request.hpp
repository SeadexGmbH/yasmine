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


#include "chrono.hpp"
#include "event_id.hpp"
#include "non_copyable.hpp"
#include "event_fwd.hpp"
#include "event_handle.hpp"


namespace sxy
{
	

class event_creation_request Y_FINAL
{	
public:	


	event_creation_request(	const sxy::time_point< sxy::system_clock >& _time, const event_sptr _event,	
		const handle_type _handle );
	~event_creation_request() Y_NOEXCEPT;
#ifndef Y_CPP03_BOOST
	Y_NO_COPY(event_creation_request)
	event_creation_request( event_creation_request&& );
	event_creation_request& operator=( event_creation_request&& );
#endif
	sxy::time_point< sxy::system_clock > get_time() const;
	handle_type get_handle() const;
	event_sptr get_event() const;


private:
	sxy::time_point< sxy::system_clock > time_;
	event_sptr event_;
	handle_type handle_;
};


}


#endif
