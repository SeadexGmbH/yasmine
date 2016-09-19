//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_URI_84775A3E_75EA_4F0A_86CF_E7CF5780ACD1
#define T_URI_84775A3E_75EA_4F0A_86CF_E7CF5780ACD1


#include <deque>
#include <string>


namespace sxy
{


class t_uri final
{
public:
	explicit t_uri( const std::string& p_uri = "" );
	~t_uri();
	bool is_empty() const;
	const std::string to_string() const;
	const std::string& get_front() const;
	const std::string& get_back();
	void push_front( const std::string& p_segment );
	void push_back( const std::string& p_segment );
	void pop_front();
	void pop_back();
	size_t size() const;


private:
	const std::string build_uri() const;
	void split_string_to_uri_segments( const std::string& p_uri );


	std::deque< std::string > m_uri;
};


}


#endif
