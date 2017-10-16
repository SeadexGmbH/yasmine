//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef JSON_PARSER_HELPER_A98B95E7_1604_4778_92B0_A3C11BF6EF82
#define JSON_PARSER_HELPER_A98B95E7_1604_4778_92B0_A3C11BF6EF82


#include <vector>

#include <document.h>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


std::string get_object_member_string( const rapidjson::Value& _obj, const char* const _name_of_member );
sxe::int64_t get_object_member_int( const rapidjson::Value& _obj, const char* const _name_of_member );
const rapidjson::Value& get_object_member_array( const rapidjson::Value& _obj, const char* const _name_of_member );
std::vector< const rapidjson::Value* > extract_members_from_array( const rapidjson::Value& _array );
void string_to_json( const char* const _json_as_string, rapidjson::Document& _document );
const rapidjson::Value& find_member( const rapidjson::Value& _member, const char* const _name );
const rapidjson::Value& find_object_member( const rapidjson::Value& _document, const char* const _name );


}


#endif
