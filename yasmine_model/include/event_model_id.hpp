//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EVENT_MODEL_ID_0A9A572D_AEA6_43BF_94B7_23F87E581966
#define EVENT_MODEL_ID_0A9A572D_AEA6_43BF_94B7_23F87E581966


#include <limits>
#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


namespace model
{


struct event_model;


//!\brief The type alias for yasmine model's event IDs.
typedef sxe::uint32_t event_id;
//!\brief The type alias for yasmine model's event ID list.
typedef std::vector< event_id > event_ids;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )

extern const event_id Y_MODEL_COMPLETION_EVENT_ID;

#else

extern const event_id Y_MODEL_COMPLETION_EVENT_ID;

#endif


typedef sxe::shared_ptr< event_model > event_sptr;


}


}


#endif
