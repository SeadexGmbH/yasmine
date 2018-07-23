//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATES_TO_ENTER_VISITOR_IMPL_7DBD7D6E_B4AB_4156_83B3_3193383C141E
#define STATES_TO_ENTER_VISITOR_IMPL_7DBD7D6E_B4AB_4156_83B3_3193383C141E


#include "vertex_visitor.hpp"
#include "state_fwd.hpp"
#include "region_fwd.hpp"


namespace sxy
{


class vertex;


class states_to_enter_visitor_impl:
	public vertex_visitor
{
public:
	states_to_enter_visitor_impl( raw_states_by_nesting_level& _states_to_enter, 
		raw_const_region_set& _regions_to_enter, composite_state& _LCA_of_compound_transition,
		const vertex& _source_of_transition );
	virtual ~states_to_enter_visitor_impl() SX_NOEXCEPT SX_OVERRIDE;
	
	SX_NO_COPY(states_to_enter_visitor_impl)
	virtual void visit( composite_state& _composite_state ) SX_OVERRIDE;
	virtual void visit( simple_state& _simple_state ) SX_OVERRIDE;
	virtual void visit( final_state& _final_state ) SX_OVERRIDE;
	virtual void visit( initial_pseudostate& _initial_pseudostate ) SX_OVERRIDE;
	virtual void visit( choice& _choice ) SX_OVERRIDE;
	virtual void visit( junction& _junction ) SX_OVERRIDE;
	virtual void visit( join& _join ) SX_OVERRIDE;
	virtual void visit( fork& _fork ) SX_OVERRIDE;
	virtual void visit( entry_point& _entry_point ) SX_OVERRIDE;
	virtual void visit( exit_point& _exit_point ) SX_OVERRIDE;
	virtual void visit( deep_history& _deep_history ) SX_OVERRIDE;
	virtual void visit( shallow_history& _shallow_history ) SX_OVERRIDE;
	virtual void visit( terminate_pseudostate& _terminate_pseudostate ) SX_OVERRIDE;


private:
	void get_states_up_to_LCA( state& _state );
	void get_regions_up_to_LCA( const state& _state );
	void add_last_active_child_states_to_enter( const state& _state );
	void insert_states_to_enter( state& _state );	
	void get_all_parent_states_to_enter( choice& _choice );


	raw_states_by_nesting_level& states_to_enter_;
	raw_const_region_set& regions_to_enter_;
	composite_state& LCA_of_compound_transition_;
	const vertex& source_of_transition_;
};


}


#endif
