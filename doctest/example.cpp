#include "example.hpp"

std::size_t factorial(std::size_t n)
{
    auto res = 1uz;
    for (auto i = 2uz; i <= n; ++i)
        res *= i;
    return res;
}