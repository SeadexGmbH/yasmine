//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_LOGGER_4207DA98_D8C1_41B4_B5B1_29E8C5A22DF3
#define I_LOGGER_4207DA98_D8C1_41B4_B5B1_29E8C5A22DF3


#include "i_logger_fwd.h"
#include "t_log_message.h"


namespace sxy
{

//!\interface i_logger
//!\brief Interface of the general logger. The specialized loggers derive from this interface.
class i_logger
{
public:
	//!\brief i_logger constructor.
	i_logger
	(
	) = default;
	
	
	virtual ~i_logger
	(
	) = default;


	i_logger
	(
		const i_logger&
	) = delete;


	i_logger&
	operator=
	(
		const i_logger&
	) = delete;


	//!\brief Log the message to the target medium.
	//!\param p_log_message Message to be logged.
	//!\return void
	virtual void
	log
	(
		const t_log_message& p_log_message
	) = 0;


};


}


#endif
