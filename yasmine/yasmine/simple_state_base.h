//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SIMPLE_STATE_BASE_804FA805_18CB_4778_8C90_9B7AB2023D3B
#define SIMPLE_STATE_BASE_804FA805_18CB_4778_8C90_9B7AB2023D3B


#include "simple_state.h"
#include "complex_state_impl.h"

#include "behavior_exception_fwd.h"
#include "behavior_exception.h"


namespace sxy
{


class simple_state_base:
	public virtual simple_state, public complex_state_impl
{


public:
	simple_state_base( const std::string& _name, behavior_uptr _entry_action,	behavior_uptr _exit_action, 
		const event_ids& _deferred_events, behavior_exception_uptr _error_event );
	~simple_state_base();	
	simple_state_base( const simple_state_base& ) = delete;
	simple_state_base& operator=(	const simple_state_base& ) = delete;

	virtual const regions& get_regions() const override;
	virtual regions& get_regions() override;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const override;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) override;
	virtual void accept_complex_state_visitor( complex_state_visitor& _visitor ) const override;
	virtual void accept_state_visitor( state_visitor& _visitor ) const override;	
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual bool has_error_event() const override;
	virtual const behavior_exception* const get_error_event() const override;


private:
	behavior_exception_uptr error_event_;
};


}


#endif
