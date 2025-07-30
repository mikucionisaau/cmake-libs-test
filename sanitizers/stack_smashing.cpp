/// Tests Stack Smashing Protector
/// https://wiki.osdev.org/Stack_Smashing_Protector

#include <algorithm>
#include <array>  // size
#include <iostream>
#include <cassert>

size_t count_unique(const int* numbers, std::size_t size);

static int few[32];
static int many[35];

int main()
{
    auto mod_counter = [i = 0] mutable { return (++i) % 5; };
    std::generate(few, few + std::size(few), mod_counter);
    std::generate(many, many + std::size(many), mod_counter);
    auto few_count = count_unique(few, std::size(few));
    assert(few_count == 5);
    auto many_count = count_unique(many, std::size(many));
    std::cout << "many_count = " << many_count << std::endl;
}

std::size_t count_unique(const int* numbers, const std::size_t size)
{
    int values[32];  // not enough for `many`
    std::copy(numbers, numbers + size, values);
    std::sort(values, values + size);
    const auto end = std::unique(values, values + size);
    return std::distance(values, end);
}