#include <numeric>
#include <cinttypes>

void test_memory_leak(int pi[], std::size_t size);

int main()
{
    constexpr auto size = 10;
    auto leak = new int[size];
    test_memory_leak(leak, size);
}

void test_memory_leak(int pi[], std::size_t size) { std::iota(pi, pi + size, 1); }
