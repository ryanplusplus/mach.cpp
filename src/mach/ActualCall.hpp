#ifndef ActualCall_hpp
#define ActualCall_hpp

#include <mach/Argument.hpp>
#include <string>
#include <vector>

namespace mach {
  struct ActualCall {
    ActualCall(std::string name, std::initializer_list<Argument> arguments = {})
      : name(std::move(name)), arguments(std::move(arguments))
    {
    }

    std::string name;
    std::vector<Argument> arguments;
  };
}

#endif
