//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef JOIN_IMPL_18BD2E66_59C9_4BB1_B5A9_5B444B6CFE1E
#define JOIN_IMPL_18BD2E66_59C9_4BB1_B5A9_5B444B6CFE1E


#include "join.hpp"
#include "region_pseudostate_impl.hpp"

namespace sxy
{


class join_impl Y_FINAL:
	public virtual join, public region_pseudostate_impl
{
public:
	explicit join_impl( const std::string& _name );
	virtual ~join_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(join_impl)
	virtual bool check_if_all_source_states_of_incoming_transitions_are_active() const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const Y_OVERRIDE;
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void add_outgoing_transition( transition& _outgoing_transition ) Y_OVERRIDE;
};


}


#endif
