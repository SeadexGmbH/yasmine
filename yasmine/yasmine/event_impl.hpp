//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_IMPL_447B2A6E_B2CC_4851_A3EB_68ACC838AEA2
#define EVENT_IMPL_447B2A6E_B2CC_4851_A3EB_68ACC838AEA2


#include <string>
#include <map>

#include "compatibility.hpp"
#include "event.hpp"


namespace sxy
{


class event_impl:
	public event
{
public:
	explicit event_impl( const event_id _event_id, const event_priority _event_priority = DEFAULT_EVENT_PRIORITY );
	virtual ~event_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(event_impl)
	virtual event_id get_id() const Y_OVERRIDE;
	virtual std::string get_name() const Y_OVERRIDE;
	virtual event_priority get_priority() const Y_OVERRIDE;
	virtual bool operator>(const event& _rhs) const Y_OVERRIDE;
	static event_sptr create( const event_id _event_id, const event_priority _event_priority = DEFAULT_EVENT_PRIORITY );


private:
	event_id event_id_;
	event_priority event_priority_;
};


}


#endif
