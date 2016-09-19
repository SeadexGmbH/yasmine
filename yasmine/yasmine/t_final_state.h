//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_FINAL_STATE_9E44601B_5ED1_402E_BD68_5DCCFF5E27E2
#define T_FINAL_STATE_9E44601B_5ED1_402E_BD68_5DCCFF5E27E2


#include "i_final_state.h"
#include "t_state.h"


namespace sxy
{


class t_final_state: public virtual i_final_state, public t_state
{
public:
	explicit t_final_state
	(
		const std::string& p_name
	);


	virtual
	~t_final_state
	(
	) override;


	t_final_state
	(
		const t_final_state&
	) = delete;


	t_final_state&
	operator=
	(
		const t_final_state&
	) = delete;


	virtual i_behavior*
	get_entry_behavior
	(
	) const override;


	virtual i_behavior*
	get_exit_behavior
	(
	) const override;
 

	virtual const t_regions&
	get_regions
	(
	) const override;


	virtual t_regions&
	get_regions
	(
	) override;
	

	virtual bool
	check
	(
		t_state_machine_defects& p_defects
	) const override;


	virtual void
	accept_vertex_visitor
	(
		i_const_vertex_visitor& p_visitor
	) const override;


	virtual void
	accept_vertex_visitor
	(
		i_vertex_visitor& p_visitor
	) override;


	virtual void
	accept_state_visitor
	(
		i_state_visitor& p_visitor
	) const override;


	virtual bool
	is_event_deferred
	(
		const t_event_id& p_event_id
	) const override;


};


}


#endif
