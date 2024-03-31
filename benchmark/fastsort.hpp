#ifndef LIBRARYTESTS_FACTORIAL_HPP
#define LIBRARYTESTS_EXAMPLE_HPP

#include <vector>

std::vector<std::size_t> make_random_data(std::size_t size);
std::vector<std::size_t> sort_algo(std::vector<std::size_t> data);
std::vector<std::size_t> sort_ranges(std::vector<std::size_t> data);
std::vector<std::size_t> sort_libc(std::vector<std::size_t> data);

#endif  // LIBRARYTESTS_FACTORIAL_HPP
