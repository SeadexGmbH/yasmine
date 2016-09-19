//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_CHECK_IF_ALL_INCOMING_TRANSITIONS_SOURCES_ARE_ACTIVE_VISITOR_H
#define T_CHECK_IF_ALL_INCOMING_TRANSITIONS_SOURCES_ARE_ACTIVE_VISITOR_H


#include "i_complex_state_visitor.h"


namespace sxy
{


class i_event;


class t_check_if_all_incoming_transitions_sources_are_active_visitor final:
	public i_complex_state_visitor
{
public:
	t_check_if_all_incoming_transitions_sources_are_active_visitor();
	virtual ~t_check_if_all_incoming_transitions_sources_are_active_visitor() override;
	t_check_if_all_incoming_transitions_sources_are_active_visitor(
		const t_check_if_all_incoming_transitions_sources_are_active_visitor& ) = delete;
	t_check_if_all_incoming_transitions_sources_are_active_visitor& operator=(
		const t_check_if_all_incoming_transitions_sources_are_active_visitor& ) = delete;
	virtual void visit( const i_composite_state& p_composite_state ) override;
	virtual void visit( const i_simple_state& p_simple_state ) override;
	bool get_result() const;


private:
	bool m_source_is_finished;
};


}
#endif
