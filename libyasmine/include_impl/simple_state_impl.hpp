//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SIMPLE_STATE_IMPL_F53AD7D0_4393_4F4A_9FB4_4D865E93C724
#define SIMPLE_STATE_IMPL_F53AD7D0_4393_4F4A_9FB4_4D865E93C724


#include "simple_state_base.hpp"


namespace sxy
{


class simple_state_impl SX_FINAL:
	public simple_state_base
{
public:
	explicit simple_state_impl( const std::string& _name, behavior_uptr do_action = behavior_uptr(),
		behavior_uptr _entry_action = behavior_uptr(), behavior_uptr _exit_action = behavior_uptr(),
		const event_ids& _deferred_events = event_ids(), event_sptr _error_event = event_sptr() );
	virtual ~simple_state_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(simple_state_impl)
	void execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler,
		event_collector& _event_collector ) const SX_OVERRIDE;

private:
	const behavior * get_do() const;

	behavior_uptr do_;	
};


}


#endif
