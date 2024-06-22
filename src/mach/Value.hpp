#ifndef Value_hpp
#define Value_hpp

#include <string>
#include <variant>

namespace mach {
  // fixme can this use std::any?
  using Value = std::variant<int, std::string>;
}

#endif
