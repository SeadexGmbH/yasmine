//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_FORK_E5E053EE_B1C9_4A84_9754_236E0E2E13E3
#define T_FORK_E5E053EE_B1C9_4A84_9754_236E0E2E13E3


#include "i_fork.h"
#include "t_region_pseudostate.h"


namespace sxy
{


class t_fork: public virtual i_fork, public t_region_pseudostate
{
public:
	explicit t_fork
	(
		const std::string& p_name
	);


	virtual
	~t_fork
	(
	) override;


	t_fork
	(
		const t_fork&
	) = delete;


	t_fork&
	operator=
	(
		const t_fork&
	) = delete;


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
	accept_pseudostate_visitor
	(
		i_pseudostate_visitor& p_visitor
	) const override;


	virtual void
	add_incoming_transition
	(
		i_transition& p_incoming_transition
	) override;


};


}


#endif
