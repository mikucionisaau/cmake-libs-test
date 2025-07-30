#include <iostream>

int get_value();

static auto done1 = false;
void task1()
{
    int res = get_value();
    if (res == 42)
        done1 = true;
}

static auto done2 = false;
void task2()
{
    int res;  // uninitialized, usually inherits previous stack values
    if (res == 42)
        done2 = true;
}

int main()
{
    task1();
    task2();
    std::cout << "PASS.\n";
    return 0;
}

int get_value() { return 42; }
