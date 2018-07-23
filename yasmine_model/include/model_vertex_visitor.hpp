//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MODEL_VERTEX_VISITOR_2F339562_6B94_4450_95C9_F0FA105E4D6B
#define MODEL_VERTEX_VISITOR_2F339562_6B94_4450_95C9_F0FA105E4D6B


#include "essentials/non_copyable.hpp"
#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


namespace model
{


class simple_state_model;
class composite_state_model;
class final_state_model;
class initial_pseudostate_model;
class terminate_pseudostate_model;
class entry_point_model;
class exit_point_model;
class deep_history_model;
class shallow_history_model;
class join_model;
class junction_model;
class choice_model;
class fork_model;


class model_vertex_visitor
{
public:
	model_vertex_visitor()
	{
		// Nothing to do...
	}


	virtual ~model_vertex_visitor() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY( model_vertex_visitor )
	virtual void visit( const simple_state_model& _simple_state_model ) = 0;
	virtual void visit( const composite_state_model& _composite_state_model ) = 0;
	virtual void visit( const final_state_model& _final_state_model ) const = 0;
	virtual void visit( const initial_pseudostate_model& _initial_pseudostate_model ) const = 0;
	virtual void visit( const terminate_pseudostate_model& _terminate_pseudostate_model ) const = 0;
	virtual void visit( const entry_point_model& _entry_point_model ) const = 0;
	virtual void visit( const exit_point_model& _exit_point_model ) const = 0;
	virtual void visit( const deep_history_model& _deep_history_model ) const = 0;
	virtual void visit( const shallow_history_model& _shallow_history_model ) const = 0;
	virtual void visit( const join_model& _join_model ) const = 0;
	virtual void visit( const fork_model& _fork_model ) const = 0;
	virtual void visit( const junction_model& _junction_model ) const = 0;
	virtual void visit( const choice_model& _choice_model ) const = 0;
};


}


}


#endif
