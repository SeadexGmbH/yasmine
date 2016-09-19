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
#include "behavior.hpp"


namespace sxy
{


class complex_state_impl:
	public virtual complex_state, public state_impl
{
public:
	explicit complex_state_impl(	const std::string& _name, behavior_uptr _entry_behavior, 
		behavior_uptr _exit_behavior, const event_ids& _deferred_events = {} );
	virtual ~complex_state_impl() noexcept override = default;
	complex_state_impl( const complex_state_impl& ) = delete;
	complex_state_impl& operator=( const complex_state_impl& ) = delete;
	virtual behavior * get_entry_behavior() const override;
	virtual behavior * get_exit_behavior() const override;
	virtual bool is_event_deferred( const event_id& _event_id ) const override;


protected:
	bool check_if_one_of_the_deferred_events_triggers_a_transition() const;


private:
	behavior_uptr entry_;
	behavior_uptr exit_;
	event_ids deferred_events_;
};


}


#endif
