//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef URI_72CBB6C3_57D9_443A_99F0_9EDE9A2BC07D
#define URI_72CBB6C3_57D9_443A_99F0_9EDE9A2BC07D


#include <deque>

#include "essentials/compatibility/compatibility.hpp"


namespace sxe
{


const char URI_DELIMITER = '/';


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
