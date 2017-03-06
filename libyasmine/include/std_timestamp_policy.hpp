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

#ifndef STD_TIMESTAMP_POLICY_A0D64C16_D7D3_4E06_B647_F949D14BBBAB
#define STD_TIMESTAMP_POLICY_A0D64C16_D7D3_4E06_B647_F949D14BBBAB


#include <string>

#include "non_copyable.hpp"


namespace sxy
{


class std_timestamp_policy Y_FINAL
{
public:
	Y_NO_COPY(std_timestamp_policy)	
	static std::string get_timestamp();
};


}


#endif

#endif
