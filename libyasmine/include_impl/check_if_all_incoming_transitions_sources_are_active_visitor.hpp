//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CHECK_IF_ALL_INCOMING_TRANSITIONS_SOURCES_ARE_ACTIVE_VISITOR_H
#define CHECK_IF_ALL_INCOMING_TRANSITIONS_SOURCES_ARE_ACTIVE_VISITOR_H


#include "complex_state_visitor.hpp"


namespace sxy
{


class event;


class check_if_all_incoming_transitions_sources_are_active_visitor Y_FINAL:
	public complex_state_visitor
{
public:
	check_if_all_incoming_transitions_sources_are_active_visitor();
	virtual ~check_if_all_incoming_transitions_sources_are_active_visitor() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(check_if_all_incoming_transitions_sources_are_active_visitor)
	virtual void visit( const composite_state& _composite_state ) Y_OVERRIDE;
	virtual void visit( const simple_state& _simple_state ) Y_OVERRIDE;
	bool get_result() const;


private:
	bool source_is_finished_;
};


}
#endif
