//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_TRANSITION_STEP_6023D41F_1644_441E_8A49_E2BE433910AF
#define I_TRANSITION_STEP_6023D41F_1644_441E_8A49_E2BE433910AF


#include "i_vertex_fwd.h"
#include "i_transition_fwd.h"


namespace sxy
{


class i_entry_point;
class i_exit_point;
class i_event;


class i_transition_step
{
public:
	i_transition_step() = default;
	virtual ~i_transition_step() = default;
	i_transition_step( const i_transition_step& ) = delete;
	i_transition_step& operator=( const i_transition_step& ) = delete;
	virtual const t_raw_transitions& get_transitions() const = 0;
	virtual const i_vertex& get_unique_source() const = 0;
	virtual const i_vertex& get_unique_target() const = 0;
	virtual void execute_transition_behaviors( const i_event& p_event ) const = 0;
	virtual const i_exit_point * get_exit_point() const = 0;
	virtual const i_entry_point * get_entry_point() const = 0;
	virtual const t_raw_const_vertices get_target_vertices() = 0;
};


}


#endif
