#include <cstddef>

void use(int* pi, std::size_t size)
{
    for (int i = 0; i < 5; i++)
        pi[i] = 42;
}

void consume(int* pi, std::size_t size);

int main()
{
    auto pi = new int[5];
    consume(pi, 5);
    use(pi, 5);
}

void consume(int* pi, std::size_t) { delete[] pi; }
