//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOUND_TRANSITION_IMPL_A5F32559_6ACF_4113_92D6_FD2473853A3A
#define COMPOUND_TRANSITION_IMPL_A5F32559_6ACF_4113_92D6_FD2473853A3A


#include "compound_transition.h"


namespace sxy
{


class compound_transition_impl final:
	public virtual compound_transition
{
public:
	compound_transition_impl();
	~compound_transition_impl();
	compound_transition_impl( const compound_transition_impl& ) = delete;
	compound_transition_impl& operator=( const compound_transition_impl& ) = delete;
	virtual transition_steps& get_transition_steps() override;
	virtual const vertex& get_last_target() const override;
	virtual const compound_transitions& get_sub_compound_transitions() const override;
	virtual void add_sub_compound_transition( compound_transition_uptr _sub_compound_transition ) override;
	virtual region * get_LCA_region() override;
	virtual composite_state * get_LCA_composite_state() override;
	virtual transition_kind get_transition_kind() override;
	virtual bool check_if_starts_with( const transition& _incoming_transition ) override;
	virtual bool create_and_check_transition_path( transition& _start_transition, const event& _event ) override;


private:
	transition_steps transition_steps_;
	compound_transitions sub_compound_transitions_;
};


}


#endif
