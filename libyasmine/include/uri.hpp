//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef URI_84775A3E_75EA_4F0A_86CF_E7CF5780ACD1
#define URI_84775A3E_75EA_4F0A_86CF_E7CF5780ACD1


#include <deque>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class uri SX_FINAL
{
public:
	explicit uri( const std::string& _uri = "" );
	~uri() SX_NOEXCEPT;
	bool is_empty() const;
	const std::string to_string() const;
	const std::string& get_front() const;
	const std::string& get_back();
	void push_front( const std::string& _segment );
	void push_back( const std::string& _segment );
	void pop_front();
	void pop_back();
	size_t size() const;


private:
	const std::string build_uri() const;
	void split_string_to_uri_segments( const std::string& _uri );


	std::deque< std::string > uri_;
};


}


#endif
