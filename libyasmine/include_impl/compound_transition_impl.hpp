//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOUND_TRANSITION_IMPL_A5F32559_6ACF_4113_92D6_FD2473853A3A
#define COMPOUND_TRANSITION_IMPL_A5F32559_6ACF_4113_92D6_FD2473853A3A


#include "compound_transition.hpp"
#include "transition_step.hpp"


namespace sxy
{


class compound_transition_impl SX_FINAL:
	public compound_transition
{
public:
	compound_transition_impl();
	virtual ~compound_transition_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(compound_transition_impl)
	virtual transition_steps& get_transition_steps() SX_OVERRIDE;
	virtual const vertex& get_last_target() const SX_OVERRIDE;
	virtual const compound_transitions& get_sub_compound_transitions() const SX_OVERRIDE;
	virtual void add_sub_compound_transition( compound_transition_uptr _sub_compound_transition ) SX_OVERRIDE;
	virtual region * get_LCA_region() SX_OVERRIDE;
	virtual composite_state * get_LCA_composite_state() SX_OVERRIDE;
	virtual transition_kind get_transition_kind() SX_OVERRIDE;
	virtual bool check_if_starts_with( const transition& _incoming_transition ) SX_OVERRIDE;
	virtual bool create_and_check_transition_path( transition& _start_transition, const event& _event, 
		event_collector& _event_collector ) SX_OVERRIDE;


private:
	transition_steps transition_steps_;
	compound_transitions sub_compound_transitions_;
};


}


#endif
