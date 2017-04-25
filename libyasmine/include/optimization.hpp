//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef OPTIMIZATION_3A290AFB_D672_4E4A_98AD_94841A01D76D
#define OPTIMIZATION_3A290AFB_D672_4E4A_98AD_94841A01D76D


#ifdef Y_OPTIMIZE_4_SPEED


	#ifdef Y_OPTIMIZE_4_SIZE

		
		#error "Y_OPTIMIZE_4_SPEED and Y_OPTIMIZE_4_SIZE are both defined!"
		


	#endif


#else


	#ifndef Y_OPTIMIZE_4_SIZE


		#define Y_OPTIMIZE_4_SIZE


	#endif


#endif


#endif
