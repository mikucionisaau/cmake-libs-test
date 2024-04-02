/// Tests Stack Smashing Protector
/// https://wiki.osdev.org/Stack_Smashing_Protector

#include <algorithm>
#include <array>      // size
#include <cinttypes>  // uint8_t
#include <cassert>

size_t count_unique(const uint8_t numbers[], size_t size);

static uint8_t few[128];
static uint8_t many[129];

int main()
{
    auto mod_counter = [i = 0] mutable { return (++i) % 5; };
    std::generate(few, few + std::size(few), mod_counter);
    std::generate(many, many + std::size(many), mod_counter);
    auto few_count = count_unique(few, std::size(few));
    assert(few_count == 5);
    auto many_count = count_unique(many, std::size(many));
    assert(many_count == 5);
}

std::size_t count_unique(const uint8_t numbers[], const size_t size)
{
    uint8_t values[128];
    std::copy(numbers, numbers + size, values);
    std::sort(values, values + size);
    auto end = std::unique(values, values + size);
    return std::distance(values, end);
}