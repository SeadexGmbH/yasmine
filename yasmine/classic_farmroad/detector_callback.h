//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef DETECTOR_CALLBACK_0AF0AB58_4818_48B8_A10D_3894B6652355
#define DETECTOR_CALLBACK_0AF0AB58_4818_48B8_A10D_3894B6652355


namespace sxy
{


class detector_callback
{
public:
	detector_callback() = default;
	virtual ~detector_callback() = default;
	detector_callback( const detector_callback& ) = delete;
	detector_callback& operator=( const detector_callback& ) = delete;
	virtual void detector_on() = 0;
	virtual void detector_off() = 0;
};


}


#endif
