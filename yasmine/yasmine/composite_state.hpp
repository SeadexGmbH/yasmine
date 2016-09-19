//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOSITE_STATE_1AD1142C_AAD0_4161_B700_32D0C0441769
#define COMPOSITE_STATE_1AD1142C_AAD0_4161_B700_32D0C0441769


#include "composite_state_fwd.hpp"
#include "complex_state.hpp"
#include "shallow_history_fwd.hpp"
#include "deep_history_fwd.hpp"
#include "entry_point_fwd.hpp"
#include "exit_point_fwd.hpp"


namespace sxy
{


class composite_state:
	public virtual complex_state
{
public:
	composite_state() = default;
	virtual ~composite_state() noexcept override = default;
	composite_state( const composite_state& ) = delete;
	composite_state& operator=( const composite_state& ) = delete;
	virtual region& add_region( region_uptr _region ) = 0;
	virtual region& add_region( const std::string& _region_name ) = 0;
	virtual const deep_history * get_deep_history() const = 0;
	virtual deep_history& add_deep_history( deep_history_uptr _deep_history ) = 0;
	virtual deep_history& add_deep_history( const std::string& _deep_history_name ) = 0;
	virtual shallow_history * get_shallow_history() const = 0;
	virtual shallow_history& add_shallow_history( shallow_history_uptr _shallow_history ) = 0;
	virtual shallow_history& add_shallow_history( const std::string& _shallow_history_name ) = 0;
	virtual const raw_const_entry_points get_entry_points() const = 0;
	virtual entry_point& add_entry_point( entry_point_uptr _entry_point ) = 0;
	virtual entry_point& add_entry_point( const std::string& _entry_point_name ) = 0;
	virtual const raw_const_exit_points get_exit_points() const = 0;
	virtual exit_point& add_exit_point( exit_point_uptr _exit_point ) = 0;
	virtual exit_point& add_exit_point( const std::string& _exit_point ) = 0;
	virtual size_t get_region_index( const region* const _region ) const = 0;
	virtual bool check_if_regions_are_completed() const = 0;
	virtual bool is_orthogonal() const = 0;
};


}


#endif
