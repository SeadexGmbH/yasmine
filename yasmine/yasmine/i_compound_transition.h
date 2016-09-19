//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_COMPOUND_TRANSITION_E7300B8C_33B4_4D4B_9093_A864A5ADA27C
#define I_COMPOUND_TRANSITION_E7300B8C_33B4_4D4B_9093_A864A5ADA27C


#include "i_compound_transition_consumer.h"
#include "t_compound_transition_fwd.h"
#include "i_transition_step_fwd.h"


namespace sxy
{


class i_vertex;
class i_region;
class i_transition;
class i_composite_state;
class i_event;


class i_compound_transition:
	public virtual i_compound_transition_consumer
{
public:
	i_compound_transition() = default;
	virtual ~i_compound_transition() = default;
	i_compound_transition( const i_compound_transition& ) = delete;
	i_compound_transition& operator=( const i_compound_transition& ) = delete;
	virtual t_transition_steps& get_transition_steps() = 0;
	virtual const i_vertex& get_last_target() const = 0;
	virtual const t_compound_transitions& get_sub_compound_transitions() const = 0;
	virtual void add_sub_compound_transition( i_compound_transition_uptr p_sub_compound_transition ) = 0;
	virtual i_region * get_LCA_region() = 0;
	virtual i_composite_state * get_LCA_composite_state() = 0;
	virtual bool check_if_starts_with( const i_transition& p_incoming_transition ) = 0;
	virtual bool create_and_check_transition_path( i_transition& p_start_transition, const i_event& p_event ) = 0;
};


}


#endif
