//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef INTERRUPTIBLE_32EC8385_109D_4338_BA8D_A82356BDBAF2
#define INTERRUPTIBLE_32EC8385_109D_4338_BA8D_A82356BDBAF2


#include "non_copyable.hpp"


namespace sxy
{


	class interruptible
	{
	public:
		interruptible()
		{
			// Nothing to do...
		}

		virtual ~interruptible() Y_NOEXCEPT
		{
			// Nothing to do...
		}


		Y_NO_COPY( interruptible )
		virtual bool is_interrupted() const = 0;
	};


}


#endif