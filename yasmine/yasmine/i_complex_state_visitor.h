//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_COMPLEX_STATE_VISITOR_H
#define I_COMPLEX_STATE_VISITOR_H


namespace sxy
{


class i_composite_state;
class i_simple_state;


class i_complex_state_visitor
{
public:
	i_complex_state_visitor() = default;
	virtual ~i_complex_state_visitor() = default;
	i_complex_state_visitor( const i_complex_state_visitor& ) = delete;
	i_complex_state_visitor& operator=( const i_complex_state_visitor& ) = delete;
	virtual void visit( const i_composite_state& p_composite_state ) = 0;
	virtual void visit( const i_simple_state& p_simple_state ) = 0;
};


}


#endif
