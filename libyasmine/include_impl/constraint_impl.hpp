//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CONSTRAINT_IMPL_A7A39030_C6D6_49D6_A051_B151370B7147
#define CONSTRAINT_IMPL_A7A39030_C6D6_49D6_A051_B151370B7147


#include "constraint.hpp"


namespace sxy
{


class constraint_impl Y_FINAL:
	public virtual constraint
{
public:
	explicit constraint_impl( const constraint_function& _function );
	virtual ~constraint_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(constraint_impl)
	virtual bool operator()( const event& _event, event_collector& _event_collector ) const Y_OVERRIDE;

	//!\brief Creates a constraint with the given function that implements the constraint.
	//!\param _function Function that implements the constraint.
	//!\return A unique pointer to the created constraint.
	static constraint_uptr create( const constraint_function& _function );


private:
	constraint_function function_;
};


}


#endif
