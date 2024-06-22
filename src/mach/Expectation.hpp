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

    auto with_arguments(std::initializer_list<Argument> arguments) -> Expectation&
    {
      this->calls.back().with_arguments(arguments);
      return *this;
    }

    auto with_any_arguments() -> Expectation&
    {
      this->calls.back().with_any_arguments();
      return *this;
    }

    auto and_will_return_value(Value value) -> Expectation&
    {
      this->calls.back().and_will_return_value(value);
      return *this;
    }

   public:
    std::vector<ExpectedCall> calls;
  };
}

#endif
