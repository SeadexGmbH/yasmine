//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef HISTORY_IMPL_D2F99021_CF5E_4B90_8BC7_DD0E3610DE94
#define HISTORY_IMPL_D2F99021_CF5E_4B90_8BC7_DD0E3610DE94


#include "history.hpp"
#include "state_pseudostate_impl.hpp"


namespace sxy
{


class history_impl:
	public virtual history, public state_pseudostate_impl
{
public:
	explicit history_impl( const std::string& _name );
	virtual ~history_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(history_impl)
	virtual raw_transitions get_default_transitions() const Y_OVERRIDE;
	virtual void add_default_transition( transition& _default_transition ) Y_OVERRIDE;
	virtual bool check_if_state_was_active_before() const Y_OVERRIDE;
};


}


#endif
