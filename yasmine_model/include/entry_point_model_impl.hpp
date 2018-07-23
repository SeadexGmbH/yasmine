//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ENTRY_POINT_MODEL_IMPL_36B48DAE_8799_46A0_84DD_5E02A89B044F
#define ENTRY_POINT_MODEL_IMPL_36B48DAE_8799_46A0_84DD_5E02A89B044F


#include "entry_point_model.hpp"
#include "pseudostate_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class entry_point_model_impl
//!\brief An entry point pseudostate in the model.
class entry_point_model_impl SX_FINAL: 
	public entry_point_model, public pseudostate_model_impl
{
public:
	//!\brief Constructor.
	//!\param _name Name of the entry point.
	explicit entry_point_model_impl( const std::string& _name );
	virtual ~entry_point_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( entry_point_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;
};


}


}


#endif
