//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOUR_EXCEPTION_2D8556FD_222C_4ABD_B11B_1AC356D1A0BB
#define BEHAVIOUR_EXCEPTION_2D8556FD_222C_4ABD_B11B_1AC356D1A0BB
		 

#include "event_fwd.hpp"
#include "event_id.hpp"
#include "exception.hpp"
#include "behaviour_exception_fwd.hpp"
#include "non_copyable.hpp"


namespace sxy
{


class behaviour_exception Y_FINAL:
	public exception
{


public:
	explicit behaviour_exception( const event_sptr& _event );
	virtual ~behaviour_exception() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY_OPERATOR_EQUAL(behaviour_exception)
	const event_sptr get_error_event() const;									


private:
	const event_sptr error_event_;
};


}


#endif
