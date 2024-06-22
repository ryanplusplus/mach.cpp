#ifndef Value_hpp
#define Value_hpp

#include <string>
#include <variant>

namespace mach {
  using Value = std::variant<int, std::string>;
}

#endif
