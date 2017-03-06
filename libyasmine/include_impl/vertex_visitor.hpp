//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERTEX_VISITOR_D71F9484_F3C5_4DEF_BC94_F273B6223268
#define VERTEX_VISITOR_D71F9484_F3C5_4DEF_BC94_F273B6223268


#include "non_copyable.hpp"


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


class vertex_visitor
{
public:
	vertex_visitor()
	{
		// Nothing to do...
	}


	virtual ~vertex_visitor() Y_NOEXCEPT
	{
		// Nothing to do...
	}


	Y_NO_COPY(vertex_visitor)
	virtual void visit( composite_state& _composite_state ) = 0;
	virtual void visit( simple_state& _simple_state ) = 0;
	virtual void visit( final_state& _final_state ) = 0;
	virtual void visit( initial_pseudostate& _initial_pseudostate ) = 0;
	virtual void visit( choice& _choice ) = 0;
	virtual void visit( junction& _junction ) = 0;
	virtual void visit( join& _join ) = 0;
	virtual void visit( fork& _fork ) = 0;
	virtual void visit( entry_point& _entry_point ) = 0;
	virtual void visit( exit_point& _exit_point ) = 0;
	virtual void visit( deep_history& _deep_history ) = 0;
	virtual void visit( shallow_history& _shallow_history ) = 0;
	virtual void visit( terminate_pseudostate& _terminate_pseudostate ) = 0;
};


}


#endif
