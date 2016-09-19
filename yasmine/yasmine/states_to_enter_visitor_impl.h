//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATES_TO_ENTER_VISITOR_IMPL_7DBD7D6E_B4AB_4156_83B3_3193383C141E
#define STATES_TO_ENTER_VISITOR_IMPL_7DBD7D6E_B4AB_4156_83B3_3193383C141E


#include "vertex_visitor.h"
#include "state_fwd.h"
#include "region_fwd.h"


namespace sxy
{


class states_to_enter_visitor_impl:
	public virtual vertex_visitor
{
public:
	states_to_enter_visitor_impl( raw_states_by_nesting_level& _states_to_enter, 
		raw_const_region_set& _regions_to_enter,	composite_state& _LCA_of_compound_transition );
	virtual ~states_to_enter_visitor_impl() override;
	states_to_enter_visitor_impl( const states_to_enter_visitor_impl& ) = delete;
	states_to_enter_visitor_impl& operator=( const states_to_enter_visitor_impl& ) = delete;
	virtual void visit( composite_state& _composite_state ) override;
	virtual void visit( simple_state& _simple_state ) override;
	virtual void visit( final_state& _final_state ) override;
	virtual void visit( initial_pseudostate& _initial_pseudostate ) override;
	virtual void visit( choice& _choice ) override;
	virtual void visit( junction& _junction ) override;
	virtual void visit( join& _join ) override;
	virtual void visit( fork& _fork ) override;
	virtual void visit( entry_point& _entry_point ) override;
	virtual void visit( exit_point& _exit_point ) override;
	virtual void visit( deep_history& _deep_history ) override;
	virtual void visit( shallow_history& _shallow_history ) override;
	virtual void visit( terminate_pseudostate& _terminate_pseudostate ) override;


private:
	void get_states_u_to_LCA( state& _state );
	void get_regions_u_to_LCA( const state& _state );
	void add_last_active_child_states_to_enter( const state& _state );
	void insert_states_to_enter( state& _state );


	raw_states_by_nesting_level& states_to_enter_;
	raw_const_region_set& regions_to_enter_;
	composite_state& LCA_of_compound_transition_;
};


}


#endif
