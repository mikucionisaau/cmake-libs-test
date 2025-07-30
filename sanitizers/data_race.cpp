#include <functional>
#include <thread>

void work1(int& value) { value = 7; }

void work2(int& value) { value = 13; }

int main()
{
    auto shared = 0;
    auto t1 = std::jthread{work1, std::ref(shared)};
    auto t2 = std::jthread{work1, std::ref(shared)};
}
