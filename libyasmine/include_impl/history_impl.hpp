//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
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
	virtual ~history_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(history_impl)
	virtual raw_transitions get_default_transitions() const SX_OVERRIDE;
	virtual void add_default_transition( transition& _default_transition ) SX_OVERRIDE;
	virtual bool check_if_state_was_active_before() const SX_OVERRIDE;
};


}


#endif
