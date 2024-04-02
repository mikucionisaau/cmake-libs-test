#include "fastsort.hpp"

#include <algorithm>
#include <random>
#include <cstdlib>

std::vector<int> make_random_data(std::size_t size)
{
    static auto gen = std::mt19937{std::random_device{}()};
    static auto dist = std::uniform_int_distribution{-1000, 1000};
    auto res = std::vector<int>(size);
    for (auto& n : res)
        n = dist(gen);
    return res;
}

std::vector<int> sort_algo(std::vector<int> data)
{
    std::sort(data.begin(), data.end());
    return data;
}

std::vector<int> sort_ranges(std::vector<int> data)
{
    std::ranges::sort(data);
    return data;
}

std::vector<int> sort_libc(std::vector<int> data)
{
    auto cmp = [](const void* n1, const void* n2) {
        const int v1 = *static_cast<const int*>(n1);
        const int v2 = *static_cast<const int*>(n2);
        if (v1 < v2)
            return -1;
        if (v1 > v2)
            return 1;
        return 0;
    };
    std::qsort(data.data(), data.size(), sizeof(int), cmp);
    return data;
}
