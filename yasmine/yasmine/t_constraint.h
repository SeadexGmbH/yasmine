//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_CONSTRAINT_7E0FB1BA_14B2_45C4_A4E6_F13156FF5980
#define T_CONSTRAINT_7E0FB1BA_14B2_45C4_A4E6_F13156FF5980
						 

#include "i_constraint.h"


namespace sxy
{


class t_constraint: public virtual i_constraint
{
public:
	explicit t_constraint
	(
		const t_constraint_function& p_function
	);


	virtual
	~t_constraint
	(
	) override;


	t_constraint
	(
		const t_constraint&
	) = delete;


	t_constraint&
	operator=
	(
		const t_constraint&
	) = delete;


	virtual bool
	operator()
	(
		const i_event& p_event
	) const override;
	
	
	//!\brief Creates a constraint with the given function that implements the constraint.
	//!\param p_function Function that implements the constraint.
	//!\return A unique pointer to the created constraint.
	static i_constraint_uptr
	create_constraint
	(
		const t_constraint_function& p_function
	);



private:
	t_constraint_function m_function;


};


}


#endif
