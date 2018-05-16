//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SIMPLE_STATE_BASE_804FA805_18CB_4778_8C90_9B7AB2023D3B
#define SIMPLE_STATE_BASE_804FA805_18CB_4778_8C90_9B7AB2023D3B


#include "simple_state.hpp"
#include "complex_state_impl.hpp"


namespace sxy
{


class simple_state_base:
	public simple_state, public complex_state_impl
{


public:
	simple_state_base( const std::string& _name, behavior_uptr _entry_action, behavior_uptr _exit_action, 
		const event_ids& _deferred_events, event_sptr _error_event );
	virtual ~simple_state_base() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(simple_state_base)
	virtual const regions& get_regions() const SX_OVERRIDE;
	virtual regions& get_regions() SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_complex_state_visitor( complex_state_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_state_visitor( state_visitor& _visitor ) const SX_OVERRIDE;
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual bool has_error_event() const SX_OVERRIDE;
	virtual event_sptr get_error_event() const SX_OVERRIDE;


private:
	event_sptr error_event_;
};


}


#endif
