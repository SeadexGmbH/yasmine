//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOSITE_STATE_IMPL_2BA1A84B_EF73_4C0C_98B9_F75BA2FF388B
#define COMPOSITE_STATE_IMPL_2BA1A84B_EF73_4C0C_98B9_F75BA2FF388B


#include "composite_state.h"
#include "complex_state_impl.h"


namespace sxy
{


class composite_state_impl final:
	public virtual composite_state, public complex_state_impl
{
public:
	explicit composite_state_impl(	const std::string& _name, behavior_uptr _entry_action = nullptr, 
		behavior_uptr _exit_action = nullptr, const event_ids& _deferred_events = {} );
	virtual ~composite_state_impl() override;
	composite_state_impl( const composite_state_impl& ) = delete;

	composite_state_impl& operator=( const composite_state_impl& ) = delete;
	virtual region& add_region( region_uptr _region ) override;

	// !\brief Creates a region with the given name and adds it to the parent composite state.
	// !\param _region_name Name of the region.
	// !\return A reference to the newly created final state.
	virtual region& add_region( const std::string& _region_name ) override;
	virtual const regions& get_regions() const override;
	virtual regions& get_regions() override;
	virtual region * get_region( const std::string& _region_name ) const override;
	bool is_complete() const override;

	virtual const deep_history * get_deep_history() const override;
	virtual deep_history& add_deep_history( deep_history_uptr _deep_history ) override;

	// !\brief Creates a deep history with the given name and adds it to the parent composite state.
	// !\param _deep_history_name Name of the deep history.
	// !\return A reference to the newly created deep history.
	virtual deep_history& add_deep_history( const std::string& _deep_history_name ) override;
	virtual shallow_history * get_shallow_history() const override;
	virtual shallow_history& add_shallow_history( shallow_history_uptr _shallow_history ) override;

	// !\brief Creates a shallow history with the given name and adds it to the parent composite state.
	// !\param _shallow_history_name Name of the shallow history.
	// !\return A reference to the newly created shallow history.
	virtual shallow_history& add_shallow_history( const std::string& _shallow_history_name ) override;
	virtual const raw_const_entry_points get_entry_points() const override;
	virtual entry_point& add_entry_point( entry_point_uptr _entry_point ) override;

	// !\brief Creates an entry point with the given name and adds it to the parent composite state.
	// !\param _entry_point_name Name of the entry point.
	// !\return A reference to the newly created entry point.
	virtual entry_point& add_entry_point( const std::string& _entry_point_name ) override;
	virtual const raw_const_exit_points get_exit_points() const override;
	virtual exit_point& add_exit_point( exit_point_uptr _exit_point ) override;

	// !\brief Creates an exit point with the given name and adds it to the parent composite state.
	// !\param _exit_point_name Name of the exit point.
	// !\return A reference to the newly created exit point.
	virtual exit_point& add_exit_point( const std::string& _exit_point_name ) override;
	virtual vertex * get_pseudostate( const std::string& _name_of_pseudostate ) const override;
	virtual size_t get_region_index( const region* const _region ) const override;
	virtual size_t get_parent_region_index() const override;
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const override;
	void accept_vertex_visitor( vertex_visitor& _visitor ) override;
	virtual void accept_complex_state_visitor( complex_state_visitor& _visitor ) const override;
	virtual void accept_state_visitor( state_visitor& _visitor ) const override;
	virtual bool is_orthogonal() const override;


private:
	virtual bool check_if_regions_are_completed() const override;


	regions regions_;
	deep_history_uptr deep_history_;
	shallow_history_uptr shallow_history_;
	entry_points entry_points_;
	exit_points exit_points_;
};


}


#endif
