#include "fastsort.hpp"

#include <algorithm>
#include <random>
#include <cstdlib>

std::vector<std::size_t> make_random_data(std::size_t size)
{
    static auto gen = std::mt19937{std::random_device{}()};
    static auto dist = std::uniform_int_distribution{10uz, 1000uz};
    auto res = std::vector<std::size_t>(size);
    for (auto& n : res)
        n = dist(gen);
    return res;
}

std::vector<std::size_t> sort_algo(std::vector<std::size_t> data)
{
    std::sort(data.begin(), data.end());
    return data;
}

std::vector<std::size_t> sort_ranges(std::vector<std::size_t> data)
{
    std::ranges::sort(data);
    return data;
}

std::vector<std::size_t> sort_libc(std::vector<std::size_t> data)
{
    auto cmp = [](const void* n1, const void* n2) {
        auto* v1 = static_cast<const std::size_t*>(n1);
        auto* v2 = static_cast<const std::size_t*>(n2);
        if (*v1 < *v2)
            return -1;
        else if (*v1 > *v2)
            return 1;
        else
            return 0;
    };
    std::qsort(data.data(), data.size(), sizeof(std::size_t), +cmp);
    return data;
}
