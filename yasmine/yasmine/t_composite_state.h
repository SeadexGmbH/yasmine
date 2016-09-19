//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_COMPOSITE_STATE_219EF624_24D5_4E33_8341_ACDA517EC5E7
#define T_COMPOSITE_STATE_219EF624_24D5_4E33_8341_ACDA517EC5E7


#include "i_composite_state.h"
#include "t_complex_state.h"


namespace sxy
{


class t_composite_state final:
	public virtual i_composite_state, public t_complex_state
{
public:
	explicit t_composite_state(	const std::string& p_name, i_behavior_uptr p_entry_action = nullptr, 
		i_behavior_uptr p_exit_action = nullptr, const t_event_ids& p_deferred_events = {} );
	virtual ~t_composite_state() override;
	t_composite_state( const t_composite_state& ) = delete;

	t_composite_state& operator=( const t_composite_state& ) = delete;
	virtual i_region& add_region( i_region_uptr p_region ) override;

	// !\brief Creates a region with the given name and adds it to the parent composite state.
	// !\param p_region_name Name of the region.
	// !\return A reference to the newly created final state.
	virtual i_region& add_region( const std::string& p_region_name ) override;
	virtual const t_regions& get_regions() const override;
	virtual t_regions& get_regions() override;
	virtual i_region * get_region( const std::string& p_region_name ) const override;
	bool is_complete() const override;

	virtual const i_deep_history * get_deep_history() const override;
	virtual i_deep_history& add_deep_history( i_deep_history_uptr p_deep_history ) override;

	// !\brief Creates a deep history with the given name and adds it to the parent composite state.
	// !\param p_deep_history_name Name of the deep history.
	// !\return A reference to the newly created deep history.
	virtual i_deep_history& add_deep_history( const std::string& p_deep_history_name ) override;
	virtual i_shallow_history * get_shallow_history() const override;
	virtual i_shallow_history& add_shallow_history( i_shallow_history_uptr p_shallow_history ) override;

	// !\brief Creates a shallow history with the given name and adds it to the parent composite state.
	// !\param p_shallow_history_name Name of the shallow history.
	// !\return A reference to the newly created shallow history.
	virtual i_shallow_history& add_shallow_history( const std::string& p_shallow_history_name ) override;
	virtual const t_raw_const_entry_points get_entry_points() const override;
	virtual i_entry_point& add_entry_point( i_entry_point_uptr p_entry_point ) override;

	// !\brief Creates an entry point with the given name and adds it to the parent composite state.
	// !\param p_entry_point_name Name of the entry point.
	// !\return A reference to the newly created entry point.
	virtual i_entry_point& add_entry_point( const std::string& p_entry_point_name ) override;
	virtual const t_raw_const_exit_points get_exit_points() const override;
	virtual i_exit_point& add_exit_point( i_exit_point_uptr p_exit_point ) override;

	// !\brief Creates an exit point with the given name and adds it to the parent composite state.
	// !\param p_exit_point_name Name of the exit point.
	// !\return A reference to the newly created exit point.
	virtual i_exit_point& add_exit_point( const std::string& p_exit_point_name ) override;
	virtual i_vertex * get_pseudostate( const std::string& p_name_of_pseudostate ) const override;
	virtual size_t get_region_index( const i_region* const p_region ) const override;
	virtual size_t get_parent_region_index() const override;
	virtual bool check( t_state_machine_defects& p_defects ) const override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_complex_state_visitor( i_complex_state_visitor& p_visitor ) const override;
	virtual void accept_state_visitor( i_state_visitor& p_visitor ) const override;
	virtual bool is_orthogonal() const override;


private:
	virtual bool check_if_regions_are_completed() const override;


	t_regions m_regions;
	i_deep_history_uptr m_deep_history;
	i_shallow_history_uptr m_shallow_history;
	t_entry_points m_entry_points;
	t_exit_points m_exit_points;
};


}


#endif
