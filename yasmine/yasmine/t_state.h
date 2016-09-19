//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_STATE_141155CA_2333_4C55_9D75_D1FD760B22D5
#define T_STATE_141155CA_2333_4C55_9D75_D1FD760B22D5


#include "i_state.h"
#include "t_vertex.h"
#include "i_behavior_fwd.h"


namespace sxy
{


class t_state:
	public virtual i_state, public t_vertex
{
public:
	explicit t_state( const std::string& p_name );
	virtual ~t_state() override;
	t_state( const t_state& ) = delete;
	t_state& operator=( const t_state& ) = delete;
	virtual const i_state_machine_element * get_parent() const override;
	virtual void set_parent_region( i_region* const p_parent_region ) override;
	virtual i_region * get_parent_region() const override;
	virtual size_t get_parent_region_index() const override;
	virtual i_region * get_region( const std::string& p_region_name ) const override;
	virtual i_vertex * get_pseudostate( const std::string& p_name_of_pseudostate ) const override;
	virtual t_raw_composite_states get_ancestors( i_composite_state* const p_final_ancestor ) const override;
	virtual t_raw_regions get_ancestors_as_regions() const override;
	virtual std::size_t get_nesting_level() const override;
	virtual void set_was_active() override;
	virtual bool was_active() const override;
	virtual void set_active() override;
	virtual void set_inactive() override;
	virtual bool is_active() const override;
	virtual bool is_complete() const override;
	virtual void execute_do_behavior( const i_event& p_event ) const override;
	virtual void execute_enter_behavior( const i_event& p_event ) const override;
	virtual void execute_exit_behavior( const i_event& p_event ) const override;
	virtual void enter_state( const i_event& p_event ) override;
	virtual void exit_state( const i_event& p_event ) override;


private:
	bool m_was_active;
	i_region* m_parent;
};


}


#endif
