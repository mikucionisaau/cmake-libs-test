#include <numeric>
#include <cstddef>

namespace
{
void use(int* pi, std::size_t size);
}  // namespace

int main()
{
    constexpr auto size = 10;
    auto* leak = new int[size];
    use(leak, size);
}

namespace
{
void use(int* pi, std::size_t size) { std::iota(pi, pi + size, 1); }
}  // namespace
