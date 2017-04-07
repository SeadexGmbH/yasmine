//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING


#ifndef STD_TIMESTAMP_POLICY_A0D64C16_D7D3_4E06_B647_F949D14BBBAB
#define STD_TIMESTAMP_POLICY_A0D64C16_D7D3_4E06_B647_F949D14BBBAB


#include <string>

#include "essentials/non_copyable.hpp"


namespace hermes
{

//!\class std_timestamp_policy
//!\brief Provides time stamps for the logger.
class std_timestamp_policy SX_FINAL
{
public:
	SX_NO_COPY(std_timestamp_policy)

	//!\ Provides time stamp as string.
	//!\return Time stamp as string.
	static std::string get_timestamp();
};


}


#endif


#endif
