//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COUT_LOGGER_170B8470_DB09_43CF_A547_D6C928D5121F
#define COUT_LOGGER_170B8470_DB09_43CF_A547_D6C928D5121F


#include "logger.h"


namespace sxy
{


// !\class cout_logger
// !\brief Class for printing messages in the console.
class cout_logger:
	public logger
{
public:
	// !\brief Constructor of cout_logger.
	cout_logger();
	virtual ~cout_logger() override = default;
	cout_logger( const cout_logger& ) = delete;
	cout_logger& operator=( const cout_logger& ) = delete;

	// !\brief Prints the message in the console.
	// !\param _log_message Log message that will be printed.
	// !\return void.
	virtual void log( const log_message& _log_message ) override;


private:
	static void log_level_as_message( const sxy::log_level _log_level );
};


}


#endif
