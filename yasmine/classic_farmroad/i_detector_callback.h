//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_DETECTOR_CALLBACK_0AF0AB58_4818_48B8_A10D_3894B6652355
#define I_DETECTOR_CALLBACK_0AF0AB58_4818_48B8_A10D_3894B6652355


namespace sxy
{


class i_detector_callback
{


public:
	i_detector_callback
	(
	) = default;
	
	
	virtual ~i_detector_callback
	(
	) = default;
	
	
	i_detector_callback
	(
		const i_detector_callback&
	) = delete;


	i_detector_callback&
	operator=
	(
		const i_detector_callback&
	) = delete;


	virtual void
	detector_on
	(
	) = 0;


	virtual void
	detector_off
	(
	) = 0;


};


}


#endif
