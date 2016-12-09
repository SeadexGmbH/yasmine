//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOUR_IMPL_687393A8_48A8_4AB2_BC6B_99017F70AEAC
#define BEHAVIOUR_IMPL_687393A8_48A8_4AB2_BC6B_99017F70AEAC


#include "behaviour.hpp"


namespace sxy
{


class event;


class behaviour_impl Y_FINAL:
	public virtual behaviour
{
public:
	explicit behaviour_impl( const behaviour_function& _function );
	virtual ~behaviour_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(behaviour_impl)
	virtual void operator()( const event& _event ) const Y_OVERRIDE;

	//!\brief Creates a behaviour with the given function that implements the behaviour.
	//!\param _function Function that implements the behaviour.
	//!\return A unique pointer to the created behaviour.
	static behaviour_uptr create_behaviour( const behaviour_function& _function );


private:
	behaviour_function function_;
};


}


#endif
