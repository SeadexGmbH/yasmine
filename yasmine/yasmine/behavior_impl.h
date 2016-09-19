//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_IMPL_687393A8_48A8_4AB2_BC6B_99017F70AEAC
#define BEHAVIOR_IMPL_687393A8_48A8_4AB2_BC6B_99017F70AEAC


#include "behavior.h"


namespace sxy
{


class event;


class behavior_impl final:
	public virtual behavior
{
public:
	explicit behavior_impl( const behavior_function& _function );
	virtual ~behavior_impl() override;
	behavior_impl( const behavior_impl& ) = delete;
	behavior_impl& operator=( const behavior_impl& ) = delete;
	virtual void operator()( const event& _event ) const override;

	// !\brief Creates a behavior with the given function that implements the behavior.
	// !\param _function Function that implements the behavior.
	// !\return A unique pointer to the created behavior.
	static behavior_uptr create_behavior( const behavior_function& _function );


private:
	behavior_function function_;
};


}


#endif
