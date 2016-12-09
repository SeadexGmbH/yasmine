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


class final_state_impl Y_FINAL:
	public virtual final_state, public state_impl
{
public:
	explicit final_state_impl( const std::string& _name );
	virtual ~final_state_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(final_state_impl)
	virtual behaviour * get_entry_behaviour() const Y_OVERRIDE;
	virtual behaviour * get_exit_behaviour() const Y_OVERRIDE;
	virtual const regions& get_regions() const Y_OVERRIDE;
	virtual regions& get_regions() Y_OVERRIDE;
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_state_visitor( state_visitor& _visitor ) const Y_OVERRIDE;
	virtual bool is_event_deferred( const event_id& _event_id ) const Y_OVERRIDE;
};


}


#endif
