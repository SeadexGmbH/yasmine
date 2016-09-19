//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_PSEUDOSTATE_IMPL_2EA11FC4_EEC5_430E_AB7B_27E54A1202A0
#define STATE_PSEUDOSTATE_IMPL_2EA11FC4_EEC5_430E_AB7B_27E54A1202A0


#include "state_pseudostate.h"
#include "pseudostate_impl.h"


namespace sxy
{


class state_pseudostate_impl:
	public virtual state_pseudostate, public pseudostate_impl
{
public:
	explicit state_pseudostate_impl( const std::string& _name );
	virtual ~state_pseudostate_impl() override;
	state_pseudostate_impl( const state_pseudostate_impl& ) = delete;
	state_pseudostate_impl& operator=( const state_pseudostate_impl& ) = delete;
	virtual const state_machine_element * get_parent() const override;
	virtual composite_state& get_parent_state() const override;
	virtual void set_parent_state( composite_state* const _parent_state ) override;
	virtual raw_composite_states get_ancestors( composite_state* const _final_ancestor ) const override;
	virtual raw_regions get_ancestors_as_regions() const override;


private:
	composite_state* parent_;
};


}


#endif
