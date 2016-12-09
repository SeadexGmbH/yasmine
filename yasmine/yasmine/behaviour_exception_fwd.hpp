#ifndef BEHAVIOUR_EXCEPTION_FWD_FDC9BCAD_9B60_4678_97D8_C2291378BD5A
#define BEHAVIOUR_EXCEPTION_FWD_FDC9BCAD_9B60_4678_97D8_C2291378BD5A


#include <vector>

#include "compatibility.hpp"


namespace sxy
{


class behaviour_exception;


typedef Y_UNIQUE_PTR< behaviour_exception > behaviour_exception_uptr;
typedef std::vector< behaviour_exception_uptr > behaviour_exceptions;

}


#endif
