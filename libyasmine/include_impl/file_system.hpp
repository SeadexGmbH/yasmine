//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FILE_SYSTEM_E5395B2B_BD8A_46B9_831A_B9A24E8CEDC2
#define FILE_SYSTEM_E5395B2B_BD8A_46B9_831A_B9A24E8CEDC2


#include <fstream>
#include <string>


namespace sxy
{


size_t get_file_size( const std::string& _file_name );
bool does_file_exist( const std::string& _file_name );
std::string add_trailing_slash_to_directory_path( const std::string& _path );


}


#endif
