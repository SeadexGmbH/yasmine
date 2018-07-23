//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_PSEUDOSTATE_IMPL_2EA11FC4_EEC5_430E_AB7B_27E54A1202A0
#define STATE_PSEUDOSTATE_IMPL_2EA11FC4_EEC5_430E_AB7B_27E54A1202A0


#include "state_pseudostate.hpp"
#include "pseudostate_impl.hpp"
#include "optimization.hpp"


namespace sxy
{


class state_pseudostate_impl:
	public virtual state_pseudostate, public pseudostate_impl
{
public:
	explicit state_pseudostate_impl( const std::string& _name );
	virtual ~state_pseudostate_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(state_pseudostate_impl)
	virtual const state_machine_element * get_parent() const SX_OVERRIDE;
	virtual composite_state& get_parent_state() const SX_OVERRIDE;
	virtual void set_parent_state( composite_state* const _parent_state ) SX_OVERRIDE;
	virtual raw_composite_states get_ancestors( composite_state* const _final_ancestor,
		bool _include_final_ancestor = true ) const SX_OVERRIDE;
	virtual raw_regions get_ancestors_as_regions() const SX_OVERRIDE;


private:
	void collect_ancestors( raw_composite_states& _ancestors, composite_state* const _final_ancestor, 
		bool _include_final_ancestor )const;
	composite_state* parent_;

#ifdef Y_OPTIMIZE_4_SPEED
	mutable raw_composite_states ancestors_;
	mutable raw_regions ancestors_as_regions_;
#endif 

};


}


#endif
