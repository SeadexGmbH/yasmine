//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_IMPL_44F1A85F_F127_46DE_811B_DD146F1AECD6
#define BEHAVIOR_IMPL_44F1A85F_F127_46DE_811B_DD146F1AECD6


#include "behavior.hpp"


namespace sxy
{


class event;


class behavior_impl SX_FINAL:
	public behavior
{
public:
	explicit behavior_impl( const behavior_function& _function );
	virtual ~behavior_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( behavior_impl )
	virtual void operator()( const event& _event, event_collector& _event_collector ) const SX_OVERRIDE;

	//!\brief Creates a behavior with the given function that implements the behavior.
	//!\param _function Function that implements the behavior.
	//!\return A unique pointer to the created behavior.
	static behavior_uptr create_behavior( const behavior_function& _function );


private:
	behavior_function function_;
};


}


#endif
