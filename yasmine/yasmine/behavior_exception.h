//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_EXCEPTION_2D8556FD_222C_4ABD_B11B_1AC356D1A0BB
#define BEHAVIOR_EXCEPTION_2D8556FD_222C_4ABD_B11B_1AC356D1A0BB
		 

#include "event_fwd.h"
#include "event_id.h"
#include "exception.h"


namespace sxy
{


class behavior_exception final:
	public exception
{


public:
	explicit behavior_exception( const event_sptr _event );
	~behavior_exception() override;	
	behavior_exception& operator=( const behavior_exception& ) = delete;
	const event_sptr get_error_event() const;									


private:
	const event_sptr error_event_;
};


}


#endif
