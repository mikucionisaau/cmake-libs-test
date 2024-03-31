#include "example.hpp"

#include <doctest/doctest.h>

TEST_CASE("Factorial function example")
{
    SUBCASE("Boundary cases")
    {
        CHECK(factorial(0) == 1);
        CHECK(factorial(1) == 1);
    }
    SUBCASE("Non-trivial cases")
    {
        CHECK(factorial(2) == 2);
        CHECK(factorial(3) == 6);
        CHECK(factorial(6) == 720);
    }
    SUBCASE("Largest integer result")
    {
        auto i = 65;
        REQUIRE(i < 66);
        CHECK(factorial(i) == 9'223'372'036'854'775'808uz);
    }
}