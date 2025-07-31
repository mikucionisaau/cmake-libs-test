#include "factorial.hpp"

std::size_t factorial(std::size_t n)
{
    auto res = 1uz;
    for (auto i = 2uz; i <= n; ++i)
        res *= i;
    return res;
}

std::size_t factorial_recursive(const std::size_t n)
{
    if (n > 1)
        return n * factorial_recursive(n - 1);
    return 1;
}

std::size_t factorial_tail(const std::size_t n, const std::size_t a)
{
    if (n <= 1)
        return a;
    return factorial_tail(n - 1, n * a);
}
