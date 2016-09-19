//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef PSEUDOSTATE_VISITOR_6250307A_E61E_4175_B03E_6C113149B5F2
#define PSEUDOSTATE_VISITOR_6250307A_E61E_4175_B03E_6C113149B5F2


namespace sxy
{


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


class pseudostate_visitor
{
public:
	pseudostate_visitor() = default;
	virtual ~pseudostate_visitor() noexcept = default;
	pseudostate_visitor( const pseudostate_visitor& ) = delete;
	pseudostate_visitor& operator=( const pseudostate_visitor& ) = delete;
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
