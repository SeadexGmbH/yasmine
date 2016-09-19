//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_STATES_NESTING_COMPARER_ASCENDING_D08136C5_FE07_48F1_8D77_5C460EC2EFF4
#define T_STATES_NESTING_COMPARER_ASCENDING_D08136C5_FE07_48F1_8D77_5C460EC2EFF4


namespace sxy
{


class i_state;


struct t_states_nesting_comparer_ascending final
{
public:
	t_states_nesting_comparer_ascending();
	~t_states_nesting_comparer_ascending();
	bool operator()( const i_state& p_lhs, const i_state& p_rhs ) const;
	bool operator()( const i_state* const p_lhs, const i_state* const p_rhs ) const;
};

}


#endif
