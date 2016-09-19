//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERTEX_IMPL_B16E40A6_719B_4DFD_91DB_D4790C6EC14D
#define VERTEX_IMPL_B16E40A6_719B_4DFD_91DB_D4790C6EC14D


#include <string>

#include "vertex.h"
#include "state_machine_element_impl.h"


namespace sxy
{


class vertex_impl:
	public virtual vertex, public state_machine_element_impl
{
public:
	explicit vertex_impl( const std::string& _name );
	virtual ~vertex_impl() override;
	vertex_impl( const vertex_impl& ) = delete;
	vertex_impl& operator=( const vertex_impl& ) = delete;
	virtual void add_outgoing_transition( transition& _outgoing_transition ) override;
	virtual void add_incoming_transition( transition& _incoming_transition ) override;
	virtual void remove_outgoing_transition( const transition& _outgoing_transition ) override;
	virtual void remove_incoming_transition( const transition& _incoming_transition ) override;
	virtual const raw_transitions& get_outgoing_transitions() const override;
	virtual const raw_transitions& get_incoming_transitions() const override;
	virtual uri get_uri() const override;
	transition * search_transition( const event& _event ) const override;
	virtual region * LCA_region( const vertex& _target_vertex ) const override;
	virtual composite_state * LCA_composite_state( const vertex& _rhs ) const override;


private:
	void add_ancestor_uri( uri& _uri ) const override;


	raw_transitions outgoing_transitions_;
	raw_transitions incoming_transitions_;
};


}


#endif
