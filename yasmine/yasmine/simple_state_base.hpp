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


#include "simple_state.hpp"
#include "complex_state_impl.hpp"


namespace sxy
{


class simple_state_base:
	public virtual simple_state, public complex_state_impl
{


public:
	simple_state_base( const std::string& _name, behaviour_uptr _entry_action,	behaviour_uptr _exit_action, 
		const event_ids& _deferred_events, event_sptr _error_event );
	virtual ~simple_state_base() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(simple_state_base)
	virtual const regions& get_regions() const Y_OVERRIDE;
	virtual regions& get_regions() Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_complex_state_visitor( complex_state_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_state_visitor( state_visitor& _visitor ) const Y_OVERRIDE;	
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual bool has_error_event() const Y_OVERRIDE;
	virtual event_sptr get_error_event() const Y_OVERRIDE;


private:
	event_sptr error_event_;
};


}


#endif
