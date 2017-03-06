//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_VISITOR_74B7FD7D_C18E_4F6E_B278_00268B0CFCD7
#define STATE_VISITOR_74B7FD7D_C18E_4F6E_B278_00268B0CFCD7


namespace sxy
{


class composite_state;
class final_state;
class simple_state;


class state_visitor
{
public:
	state_visitor()
	{
		// Nothing to do...
	}


	virtual ~state_visitor() Y_NOEXCEPT
	{
		// Nothing to do...
	}


	Y_NO_COPY(state_visitor)
	virtual void visit( const composite_state& _composite_state ) = 0;
	virtual void visit( const simple_state& _simple_state ) = 0;
	virtual void visit( const final_state& _final_state ) = 0;
};


}


#endif
