//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SIMPLE_STATE_IMPL_F53AD7D0_4393_4F4A_9FB4_4D865E93C724
#define SIMPLE_STATE_IMPL_F53AD7D0_4393_4F4A_9FB4_4D865E93C724


#include "simple_state_base.hpp"


namespace sxy
{


class simple_state_impl Y_FINAL:
	public simple_state_base
{
public:
	explicit simple_state_impl( const std::string& _name, behaviour_uptr do_action = behaviour_uptr(),
		behaviour_uptr _entry_action = behaviour_uptr(), behaviour_uptr _exit_action = behaviour_uptr(),
		const event_ids& _deferred_events = event_ids(), event_sptr _error_event = event_sptr() );
	virtual ~simple_state_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(simple_state_impl)
	void execute_do_behaviour( const event& _event, async_event_handler* const _async_event_handler ) const Y_OVERRIDE;

private:
	const behaviour * get_do() const;

	behaviour_uptr do_;	
};


}


#endif
