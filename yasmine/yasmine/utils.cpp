//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "utils.h"


namespace sxy
{


namespace utils
{


namespace
{


#ifdef WIN32
const SHORT MAX_ROWS = 9999;
#endif


}


#ifdef WIN32

// cppcheck-suppress unusedFunction
void set_window_size(	const SHORT p_width, const SHORT p_height )
{
	COORD coord;
	coord.X = p_width;
	coord.Y = MAX_ROWS;
	SMALL_RECT l_rect;
	l_rect.Top = 0;
	l_rect.Left = 0;
	l_rect.Right = p_width - 1;
	l_rect.Bottom = p_height - 1;
	const HANDLE l_handle = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleScreenBufferSize( l_handle, coord );
	SetConsoleWindowInfo( l_handle, TRUE, &l_rect );
}


// cppcheck-suppress unusedFunction
void maximize_window()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &info );
	SMALL_RECT l_rect;
	l_rect.Left = 0;
	l_rect.Top = 0;
	l_rect.Right = min( info.dwMaximumWindowSize.X, info.dwSize.X ) - 1;
	l_rect.Bottom = min( info.dwMaximumWindowSize.Y, info.dwSize.Y ) - 1;
	SetConsoleWindowInfo( GetStdHandle( STD_OUTPUT_HANDLE ), true, &l_rect );
}


#endif


}


}
