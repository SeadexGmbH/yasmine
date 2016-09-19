//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_STATE_A72D37CD_D9B1_430D_BBCA_13371745FC80
#define I_STATE_A72D37CD_D9B1_430D_BBCA_13371745FC80


#include "i_vertex.h"
#include "i_state_fwd.h"
#include "i_region_fwd.h"


namespace sxy
{


class i_state_visitor;
class i_behavior;
class i_event;


class i_state: public virtual i_vertex
{
public:
	i_state
	(
	)	= default;


	virtual 
	~i_state
	(
	) override = default;


	i_state
	(
		const i_state&
	) = delete;


	i_state&
	operator=
	(
		const i_state&
	) = delete;


	virtual void
	set_parent_region
	(
		i_region* const p_parent_region
	) = 0;
	

	virtual i_region*
	get_parent_region
	(
	) const = 0;


	virtual size_t
	get_parent_region_index
	(			
	) const = 0;


	virtual i_region*
	get_region
	(
		const std::string& p_region_name
	) const = 0;


	virtual i_vertex*
	get_pseudostate
	(
		const std::string& p_name_of_pseudostate
	) const = 0;


	virtual i_behavior*
	get_entry_behavior
	(
	) const = 0;


	virtual i_behavior*
	get_exit_behavior
	(
	) const = 0;
	

	virtual std::size_t
	get_nesting_level
	(
	) const = 0;


	virtual void
	set_active
	(
	) = 0;


	virtual void
	set_inactive
	(
	) = 0;


	virtual bool
	is_active
	(
	) const = 0;


	virtual bool
	is_complete
	(
	) const = 0;


	virtual bool
	is_event_deferred
	(
		const t_event_id& p_event_id
	) const = 0;
	

	virtual bool
	was_active
	(
	) const = 0;


	virtual void
	set_was_active
	(
	) = 0;				

	
	virtual const t_regions&
	get_regions
	(
	) const = 0;


	virtual t_regions&
	get_regions
	(
	) = 0;


	virtual void
	execute_do_behavior
	(
		const i_event& p_event
	) const = 0;


	virtual void
	execute_enter_behavior
	(
		const i_event& p_event
	) const = 0;


	virtual void
	execute_exit_behavior
	(
		const i_event& p_event
	) const = 0;
	

	virtual void
	accept_state_visitor
	(
		i_state_visitor& p_visitor
	) const = 0;
	

	virtual void
	enter_state
	(
		const i_event& p_event
	) = 0;


	virtual void
	exit_state
	(
		const i_event& p_event
	) = 0;


};


}


#endif
