/**
 * CTest does not recognize crash/abort as test failure, hence a workaround:
 * register abort handler which exits with failure.
 * Taken from: https://discourse.cmake.org/t/tests-that-are-meant-to-abort/537/4
 */
#include <cstdlib>  // std::exit
#include <csignal>  // std::signal

// This is a hack to implement death tests in CTest.
extern "C" void error_test_handle_abort(int) { std::exit(EXIT_FAILURE); }

struct test_override_abort
{
    test_override_abort() noexcept { std::signal(SIGABRT, error_test_handle_abort); }
};

auto install_abort_handler = test_override_abort{};
