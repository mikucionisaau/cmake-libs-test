#include <fmt/ranges.h>

#include <array>

int main(int argc, char* argv[])
{
    const auto words = std::array{"Hello", "C++", "World!"};
    fmt::println(" Words: {}", words);
    const auto result = fmt::format("{}", words);
    const auto expect = "[\"Hello\", \"C++\", \"World!\"]";
    fmt::println("Result: {}\nExpect: {}", result, expect);
    if (result != expect) {
        fmt::println(stderr, "Test failed.");
        return 1;
    }
    fmt::println("Test passed.");
    return 0;
}
