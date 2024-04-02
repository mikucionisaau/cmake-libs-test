#ifndef LIBRARYTESTS_FASTSORT_HPP
#define LIBRARYTESTS_FASTSORT_HPP

#include <vector>

std::vector<int> make_random_data(std::size_t size);
std::vector<int> sort_algo(std::vector<int> data);
std::vector<int> sort_ranges(std::vector<int> data);
std::vector<int> sort_libc(std::vector<int> data);

#endif  // LIBRARYTESTS_FASTSORT_HPP
