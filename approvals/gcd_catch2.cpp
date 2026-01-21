#define APPROVALS_CATCH2_V3
#include <ApprovalTests/ApprovalTests.hpp>
#include <catch2/catch_test_macros.hpp>

#include <numeric>  // gcd
#include <format>

TEST_CASE("gcd")
{
    const auto numbers = std::array{1, 4, 6, 8, 9, 10, 12, 14, 15};
    auto os = std::ostringstream{};
    for (auto& a : numbers)
        for (auto& b : numbers)
            std::println(os, "gcd({}, {}) = {}", a, b, std::gcd(a, b));
    ApprovalTests::Approvals::verify(os.str());
}
