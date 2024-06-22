#include "mach.hpp"
#include "mach/UnexpectedCallError.hpp"

using namespace mach;

static auto default_handler = [](ActualCall call) -> Value {
  throw UnexpectedCallError(call);
};

static std::function<Value(ActualCall)> handler = default_handler;

auto mach::expect_one_call(const char* name, std::initializer_list<Argument> arguments, Value return_value) -> Expectation
{
  return Expectation{
    ExpectedCall{ name, arguments, return_value }
  };
}

auto mach::expect_one_call_with_any_arguments(const char* name) -> Expectation
{
  return Expectation{
    ExpectedCall{ name }.with_any_arguments()
  };
}

auto mach::actual_call(const char* name, std::initializer_list<Argument> arguments) -> Value
{
  return handler(ActualCall{ name, arguments });
}

mach::ActualCallContext::ActualCallContext(std::function<Value(ActualCall)> _handler)
{
  handler = std::move(_handler);
}

mach::ActualCallContext::~ActualCallContext()
{
  handler = default_handler;
}
