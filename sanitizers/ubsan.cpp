#include <limits>

void test_int_overflow(int& number);

int main()
{
    auto number = std::numeric_limits<int>::max() - 3;
    test_int_overflow(number);
}

void test_int_overflow(int& number) { number += 10; }
