//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
				 
#ifndef SX_NO_LOGGING		


#ifndef COUT_LOGGER_170B8470_DB09_43CF_A547_D6C928D5121F
#define COUT_LOGGER_170B8470_DB09_43CF_A547_D6C928D5121F


#include "logger.hpp"
#include "color_mapping.hpp"


namespace hermes
{


//!\class cout_logger
//!\brief Class for printing messages in the console via cout.
class cout_logger:
	public logger
{
public:
	//!\brief Constructor
	cout_logger();
	virtual ~cout_logger() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY(cout_logger)

	//!\brief Prints the message.
	//!\param _log_message Log message that will be printed.
	//!\return void
	virtual void log( const log_message& _log_message ) SX_OVERRIDE;


private:
	void log_level_as_message( const hermes::log_level _log_level ) const;

	color_mapping color_mapping_;
};


}


#endif


#endif
