#ifndef MAKE_UNIQUE_D01ABAE4_2C3D_4B46_B194_603442B16640
#define MAKE_UNIQUE_D01ABAE4_2C3D_4B46_B194_603442B16640


#include <memory>


namespace sxy {


#ifdef Y_NO_STD_MAKE_UNIQUE


template< typename t, typename ... args >
std::unique_ptr< t > make_unique( args&& ... _args ) {
    return( std::unique_ptr< t >( new t( std::forward< args >( _args )... ) ) );
}


#else


using std::make_unique;


#endif


}


#endif
