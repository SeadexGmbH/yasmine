//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef WAITER_5E57D733_02DD_413D_A906_5047979A5DFD
#define WAITER_5E57D733_02DD_413D_A906_5047979A5DFD

#include "hermes_backward_compatibility.hpp"


#ifndef SX_NO_LOGGING


#include "log_callback.hpp"
#include "essentials/compatibility/thread.hpp"


namespace hermes
{

	//!\class waiter
	//!\brief Class that implements the log callback and gives the logger the ability to wait for a message to be printed. This useful when
	//!when we have to be sure writing a log message has definitely finished (e.g. before triggering an assert).
	class waiter : public log_callback
	{
	public:
		//!\brief Constructor
		waiter();
		virtual ~waiter() SX_NOEXCEPT SX_OVERRIDE;
		
		//!\brief Wait for the process to finish.
		virtual void wait() SX_OVERRIDE;

		//!\brief The thing we are waiting for is done.
		virtual void done() SX_OVERRIDE;

		//!\brief Check if the thing we are waiting for is done.
		//!\return True if it's done, false otherwise.
		virtual bool is_done() SX_OVERRIDE;


	private:
		sxe::mutex done_mutex_;
		sxe::condition_variable done_condition_variable_;
		bool done_;
	};

}


#endif


#endif
