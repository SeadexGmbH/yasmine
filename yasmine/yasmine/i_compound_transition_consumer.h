//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_COMPOUND_TRANSITION_CONSUMER_01F0BAAD_6712_44B9_AA77_76A33352E801
#define I_COMPOUND_TRANSITION_CONSUMER_01F0BAAD_6712_44B9_AA77_76A33352E801


#include "i_transition_step_fwd.h"
#include "t_compound_transition_fwd.h"
#include "t_transition_kind.h"


namespace sxy
{


class i_vertex;
class i_region;
class i_composite_state;


class i_compound_transition_consumer
{
public:
	i_compound_transition_consumer() = default;
	virtual ~i_compound_transition_consumer() = default;
	i_compound_transition_consumer( const i_compound_transition_consumer& ) = delete;
	i_compound_transition_consumer& operator=( const i_compound_transition_consumer& ) = delete;
	virtual t_transition_steps& get_transition_steps() = 0;
	virtual const i_vertex& get_last_target() const = 0;
	virtual const t_compound_transitions& get_sub_compound_transitions() const = 0;
	virtual i_region * get_LCA_region() = 0;
	virtual i_composite_state * get_LCA_composite_state() = 0;
	virtual t_transition_kind get_transition_kind() = 0;
};


}


#endif
