//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SUBMACHINE_731C5BC9_5AEA_4C88_BD3A_770355BF17D3
#define SUBMACHINE_731C5BC9_5AEA_4C88_BD3A_770355BF17D3


#include "non_copyable.hpp"
#include "compatibility.hpp"


namespace sxy
{


	class state_machine;
	class region;
	class composite_state;


}


#ifndef Y_CPP03_BOOST
namespace examples{ class event_5; }
#else
namespace sxy { class event; }
#endif


namespace examples
{


class submachine Y_FINAL
{
public:
	submachine( sxy::state_machine& _parent_state_machine, sxy::region& _parent_region );
	~submachine() Y_NOEXCEPT;
	Y_NO_COPY( submachine )
	sxy::composite_state& get_submachine_root_state() const;


private:
	void reset_members();
	void print_members() const;	
#ifndef Y_CPP03_BOOST
	void change_members( const event_5& _event );
#else
	void change_members( const sxy::event& _event );
#endif 

	sxy::composite_state& submachine_;
	int i_;
	std::string s_;
};


}


#endif
