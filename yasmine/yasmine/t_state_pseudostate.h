//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_STATE_PSEUDOSTATE_53615536_1590_46FD_B505_C62A7BFDC648
#define T_STATE_PSEUDOSTATE_53615536_1590_46FD_B505_C62A7BFDC648


#include "i_state_pseudostate.h"
#include "t_pseudostate.h"


namespace sxy
{


class t_state_pseudostate : public virtual i_state_pseudostate, public t_pseudostate
{
public:
	explicit t_state_pseudostate				 		
	(
		const std::string& p_name
	);


	virtual 
	~t_state_pseudostate
	(
	) override;


	t_state_pseudostate
	(
		const t_state_pseudostate&
	) = delete;


	t_state_pseudostate&
	operator=
	(
		const t_state_pseudostate&
	) = delete;							


	virtual const i_state_machine_element*
	get_parent
	(
	) const override;


	virtual i_composite_state&
	get_parent_state
	(
	) const override;


	virtual void
	set_parent_state
	(
		i_composite_state* const p_parent_state
	) override;


	virtual t_raw_composite_states
	get_ancestors
	(
		i_composite_state* const p_final_ancestor
	) const override;


	virtual t_raw_regions
	get_ancestors_as_regions
	(
	) const	override;
	
	
private:
	i_composite_state* m_parent;

};


}


#endif
