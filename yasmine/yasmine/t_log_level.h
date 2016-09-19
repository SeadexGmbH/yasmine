//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_LOG_LEVEL_5059A1FA_DC2D_4C94_AA8B_49B750B30F07
#define T_LOG_LEVEL_5059A1FA_DC2D_4C94_AA8B_49B750B30F07


#include <string>


namespace sxy
{


// !\brief Enum class for log levels.
enum class t_log_level
{
	LL_ASSERT = 0, LL_FATAL = 1, LL_ERROR = 2, LL_WARN = 3, LL_INFO = 4, LL_DEBUG = 5, LL_TRACE = 6, LL_SPAM = 7,
	LL_PROTOCOL = 8
};


// !\brief Convert the given log level to a string.
// !\param p_log_level - The log level.
// !\return The log level as string.
std::string log_level_to_string( const t_log_level p_log_level );	


}


#endif
