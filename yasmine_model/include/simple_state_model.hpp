//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SIMPLE_STATE_MODEL_0B93DA0E_CD9B_486A_A5FC_4DDC8375C4C4
#define SIMPLE_STATE_MODEL_0B93DA0E_CD9B_486A_A5FC_4DDC8375C4C4


#include "state_model.hpp"
#include "simple_state_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface simple_state_model
//!\brief Interface for a simple state in the model.
class simple_state_model : public virtual state_model
{
public:
	simple_state_model()
	{
		// Nothing to do...
	}


	virtual ~simple_state_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( simple_state_model )
	virtual bool has_error_event() const = 0;
	virtual event_sptr get_error_event() const = 0;
	virtual void set_error_event( event_sptr _error_event ) = 0;
	virtual bool is_async() const = 0;
	virtual void set_is_async( bool _is_async ) = 0;


};


}
}


#endif
