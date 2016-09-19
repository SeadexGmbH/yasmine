//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_SIMPLE_STATE_69C22969_31D5_4E5F_B1E2_F3469C517696
#define T_SIMPLE_STATE_69C22969_31D5_4E5F_B1E2_F3469C517696


#include "i_simple_state.h"
#include "t_complex_state.h"


namespace sxy
{


class t_simple_state final:
	public virtual i_simple_state, public t_complex_state
{
public:
	explicit t_simple_state( const std::string& p_name,	i_behavior_uptr do_action = nullptr, 
		i_behavior_uptr p_entry_action = nullptr,	i_behavior_uptr p_exit_action = nullptr,
		const t_event_ids& p_deferred_events = {} );
	virtual ~t_simple_state() override;
	t_simple_state( const t_simple_state& ) = delete;
	t_simple_state& operator=( const t_simple_state& ) = delete;
	virtual const i_behavior * get_do() const override;
	virtual const t_regions& get_regions() const override;
	virtual t_regions& get_regions() override;
	virtual void accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const override;
	virtual void accept_vertex_visitor( i_vertex_visitor& p_visitor ) override;
	virtual void accept_complex_state_visitor( i_complex_state_visitor& p_visitor ) const override;
	virtual void accept_state_visitor( i_state_visitor& p_visitor ) const override;
	void execute_do_behavior( const i_event& p_event ) const override;
	virtual bool check( t_state_machine_defects& p_defects ) const override;


private:
	i_behavior_uptr m_do;
};


}


#endif
