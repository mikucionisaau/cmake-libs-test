#include <cinttypes>

void test_memory_bounds(int pi[], std::size_t index);

int main()
{
    auto mem = new int[5];
    test_memory_bounds(mem, 4);  // fine
    test_memory_bounds(mem, 5);  // heap overflow
    delete[] mem;
}

void test_memory_bounds(int pi[], std::size_t index) { pi[index] = 42; }
