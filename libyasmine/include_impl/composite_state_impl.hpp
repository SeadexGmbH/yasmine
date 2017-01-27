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


#include "composite_state.hpp"
#include "complex_state_impl.hpp"
#include "deep_history.hpp"
#include "shallow_history.hpp"
#include "entry_point.hpp"
#include "exit_point.hpp"


namespace sxy
{


class composite_state_impl Y_FINAL:
	public virtual composite_state, public complex_state_impl
{
public:
	explicit composite_state_impl(	const std::string& _name, behavior_uptr _entry_action = behavior_uptr(),
		behavior_uptr _exit_action = behavior_uptr(), const event_ids& _deferred_events = event_ids() );
	virtual ~composite_state_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(composite_state_impl)
	virtual region& add_region( region_uptr _region ) Y_OVERRIDE;

	//!\brief Creates a region with the given name and adds it to the parent composite state.
	//!\param _region_name Name of the region.
	//!\return A reference to the newly created final state.
	virtual region& add_region( const std::string& _region_name ) Y_OVERRIDE;
	virtual const regions& get_regions() const Y_OVERRIDE;
	virtual regions& get_regions() Y_OVERRIDE;
	virtual region * get_region( const std::string& _region_name ) const Y_OVERRIDE;
	bool is_complete() const Y_OVERRIDE;

	virtual const deep_history * get_deep_history() const Y_OVERRIDE;
	virtual deep_history& add_deep_history( deep_history_uptr _deep_history ) Y_OVERRIDE;

	//!\brief Creates a deep history with the given name and adds it to the parent composite state.
	//!\param _deep_history_name Name of the deep history.
	//!\return A reference to the newly created deep history.
	virtual deep_history& add_deep_history( const std::string& _deep_history_name ) Y_OVERRIDE;
	virtual shallow_history * get_shallow_history() const Y_OVERRIDE;
	virtual shallow_history& add_shallow_history( shallow_history_uptr _shallow_history ) Y_OVERRIDE;

	//!\brief Creates a shallow history with the given name and adds it to the parent composite state.
	//!\param _shallow_history_name Name of the shallow history.
	//!\return A reference to the newly created shallow history.
	virtual shallow_history& add_shallow_history( const std::string& _shallow_history_name ) Y_OVERRIDE;
	virtual const raw_const_entry_points get_entry_points() const Y_OVERRIDE;
	virtual entry_point& add_entry_point( entry_point_uptr _entry_point ) Y_OVERRIDE;

	//!\brief Creates an entry point with the given name and adds it to the parent composite state.
	//!\param _entry_point_name Name of the entry point.
	//!\return A reference to the newly created entry point.
	virtual entry_point& add_entry_point( const std::string& _entry_point_name ) Y_OVERRIDE;
	virtual const raw_const_exit_points get_exit_points() const Y_OVERRIDE;
	virtual exit_point& add_exit_point( exit_point_uptr _exit_point ) Y_OVERRIDE;

	//!\brief Creates an exit point with the given name and adds it to the parent composite state.
	//!\param _exit_point_name Name of the exit point.
	//!\return A reference to the newly created exit point.
	virtual exit_point& add_exit_point( const std::string& _exit_point_name ) Y_OVERRIDE;
	virtual vertex * get_pseudostate( const std::string& _name_of_pseudostate ) const Y_OVERRIDE;
	virtual size_t get_region_index( const region* const _region ) const Y_OVERRIDE;
	virtual size_t get_parent_region_index() const Y_OVERRIDE;
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_complex_state_visitor( complex_state_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_state_visitor( state_visitor& _visitor ) const Y_OVERRIDE;
	virtual bool is_orthogonal() const Y_OVERRIDE;


private:
	virtual bool check_if_regions_are_completed() const Y_OVERRIDE;
	static bool regions_are_equal( const region* const _region, const region_uptr& _vector_element_region );


	regions regions_;
	deep_history_uptr deep_history_;
	shallow_history_uptr shallow_history_;
	entry_points entry_points_;
	exit_points exit_points_;
};


}


#endif
