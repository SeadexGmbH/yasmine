//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_STATE_VISITOR_H
#define I_STATE_VISITOR_H


namespace sxy
{


class i_composite_state;
class i_final_state;
class i_simple_state;


class i_state_visitor
{
public:
	i_state_visitor() = default;
	virtual ~i_state_visitor() = default;
	i_state_visitor( const i_state_visitor& ) = delete;
	i_state_visitor& operator=( const i_state_visitor& ) = delete;
	virtual void visit( const i_composite_state& p_composite_state ) = 0;
	virtual void visit( const i_simple_state& p_simple_state ) = 0;
	virtual void visit( const i_final_state& p_final_state ) = 0;
};


}


#endif
