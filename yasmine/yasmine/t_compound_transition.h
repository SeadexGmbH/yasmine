//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_COMPOUND_TRANSITION_H_191B3264_322A_495C_8CF0_9475D4B51684
#define T_COMPOUND_TRANSITION_H_191B3264_322A_495C_8CF0_9475D4B51684


#include "i_compound_transition.h"


namespace sxy
{


class t_compound_transition final:
	public virtual i_compound_transition
{
public:
	t_compound_transition();
	~t_compound_transition();
	t_compound_transition( const t_compound_transition& ) = delete;
	t_compound_transition& operator=( const t_compound_transition& ) = delete;
	virtual t_transition_steps& get_transition_steps() override;
	virtual const i_vertex& get_last_target() const override;
	virtual const t_compound_transitions& get_sub_compound_transitions() const override;
	virtual void add_sub_compound_transition( i_compound_transition_uptr p_sub_compound_transition ) override;
	virtual i_region * get_LCA_region() override;
	virtual i_composite_state * get_LCA_composite_state() override;
	virtual t_transition_kind get_transition_kind() override;
	virtual bool check_if_starts_with( const i_transition& p_incoming_transition ) override;
	virtual bool create_and_check_transition_path( i_transition& p_start_transition, const i_event& p_event ) override;


private:
	t_transition_steps m_transition_steps;
	t_compound_transitions m_sub_compound_transitions;
};


}


#endif
