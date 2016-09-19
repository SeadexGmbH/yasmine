//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_EVENT_93C15F39_B9E1_4AB9_883A_F3405C0AF83C
#define T_EVENT_93C15F39_B9E1_4AB9_883A_F3405C0AF83C


#include <string>
#include <map>

#include "i_event.h"
#include "i_event_fwd.h"


namespace sxy
{


class t_event:
	public i_event
{
public:
	explicit t_event( const t_event_id p_event_id );
	virtual ~t_event() override;
	t_event( const t_event& ) = delete;
	t_event& operator=( const t_event& ) = delete;
	virtual t_event_id get_id() const override;
	static t_event_sptr create_event( const t_event_id p_event_id );


private:
	t_event_id m_event_id;
};


}


#endif
