//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SUBMACHINE_731C5BC9_5AEA_4C88_BD3A_770355BF17D3
#define SUBMACHINE_731C5BC9_5AEA_4C88_BD3A_770355BF17D3


#include "essentials/non_copyable.hpp"
#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


	class sync_state_machine;
	class region;
	class composite_state;


}


namespace examples{ class event_5; }


namespace examples
{


class submachine SX_FINAL
{
public:
	submachine( sxy::sync_state_machine& _parent_state_machine, sxy::region& _parent_region );
	~submachine() SX_NOEXCEPT;
	SX_NO_COPY( submachine )
	sxy::composite_state& get_submachine_root_state() const;


private:
	void reset_members();
	void print_members() const;
	void change_members( const event_5& _event );


	sxy::composite_state& submachine_;
	int i_;
	std::string s_;
};


}


#endif
