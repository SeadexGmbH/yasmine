//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "grammar.hpp"


namespace sx
{


namespace genesis
{	


const std::string condition_modifier_NOT = "NOT";
const std::string condition_modifier_NONE = "NONE";
const char DELIMITER_CHAR = '$';
const char LINE_BREAK_CHAR = '@';		
const char OPEN_PARENTHESIS_CHAR = '(';
const char CLOSE_PARENTHESIS_CHAR = ')';
const char COMMA_CHAR = ',';
const std::string COMMA_CLOSE_PARENTHESIS = ",)";
const std::string VARIABLE_COMMAND = "$var";
const std::string LOOP_START_COMMAND = "$loop";
const std::string LOOP_END_COMMAND = "$pool";
const std::string IF_START_COMMAND = "$if";
const std::string IF_END_COMMAND = "$fi";
const std::string SWITCH_START_COMMAND = "$switch";
const std::string SWITCH_END_COMMAND = "$hctiws";
const std::string SWITCH_CASE_START_COMMAND = "$case";
const std::string SWITCH_CASE_END_COMMAND = "$esac";
const std::string SWITCH_DEFAULT_START_COMMAND = "$default";
const std::string SWITCH_DEFAULT_END_COMMAND = "$tluafed";
const int SWITCH_DEFAULT_INDEX_VALUE = -1;
const std::string TEMPLATE_COMMAND = "$template";
const char NEW_LINE_CHAR = '\n';
const std::size_t SIZE_ONE = 1;


}


}
