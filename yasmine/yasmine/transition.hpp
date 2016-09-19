//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_9D568568_F100_40E3_B02C_1141C218D7D8
#define TRANSITION_9D568568_F100_40E3_B02C_1141C218D7D8


#include "state_machine_element.hpp"

#include "transition_kind.hpp"
#include "event_id.hpp"
#include "transition_fwd.hpp"


namespace sxy
{


class vertex;
class constraint;
class behavior;
class event;


class transition:
	public virtual state_machine_element
{
public:
	transition() = default;
	virtual ~transition() noexcept override = default;
	transition( const transition& ) = delete;
	transition& operator=( const transition& ) = delete;
	virtual const vertex& get_source() const = 0;
	virtual const vertex& get_target() const = 0;
	virtual vertex& get_target() = 0;
	virtual const constraint * get_guard() const = 0;
	virtual const behavior * get_behavior() const = 0;
	virtual sxy::transition_kind get_kind() const = 0;
	virtual void on_transition_behavior( const event& _event ) const = 0;
	virtual bool check_guard( const event& _event ) const = 0;
	virtual bool check( state_machine_defects& _defects ) const override = 0;
	virtual bool can_accept_event( const event_id _event ) const = 0;
};


}


#endif
