#ifndef ExpectedCall_hpp
#define ExpectedCall_hpp

#include <string>
#include <vector>
#include "mach/Argument.hpp"
#include "mach/Value.hpp"

namespace mach {
  struct ExpectedCall {
    ExpectedCall(std::string name)
      : name{ name }
    {
    }

    auto with_arguments(std::initializer_list<Argument> arguments) -> ExpectedCall&
    {
      this->arguments = arguments;
      return *this;
    }

    auto with_any_arguments() -> ExpectedCall&
    {
      this->ignore_arguments = true;
      return *this;
    }

    auto and_will_return_value(Value value) -> ExpectedCall&
    {
      this->return_value = value;
      return *this;
    }

    std::string name;
    std::vector<Argument> arguments{};
    Value return_value = 0;
    bool ignore_arguments = false;
  };
}

#endif
