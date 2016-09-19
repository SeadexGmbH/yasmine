//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_BEHAVIOR_86504172_8E66_4DF4_945F_A76FC04D3BEF
#define T_BEHAVIOR_86504172_8E66_4DF4_945F_A76FC04D3BEF


#include "i_behavior.h"


namespace sxy
{


class i_event;


class t_behavior: public virtual i_behavior
{
public:
	explicit t_behavior
	(
		const t_behavior_function& p_function
	);


	virtual
	~t_behavior
	(
	) override;


	t_behavior
	(
		const t_behavior&
	) = delete;


	t_behavior&
	operator=
	(
		const t_behavior&
	) = delete;


	virtual void
	operator()
	(
		const i_event& p_event
	) const override;

		
	//!\brief Creates a behavior with the given function that implements the behavior.
	//!\param p_function Function that implements the behavior.
	//!\return A unique pointer to the created behavior.
	static i_behavior_uptr
	create_behavior
	(
		const t_behavior_function& p_function
	);


private:
	t_behavior_function m_function;


};


}


#endif
