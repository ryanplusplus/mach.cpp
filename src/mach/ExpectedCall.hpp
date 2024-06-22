#ifndef ExpectedCall_hpp
#define ExpectedCall_hpp

#include <string>
#include <vector>
#include "mach/Argument.hpp"
#include "mach/Value.hpp"

namespace mach {
  struct ExpectedCall {
    ExpectedCall(std::string name, std::initializer_list<Argument> arguments = {}, Value return_value = 0)
      : name{ std::move(name) }, arguments{ std::move(arguments) }, return_value{ std::move(return_value) }
    {
    }

    auto with_any_arguments() -> ExpectedCall&
    {
      this->ignore_arguments = true;
      return *this;
    }

    std::string name;
    std::vector<Argument> arguments;
    Value return_value;
    bool ignore_arguments = false;
  };
}

#endif
