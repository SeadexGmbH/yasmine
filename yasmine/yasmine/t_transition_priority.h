//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TRANSITION_PRIORITY_FDB88A02_ECF6_4BB5_B95A_3F45813BF357
#define T_TRANSITION_PRIORITY_FDB88A02_ECF6_4BB5_B95A_3F45813BF357


#include <cstddef>


namespace sxy
{


class i_compound_transition;


class t_transition_priority final
{
public:
	explicit t_transition_priority
	(
		i_compound_transition& p_compound_transition
	);


	virtual
	~t_transition_priority
	(
	);


	std::size_t
	get_priority
	(
	) const;


	i_compound_transition&
	get_compound_transition
	(
	) const;


	bool
	operator<
	(
		const t_transition_priority& p_compare_member
	) const;


private:
	// Objects of this class have to be copied, so we cannot have a reference member.
	i_compound_transition* m_compound_transition;
	std::size_t m_priority;
};


}


#endif
