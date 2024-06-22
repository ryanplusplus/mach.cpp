#ifndef UnexpectedArgumentsError_hpp
#define UnexpectedArgumentsError_hpp

#include <exception>
#include "mach/ActualCall.hpp"
#include "mach/ExpectedCall.hpp"

namespace mach {
  class UnexpectedArgumentsError : public std::exception {
   public:
    UnexpectedArgumentsError(ExpectedCall expected, ActualCall actual)
      : expected(expected), actual(actual)
    {
    }

   public:
    ExpectedCall expected;
    ActualCall actual;
  };
}

#endif
