//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_EXCEPTION_626C2339_34D7_4BC1_A01A_DB4C0914AA6C
#define BEHAVIOR_EXCEPTION_626C2339_34D7_4BC1_A01A_DB4C0914AA6C


#include "essentials/exception.hpp"
#include "essentials/non_copyable.hpp"

#include "event_fwd.hpp"
#include "event_id.hpp"
#include "behavior_exception_fwd.hpp"


namespace sxy
{


class behavior_exception SX_FINAL:
	public sxe::exception
{


public:
	explicit behavior_exception( const event_sptr& _event );
	virtual ~behavior_exception() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_ASSIGNMENT_OPERATOR( behavior_exception )
	const event_sptr get_error_event() const;


private:
	const event_sptr error_event_;
};


}


#endif
