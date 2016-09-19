//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_TRANSITION_9D568568_F100_40E3_B02C_1141C218D7D8
#define I_TRANSITION_9D568568_F100_40E3_B02C_1141C218D7D8


#include "i_state_machine_element.h"

#include "t_transition_kind.h"
#include "t_event_id.h"


namespace sxy
{


class i_vertex;
class i_constraint;
class i_behavior;
class i_event;


class i_transition:
	public virtual i_state_machine_element
{
public:
	i_transition() = default;
	virtual ~i_transition() override = default;
	i_transition( const i_transition& ) = delete;
	i_transition& operator=( const i_transition& ) = delete;
	virtual const i_vertex& get_source() const = 0;
	virtual const i_vertex& get_target() const = 0;
	virtual i_vertex& get_target() = 0;
	virtual const i_constraint * get_guard() const = 0;
	virtual const i_behavior * get_behavior() const = 0;
	virtual sxy::t_transition_kind get_kind() const = 0;
	virtual void on_transition_behavior( const i_event& p_event ) const = 0;
	virtual bool check_guard( const i_event& p_event ) const = 0;
	virtual bool check( t_state_machine_defects& p_defects ) const override = 0;
	virtual bool can_accept_event( const t_event_id p_event ) const = 0;
};


}


#endif
