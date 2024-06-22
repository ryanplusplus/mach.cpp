#ifndef Argument_hpp
#define Argument_hpp

#include <string>
#include <variant>
#include "mach/Value.hpp"

namespace mach {
  struct Argument {
    auto operator==(const Argument& other) const -> bool
    {
      return (this->name == other.name) && (this->value == other.value);
    }

    std::string name;
    Value value;
  };
}

#endif
