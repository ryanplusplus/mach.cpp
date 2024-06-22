#ifndef Expectation_hpp
#define Expectation_hpp

#include <functional>
#include "mach/ExpectedCall.hpp"

namespace mach {
  class Expectation {
   public:
    Expectation(ExpectedCall call);
    auto and_then(Expectation expectation) -> Expectation&;
    auto when(std::function<void()> f) -> void;

   public:
    std::vector<ExpectedCall> calls;
  };
}

#endif
