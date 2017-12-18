//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DEEP_HISTORY_MODEL_IMPL_A4563ACA_2A35_4E93_AEF0_676FBE34AEB7
#define DEEP_HISTORY_MODEL_IMPL_A4563ACA_2A35_4E93_AEF0_676FBE34AEB7


#include "deep_history_model.hpp"
#include "pseudostate_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class deep_history_model_impl
//!\brief A deep history pseudostate in the model.
class deep_history_model_impl SX_FINAL: 
	public virtual deep_history_model, public pseudostate_model_impl
{


public:
	//!\Constructor.
	//!\param _name Name of the deep history.
	explicit deep_history_model_impl( const std::string& _name );
	virtual ~deep_history_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( deep_history_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;
};


}


}


#endif
