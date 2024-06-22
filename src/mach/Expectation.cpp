#include "mach/ActualCallContext.hpp"
#include "mach/Expectation.hpp"
#include "mach/NotAllCallsOccurredError.hpp"
#include "mach/UnexpectedArgumentsError.hpp"
#include "mach/UnexpectedCallError.hpp"

using namespace mach;

Expectation::Expectation(ExpectedCall call)
  : calls{ call }
{
}

auto Expectation::and_then(Expectation expectation) -> Expectation&
{
  calls.insert(calls.end(), expectation.calls.begin(), expectation.calls.end());
  return *this;
}

auto Expectation::when(std::function<void()> f) -> void
{
  auto current_call_index = size_t{ 0 };

  auto context = ActualCallContext{ [&](ActualCall actual) -> Value {
    const auto& expected = calls[current_call_index];

    if(expected.name != actual.name) {
      throw UnexpectedCallError{ actual };
    }

    if(!expected.ignore_arguments && (expected.arguments != actual.arguments)) {
      throw UnexpectedArgumentsError{ expected, actual };
    }

    current_call_index++;

    return expected.return_value;
  } };

  f();

  if(current_call_index != calls.size()) {
    throw NotAllCallsOccurredError();
  }
}
