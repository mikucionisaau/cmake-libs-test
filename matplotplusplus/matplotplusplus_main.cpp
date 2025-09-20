#include <matplot/matplot.h>

int main()
{
    namespace plt = matplot;
    auto t = plt::linspace(0, 2 * plt::pi);
    auto x = plt::transform(t, [](auto x) { return sin(x); });

    plt::plot(t, x, "-o");
    plt::hold(plt::on);
    plt::plot(t, plt::transform(x, [](auto t) { return -t; }), "--xr");
    plt::plot(t, plt::transform(t, [](auto t) { return t / plt::pi - 1.; }), "-:gs");
    plt::plot({1.0, 0.7, 0.4, 0.0, -0.4, -0.7, -1}, "k");

    plt::show();
}
