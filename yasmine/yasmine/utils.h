//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef UTILS_50FAC970_4B2B_46F8_91B8_16F5A7DC3D9B
#define UTILS_50FAC970_4B2B_46F8_91B8_16F5A7DC3D9B


#ifdef WIN32


#define WIN32_LEAN_AND_MEAN
#include <windows.h>


#endif


namespace sxy
{


namespace utils
{


#ifdef WIN32


// !\brief Sets the size of the console.
// !\param	p_width Number of columns in Windows console.
// !\param	p_height Number of lines in Windows console.
// !\return void
void set_window_size(	const SHORT p_width, const SHORT p_height );

// !brief Maximize the Windows console.
// !return void
void maximize_window();


#endif


}


}


#endif
