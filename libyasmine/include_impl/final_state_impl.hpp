//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FINAL_STATE_IMPL_05AFD9ED_2F4A_46B8_9C77_4933E67B5520
#define FINAL_STATE_IMPL_05AFD9ED_2F4A_46B8_9C77_4933E67B5520


#include "final_state.hpp"
#include "state_impl.hpp"


namespace sxy
{


class final_state_impl SX_FINAL:
	public virtual final_state, public state_impl
{
public:
	explicit final_state_impl( const std::string& _name );
	virtual ~final_state_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(final_state_impl)
	virtual behavior * get_entry_behavior() const SX_OVERRIDE;
	virtual behavior * get_exit_behavior() const SX_OVERRIDE;
	virtual const regions& get_regions() const SX_OVERRIDE;
	virtual regions& get_regions() SX_OVERRIDE;
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_state_visitor( state_visitor& _visitor ) const SX_OVERRIDE;
	virtual bool is_event_deferred( const event_id& _event_id ) const SX_OVERRIDE;
};


}


#endif
