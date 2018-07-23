//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "json_parser_helper.hpp"

#include "model_exception.hpp"


namespace sxy
{


std::string get_object_member_string( const rapidjson::Value& _obj, const char* const _name_of_member )
{
	std::string found_value = "";
	if( _obj.IsObject() )
	{
		const rapidjson::Value& found_member = find_member( _obj, _name_of_member );
		if( found_member.IsString() )
		{
			found_value = found_member.GetString();
		}
		else
		{
			throw model::exception( "Member % is not a string type!", _name_of_member );
		}
	}

	return( found_value );
}


sxe::int64_t get_object_member_int( const rapidjson::Value& _obj, const char* const _name_of_member )
{
	sxe::int64_t found_value = 0;
	if( _obj.IsObject() )
	{
		const rapidjson::Value& found_member = find_member( _obj, _name_of_member );
		if( found_member.IsInt64() )
		{
			found_value = found_member.GetInt64();
		}
		else
		{
			throw model::exception( "Member % is not a Int64 type!", _name_of_member );
		}
	}

	return( found_value );
}


const rapidjson::Value& get_object_member_array( const rapidjson::Value& _obj, const char* const _name_of_member )
{
	const rapidjson::Value& array_object = _obj.MemberBegin()->value;
	if( _obj.IsObject() )
	{
		const rapidjson::GenericMemberIterator< true, rapidjson::UTF8< >, rapidjson::MemoryPoolAllocator< > > member
			= _obj.FindMember( _name_of_member );
		if( member != _obj.MemberEnd() )
		{
			if( member->value.IsArray() )
			{
				return( _obj.FindMember( _name_of_member )->value );
			}
			else
			{
				throw model::exception( "Member % is not an array!", _name_of_member );
			}
		}
		else
		{
			throw model::exception( "Member % was not found!", _name_of_member );
		}
	}

	return( array_object );
}


std::vector< const rapidjson::Value* > extract_members_from_array( const rapidjson::Value& _array )
{
	std::vector< const rapidjson::Value* > array_of_values;
	if( _array.IsArray() )
	{
		for( rapidjson::Value::ConstValueIterator itr = _array.Begin(); itr != _array.End(); ++itr )
		{
			array_of_values.push_back( &*itr );
		}
	}

	return( array_of_values );
}


void string_to_json( const char* const _json_as_string, rapidjson::Document& _document )
{
	_document.Parse< 0 >( _json_as_string );
}


const rapidjson::Value& find_member( const rapidjson::Value& _member, const char* const _name )
{
	if( _member.HasMember( _name ) )
	{
		if( _member.FindMember( _name ) == _member.MemberEnd() )
		{
			throw sxy::model::exception( "Member % not found!", _name );
		}
	}
	else
	{
		throw sxy::model::exception( "Member % not found!", _name );
	}

	return( _member.FindMember( _name )->value );
}


const rapidjson::Value& find_object_member( const rapidjson::Value& _document, const char* const _name )
{
	const rapidjson::Value& found_member = find_member( _document, _name );
	if( !found_member.IsObject() )
	{
		throw sxy::model::exception( "Member % is not an object!", _name );
	}

	return( found_member );
}


}
