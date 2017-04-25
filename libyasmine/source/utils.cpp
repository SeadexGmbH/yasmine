//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "utils.hpp"


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
void set_window_size(	const SHORT _width, const SHORT _height )
{
	COORD coord;
	coord.X = _width;
	coord.Y = MAX_ROWS;
	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Right = _width - 1;
	rect.Bottom = _height - 1;
	const HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleScreenBufferSize( handle, coord );
	SetConsoleWindowInfo( handle, TRUE, &rect );
}


// cppcheck-suppress unusedFunction
void maximize_window()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &info );
	SMALL_RECT rect;
	rect.Left = 0;
	rect.Top = 0;
	rect.Right = min( info.dwMaximumWindowSize.X, info.dwSize.X ) - 1;
	rect.Bottom = min( info.dwMaximumWindowSize.Y, info.dwSize.Y ) - 1;
	SetConsoleWindowInfo( GetStdHandle( STD_OUTPUT_HANDLE ), true, &rect );
}


#endif


}


}
