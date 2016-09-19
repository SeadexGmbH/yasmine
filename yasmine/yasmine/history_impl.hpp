//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
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
	virtual ~history_impl() noexcept override = default;
	history_impl( const history_impl& ) = delete;
	history_impl& operator=( const history_impl& ) = delete;
	virtual raw_transitions get_default_transitions() const override;
	virtual void add_default_transition( transition& _default_transition ) override;
	virtual bool check_if_state_was_active_before() const override;
};


}


#endif
