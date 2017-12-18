////////////////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                                  //
//// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
//// Copyright (C) 2016-2017 Seadex GmbH                                                              //
////                                                                                                  //
//// Licensing information is available in the folder "license" which is part of this distribution.   //
//// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
////                                                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DELETE_VISITOR_3A02D550_C734_420C_B0D0_8720A701212B
#define DELETE_VISITOR_3A02D550_C734_420C_B0D0_8720A701212B

#include "essentials/non_copyable.hpp"


namespace sxy
{


namespace model
{


class simple_state_model;
class composite_state_model;
class final_state_model;
class initial_pseudostate_model_impl;
class terminate_pseudostate_model_impl;
class join_model_impl;
class fork_model_impl;
class choice_model_impl;
class junction_model_impl;
class entry_point_model_impl;
class exit_point_model_impl;
class shallow_history_model_impl;
class deep_history_model_impl;
class transition_model;
class region_model;
class state_model;
class pseudostate_model_impl;


class delete_visitor SX_FINAL
{
public:
	explicit delete_visitor();
	~delete_visitor() SX_NOEXCEPT;
	SX_NO_COPY( delete_visitor )
	void visit( simple_state_model& _simple_state );
	void visit( composite_state_model& _composite_state );
	void visit( final_state_model& _final_state );
	void visit( initial_pseudostate_model_impl& _initial_pseudostate );
	void visit( terminate_pseudostate_model_impl& _terminate_pseudostate );
	void visit( join_model_impl& _join );
	void visit( fork_model_impl& _fork );
	void visit( choice_model_impl& _choice );
	void visit( junction_model_impl& _junction );
	void visit( entry_point_model_impl& _entry_point );
	void visit( exit_point_model_impl& _exit_point );
	void visit( shallow_history_model_impl& _shallow_history );
	void visit( deep_history_model_impl& _deep_history );
	void visit( transition_model& _transition );
	void visit( region_model& _region );


private:
	void delete_state( state_model* _state );
	void delete_pseudostate( pseudostate_model_impl* _pseudostate );
	void delete_state_pseudostate( pseudostate_model_impl* _state_pseudostate );
};


}


}


#endif
