#ifndef BEHAVIOR_EXCEPTION_FWD_FDC9BCAD_9B60_4678_97D8_C2291378BD5A
#define BEHAVIOR_EXCEPTION_FWD_FDC9BCAD_9B60_4678_97D8_C2291378BD5A


#include <memory>
#include <vector>


namespace sxy
{


class behavior_exception;


using behavior_exception_uptr = std::unique_ptr< behavior_exception >;
using behavior_exceptions = std::vector< behavior_exception_uptr >;

}


#endif
