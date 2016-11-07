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


#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif 
													 
#include <windows.h>


#endif


namespace sxy
{


namespace utils
{


#ifdef WIN32


//!\brief Sets the size of the console.
//!\param	_width Number of columns in Windows console.
//!\param	_height Number of lines in Windows console.
//!\return void
void set_window_size(	const SHORT _width, const SHORT _height );

//!\brief Maximize the Windows console.
//!\return void
void maximize_window();


#endif


}


}


#endif
