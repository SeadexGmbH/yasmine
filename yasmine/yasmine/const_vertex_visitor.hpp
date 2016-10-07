//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CONST_VERTEX_VISITOR_7EEF8936_8C47_401E_BE7D_997A1A245728
#define CONST_VERTEX_VISITOR_7EEF8936_8C47_401E_BE7D_997A1A245728


#include "compatibility.hpp"


namespace sxy
{


class composite_state;
class final_state;
class simple_state;
class choice;
class deep_history;
class entry_point;
class exit_point;
class fork;
class initial_pseudostate;
class join;
class junction;
class shallow_history;
class terminate_pseudostate;


class const_vertex_visitor
{
public:
	const_vertex_visitor() = default;
	virtual ~const_vertex_visitor() noexcept = default;
	const_vertex_visitor( const const_vertex_visitor& ) = delete;
	const_vertex_visitor& operator=( const const_vertex_visitor& ) = delete;
	virtual void visit( const composite_state& _composite_state ) = 0;
	virtual void visit( const simple_state& _simple_state ) = 0;
	virtual void visit( const final_state& _final_state ) = 0;
	virtual void visit( const initial_pseudostate& _initial_pseudostate ) = 0;
	virtual void visit( const choice& _choice ) = 0;
	virtual void visit( const junction& _junction ) = 0;
	virtual void visit( const join& _join ) = 0;
	virtual void visit( const fork& _fork ) = 0;
	virtual void visit( const entry_point& _entry_point ) = 0;
	virtual void visit( const exit_point& _exit_point ) = 0;
	virtual void visit( const deep_history& _deep_history ) = 0;
	virtual void visit( const shallow_history& _shallow_history ) = 0;
	virtual void visit( const terminate_pseudostate& _terminate_pseudostate ) = 0;
};


}


#endif
