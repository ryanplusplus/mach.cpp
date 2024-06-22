#ifndef mach_hpp
#define mach_hpp

#include <initializer_list>
#include "mach/ActualCall.hpp" // IWYU pragma: export
#include "mach/ActualCallContext.hpp" // IWYU pragma: export
#include "mach/Argument.hpp"
#include "mach/Expectation.hpp"
#include "mach/NotAllCallsOccurredError.hpp" // IWYU pragma: export
#include "mach/UnexpectedArgumentsError.hpp" // IWYU pragma: export
#include "mach/UnexpectedCallError.hpp" // IWYU pragma: export

namespace mach {
  auto expect_one_call(
    const char* name,
    std::initializer_list<Argument> arguments = {},
    Value return_value = {})
    -> Expectation;

  auto expect_one_call_with_any_arguments(
    const char* name)
    -> Expectation;

  auto actual_call(
    const char* name,
    std::initializer_list<Argument> arguments = {})
    -> Value;
}

#endif
