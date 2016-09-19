//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FINAL_STATE_IMPL_05AFD9ED_2F4A_46B8_9C77_4933E67B5520
#define FINAL_STATE_IMPL_05AFD9ED_2F4A_46B8_9C77_4933E67B5520


#include "final_state.hpp"
#include "state_impl.hpp"


namespace sxy
{


class final_state_impl final:
	public virtual final_state, public state_impl
{
public:
	explicit final_state_impl( const std::string& _name );
	virtual ~final_state_impl() noexcept override = default;
	final_state_impl( const final_state_impl& ) = delete;
	final_state_impl& operator=( const final_state_impl& ) = delete;
	virtual behavior * get_entry_behavior() const override;
	virtual behavior * get_exit_behavior() const override;
	virtual const regions& get_regions() const override;
	virtual regions& get_regions() override;
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const override;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) override;
	virtual void accept_state_visitor( state_visitor& _visitor ) const override;
	virtual bool is_event_deferred( const event_id& _event_id ) const override;
};


}


#endif
