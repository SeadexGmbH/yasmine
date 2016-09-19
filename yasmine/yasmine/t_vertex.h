//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_VERTEX_C12397AA_F439_49F8_99C3_9665CC5390C0
#define T_VERTEX_C12397AA_F439_49F8_99C3_9665CC5390C0

#include <string>

#include "i_vertex.h"
#include "t_state_machine_element.h"


namespace sxy
{


class t_vertex:
	public virtual i_vertex, public t_state_machine_element
{
public:
	explicit t_vertex( const std::string& p_name );
	virtual ~t_vertex() override;
	t_vertex( const t_vertex& ) = delete;
	t_vertex& operator=( const t_vertex& ) = delete;
	virtual void add_outgoing_transition( i_transition& p_outgoing_transition ) override;
	virtual void add_incoming_transition( i_transition& p_incoming_transition ) override;
	virtual void remove_outgoing_transition( const i_transition& p_outgoing_transition ) override;
	virtual void remove_incoming_transition( const i_transition& p_incoming_transition ) override;
	virtual const t_raw_transitions& get_outgoing_transitions() const override;
	virtual const t_raw_transitions& get_incoming_transitions() const override;
	virtual t_uri get_uri() const override;
	i_transition * search_transition( const i_event& p_event ) const override;
	virtual i_region * LCA_region( const i_vertex& p_target_vertex ) const override;
	virtual i_composite_state * LCA_composite_state( const i_vertex& p_rhs ) const override;


private:
	void add_ancestor_uri( t_uri& p_uri ) const override;


	t_raw_transitions m_outgoing_transitions;
	t_raw_transitions m_incoming_transitions;
};


}


#endif
