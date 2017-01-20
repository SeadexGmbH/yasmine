//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SPECIALIZED_EVENT_CA823D7C_65A6_4094_8641_FA9496F11C1F
#define SPECIALIZED_EVENT_CA823D7C_65A6_4094_8641_FA9496F11C1F


#include "event_impl.hpp"


namespace sxy
{


template<typename _tag, sxy::event_id _event_id, sxy::event_priority _event_priority = DEFAULT_EVENT_PRIORITY>
class specialized_event: public event_impl
{
public:
	explicit specialized_event(const std::string _name = std::string())
		: event_impl( _event_id, _event_priority ),
		  name_( _name )
	{
		// Nothing to do.
	}


	virtual ~specialized_event() Y_NOEXCEPT Y_OVERRIDE
	{
		// Nothing to do.
	}


	Y_NO_COPY(specialized_event)


	virtual std::string get_name() const Y_OVERRIDE
	{
		const std::string name = name_.empty() ? event_impl::get_name() : name_;
		return(name);
	}


private:
	std::string name_;
};


}


#endif
