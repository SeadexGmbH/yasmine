//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef JUNCTION_MODEL_IMPL_7E649570_1C3D_45B3_B282_BB8633E7177E
#define JUNCTION_MODEL_IMPL_7E649570_1C3D_45B3_B282_BB8633E7177E


#include "junction_model.hpp"
#include "pseudostate_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class junction_model_impl
//!\brief A junction pseudostate in the model.
class junction_model_impl SX_FINAL: 
	public virtual junction_model, public pseudostate_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name Name of the junction.
	explicit junction_model_impl( const std::string& _name );
	virtual ~junction_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( junction_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;
};


}


}


#endif
