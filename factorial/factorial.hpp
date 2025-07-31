#ifndef LIBRARYTESTS_FACTORIAL_HPP
#define LIBRARYTESTS_FACTORIAL_HPP

#include <cinttypes>

std::size_t factorial(std::size_t n);

std::size_t factorial_recursive(std::size_t n);

std::size_t factorial_tail(std::size_t n, std::size_t a = 1);

#endif  // LIBRARYTESTS_FACTORIAL_HPP
