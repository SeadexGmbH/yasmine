//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_COMPOSITE_STATE_1AD1142C_AAD0_4161_B700_32D0C0441769
#define I_COMPOSITE_STATE_1AD1142C_AAD0_4161_B700_32D0C0441769


#include "i_composite_state_fwd.h"
#include "i_complex_state.h"
#include "i_shallow_history_fwd.h"
#include "i_deep_history_fwd.h"
#include "i_entry_point_fwd.h"
#include "i_exit_point_fwd.h"


namespace sxy
{


class i_composite_state:
	public virtual i_complex_state
{
public:
	i_composite_state() = default;
	virtual ~i_composite_state() override = default;
	i_composite_state( const i_composite_state& ) = delete;
	i_composite_state& operator=( const i_composite_state& ) = delete;
	virtual i_region& add_region( i_region_uptr p_region ) = 0;
	virtual i_region& add_region( const std::string& p_region_name ) = 0;
	virtual const i_deep_history * get_deep_history() const = 0;
	virtual i_deep_history& add_deep_history( i_deep_history_uptr p_deep_history ) = 0;
	virtual i_deep_history& add_deep_history( const std::string& p_deep_history_name ) = 0;
	virtual i_shallow_history * get_shallow_history() const = 0;
	virtual i_shallow_history& add_shallow_history( i_shallow_history_uptr p_shallow_history ) = 0;
	virtual i_shallow_history& add_shallow_history( const std::string& p_shallow_history_name ) = 0;
	virtual const t_raw_const_entry_points get_entry_points() const = 0;
	virtual i_entry_point& add_entry_point( i_entry_point_uptr p_entry_point ) = 0;
	virtual i_entry_point& add_entry_point( const std::string& p_entry_point_name ) = 0;
	virtual const t_raw_const_exit_points get_exit_points() const = 0;
	virtual i_exit_point& add_exit_point( i_exit_point_uptr p_exit_point ) = 0;
	virtual i_exit_point& add_exit_point( const std::string& p_exit_point ) = 0;
	virtual size_t get_region_index( const i_region* const p_region ) const = 0;
	virtual bool check_if_regions_are_completed() const = 0;
	virtual bool is_orthogonal() const = 0;
};


}


#endif
