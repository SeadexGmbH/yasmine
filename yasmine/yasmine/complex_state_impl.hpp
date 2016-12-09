//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPLEX_STATE_IMPL_38C23A75_BCF7_419A_BC41_CD8FB9F8C011
#define COMPLEX_STATE_IMPL_38C23A75_BCF7_419A_BC41_CD8FB9F8C011


#include "complex_state.hpp"
#include "state_impl.hpp"
#include "behaviour.hpp"


namespace sxy
{


class complex_state_impl:
	public virtual complex_state, public state_impl
{
public:
	explicit complex_state_impl(	const std::string& _name, behaviour_uptr _entry_behaviour, 
		behaviour_uptr _exit_behaviour, const event_ids& _deferred_events = event_ids() );
	virtual ~complex_state_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(complex_state_impl)	
	virtual behaviour * get_entry_behaviour() const Y_OVERRIDE;
	virtual behaviour * get_exit_behaviour() const Y_OVERRIDE;
	virtual bool is_event_deferred( const event_id& _event_id ) const Y_OVERRIDE;


protected:
	bool check_if_one_of_the_deferred_events_triggers_a_transition() const;


private:
	behaviour_uptr entry_;
	behaviour_uptr exit_;
	event_ids deferred_events_;
};


}


#endif
