//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FILE_SYSTEM_E5395B2B_BD8A_46B9_831A_B9A24E8CEDC2
#define FILE_SYSTEM_E5395B2B_BD8A_46B9_831A_B9A24E8CEDC2


#include <fstream>
#include <string>


namespace hermes
{


//!\fn get_file_size
//!\brief Get the size of the file with the given name.
//!\param _file_name Name of file for which the size is requested.
//!\return Size of the given file.
size_t get_file_size( const std::string& _file_name );

//!\fn does_file_exist
//!\brief Checks if the file with the given name exists.
//!\param _file_name Name of the file to be checked.
//!\return True if the given file exists, false otherwise.
bool does_file_exist( const std::string& _file_name );

//!\fn add_trailing_slash_to_directory_path
//!\brief Add trailing slash to the given path.
//!\param _path Path to which the trailing slash is added.
//!\return Path with trailing slash at the end.
std::string add_trailing_slash_to_directory_path( const std::string& _path );


}


#endif
