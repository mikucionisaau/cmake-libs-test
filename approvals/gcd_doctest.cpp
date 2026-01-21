#define APPROVALS_DOCTEST
#include <ApprovalTests/ApprovalTests.hpp>
#include <doctest/doctest.h>

#include <numeric>  // gcd
#include <print>

TEST_SUITE_BEGIN("gcd doctest");

TEST_CASE("gcd")
{
    const auto numbers = std::array{1, 4, 6, 8, 9, 10, 12, 14, 15};
    auto os = std::ostringstream{};
    for (auto& a : numbers)
        for (auto& b : numbers)
            std::println(os, "gcd({}, {}) = {}", a, b, std::gcd(a, b));
    ApprovalTests::Approvals::verify(os.str());
}

TEST_SUITE_END();