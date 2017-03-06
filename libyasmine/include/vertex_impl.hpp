//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERTEX_IMPL_B16E40A6_719B_4DFD_91DB_D4790C6EC14D
#define VERTEX_IMPL_B16E40A6_719B_4DFD_91DB_D4790C6EC14D


#include <string>

#include "vertex.hpp"
#include "state_machine_element_impl.hpp"


namespace sxy
{


class vertex_impl:
	public virtual vertex, public state_machine_element_impl
{
public:
	explicit vertex_impl( const std::string& _name );
	virtual ~vertex_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY( vertex_impl )
	virtual composite_state* get_root_state() Y_OVERRIDE;
	virtual const composite_state* get_root_state() const Y_OVERRIDE;
	virtual void add_outgoing_transition( transition& _outgoing_transition ) Y_OVERRIDE;
	virtual void add_incoming_transition( transition& _incoming_transition ) Y_OVERRIDE;
	virtual void remove_outgoing_transition( const transition& _outgoing_transition ) Y_OVERRIDE;
	virtual void remove_incoming_transition( const transition& _incoming_transition ) Y_OVERRIDE;
	virtual const raw_transitions& get_outgoing_transitions() const Y_OVERRIDE;
	virtual const raw_transitions& get_incoming_transitions() const Y_OVERRIDE;
	virtual uri get_uri() const Y_OVERRIDE;
	transition* search_transition( const event& _event, event_collector& _event_collector ) const Y_OVERRIDE;
	virtual region* LCA_region( const vertex& _target_vertex ) const Y_OVERRIDE;
	virtual composite_state* LCA_composite_state( const vertex& _rhs ) const Y_OVERRIDE;


private:
	void add_ancestor_uri( uri& _uri ) const Y_OVERRIDE;
	raw_transitions::const_iterator find_first_transition_without_guard( const raw_transitions& _vector_of_transitions );
	static bool has_no_guard( const transition* const _transition );


	raw_transitions outgoing_transitions_;
	raw_transitions incoming_transitions_;
};


}


#endif
