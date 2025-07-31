#include "factorial.hpp"

#include <catch2/catch_test_macros.hpp>            // TEST_CASE, SECTION, CHECK, REQUIRE
#include <catch2/generators/catch_generators.hpp>  // GENERATE
#include <catch2/benchmark/catch_benchmark.hpp>    // BENCHMARK

#include <tuple>

TEST_CASE("Factorial")
{
    SECTION("Boundary cases")
    {
        CHECK(factorial(0) == 1);
        CHECK(factorial(1) == 1);
    }
    SECTION("Non-trivial cases")
    {
        CHECK(factorial(2) == 2);
        CHECK(factorial(3) == 6);
        CHECK(factorial(6) == 720);
    }
    SECTION("Largest integer result")
    {
        auto i = 65;
        REQUIRE(i < 66);
        CHECK(factorial(i) == 9'223'372'036'854'775'808uz);
    }
}

TEST_CASE("Factorial fail demo", "[!shouldfail]") { CHECK(factorial(5) == 5); }

TEST_CASE("Factorial Alternatives")
{
    auto test_input = std::size_t{};
    auto expected_output = std::size_t{};
    std::tie(test_input, expected_output) = GENERATE(
        table<std::size_t, std::size_t>({{0, 1}, {1, 1}, {2, 2}, {3, 6}, {6, 720}, {65, 9'223'372'036'854'775'808uz}}));
    CAPTURE(test_input);
    CHECK(factorial_recursive(test_input) == expected_output);
    CHECK(factorial_tail(test_input) == expected_output);
}

TEST_CASE("Factorial Benchmarks", "[!benchmark]")
{
    BENCHMARK("factorial") { return factorial(65); };
    BENCHMARK("factorial_recursive") { return factorial_recursive(65); };
    BENCHMARK("factorial_tail") { return factorial_tail(65); };
}
