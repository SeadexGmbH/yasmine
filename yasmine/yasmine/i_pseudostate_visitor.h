//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_PSEUDOSTATE_VISITOR_H
#define I_PSEUDOSTATE_VISITOR_H


namespace sxy
{


class i_choice;
class i_deep_history;
class i_entry_point;
class i_exit_point;
class i_fork;
class i_initial_pseudostate;
class i_join;
class i_junction;
class i_shallow_history;
class i_terminate_pseudostate;


class i_pseudostate_visitor
{
public:
	i_pseudostate_visitor
	(
	) = default;


	virtual 
	~i_pseudostate_visitor
	(
	) = default;


	i_pseudostate_visitor
	(
		const i_pseudostate_visitor&
	) = delete;


	i_pseudostate_visitor&
	operator=
	(
		const i_pseudostate_visitor&
	) = delete;


	virtual void visit
	(
		const i_initial_pseudostate& p_initial_pseudostate
	) = 0;


	virtual void visit
	(
		const i_choice& p_choice
	) = 0;


	virtual void visit
	(
		const i_junction& p_junction
	) = 0;


	virtual void visit
	(
		const i_join& p_join
	) = 0;


	virtual void visit
	(
		const i_fork& p_fork
	) = 0;


	virtual void visit
	(
		const i_entry_point& p_entry_point
	) = 0;


	virtual void visit
	(
		const i_exit_point& p_exit_point
	) = 0;


	virtual void visit
	(
		const i_deep_history& p_deep_history
	) = 0;


	virtual void visit
	(
		const i_shallow_history& p_shallow_history
	) = 0;


	virtual void visit
	(
		const i_terminate_pseudostate& p_terminate_pseudostate
	) = 0;


};


}


#endif
