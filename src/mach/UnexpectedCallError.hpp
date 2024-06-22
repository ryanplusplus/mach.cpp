#ifndef UnexpectedCallError_hpp
#define UnexpectedCallError_hpp

#include <exception>
#include "mach/ActualCall.hpp"

namespace mach {
  class UnexpectedCallError : public std::exception {
   public:
    UnexpectedCallError(ActualCall call)
      : call(call)
    {
    }

   public:
    ActualCall call;
  };
}

#endif
