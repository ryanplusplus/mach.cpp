#ifndef ActualCallContext_hpp
#define ActualCallContext_hpp

#include <functional>
#include "mach/ActualCall.hpp"
#include "mach/Value.hpp"

namespace mach {
  class ActualCallContext {
   public:
    ActualCallContext(std::function<Value(ActualCall)> handler);
    ~ActualCallContext();
  };
}

#endif
