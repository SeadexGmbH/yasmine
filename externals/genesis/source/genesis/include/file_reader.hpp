//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef FILE_READER_20EC6A5D_A4B2_4EDC_9B67_57B4B0A0DA31
#define FILE_READER_20EC6A5D_A4B2_4EDC_9B67_57B4B0A0DA31


#include<string>


namespace sx
{


namespace genesis
{


//!\fn
//!\brief Function that reads a file into a given string variable.
//!\param _file_path File that is read.
//!\param _content Target for the content of the file.
//!\return True if the read was successful, false otherwise.
bool read( const std::string& _file_path, std::string& _content );


}


}


#endif
