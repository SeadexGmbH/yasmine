//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef Y_NO_LOGGING


#ifndef WAITER_5E57D733_02DD_413D_A906_5047979A5DFD
#define WAITER_5E57D733_02DD_413D_A906_5047979A5DFD


#include "log_callback.hpp"
#include "thread.hpp"


namespace sxy
{


	class waiter : public log_callback
	{
	public:
		waiter();
		virtual ~waiter() Y_NOEXCEPT Y_OVERRIDE;
		virtual void wait() Y_OVERRIDE;
		virtual void done() Y_OVERRIDE;
		virtual bool is_done() Y_OVERRIDE;


	private:
		sxy::mutex done_mutex_;
		sxy::condition_variable done_condition_variable_;
		bool done_;
	};

}


#endif


#endif
