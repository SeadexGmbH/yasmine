//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_STATE_TO_ENTER_VISITOR_E9F45A08_EB9F_42B7_9561_64ED792DCA65
#define T_STATE_TO_ENTER_VISITOR_E9F45A08_EB9F_42B7_9561_64ED792DCA65


#include "i_vertex_visitor.h"
#include "i_state_fwd.h"
#include "i_region_fwd.h"


namespace sxy
{


class t_states_to_enter_visitor:
	public virtual i_vertex_visitor
{
public:
	t_states_to_enter_visitor( t_raw_states_by_nesting_level& p_states_to_enter, 
		t_raw_const_region_set& p_regions_to_enter,	i_composite_state& p_LCA_of_compound_transition );
	virtual ~t_states_to_enter_visitor() override;
	t_states_to_enter_visitor( const t_states_to_enter_visitor& ) = delete;
	t_states_to_enter_visitor& operator=( const t_states_to_enter_visitor& ) = delete;
	virtual void visit( i_composite_state& p_composite_state ) override;
	virtual void visit( i_simple_state& p_simple_state ) override;
	virtual void visit( i_final_state& p_final_state ) override;
	virtual void visit( i_initial_pseudostate& p_initial_pseudostate ) override;
	virtual void visit( i_choice& p_choice ) override;
	virtual void visit( i_junction& p_junction ) override;
	virtual void visit( i_join& p_join ) override;
	virtual void visit( i_fork& p_fork ) override;
	virtual void visit( i_entry_point& p_entry_point ) override;
	virtual void visit( i_exit_point& p_exit_point ) override;
	virtual void visit( i_deep_history& p_deep_history ) override;
	virtual void visit( i_shallow_history& p_shallow_history ) override;
	virtual void visit( i_terminate_pseudostate& p_terminate_pseudostate ) override;


private:
	void get_states_up_to_LCA( i_state& p_state );
	void get_regions_up_to_LCA( const i_state& p_state );
	void add_last_active_child_states_to_enter( const i_state& p_state );
	void insert_states_to_enter( i_state& p_state );


	t_raw_states_by_nesting_level& m_states_to_enter;
	t_raw_const_region_set& m_regions_to_enter;
	i_composite_state& m_LCA_of_compound_transition;
};


}


#endif
