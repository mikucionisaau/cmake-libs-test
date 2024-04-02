#include "fastsort.hpp"

#include <benchmark/benchmark.h>

static void sort_algo_bm(benchmark::State& state)
{
    const auto data = make_random_data(state.range(0));
    for (auto _ : state) {
        auto res = sort_algo(data);
        benchmark::DoNotOptimize(res.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(sort_algo_bm)->Arg(128)->Arg(8192)->Arg(524288);

static void sort_ranges_bm(benchmark::State& state)
{
    const auto data = make_random_data(state.range(0));
    for (auto _ : state) {
        auto res = sort_ranges(data);
        benchmark::DoNotOptimize(res.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(sort_ranges_bm)->Arg(128)->Arg(8192)->Arg(524288);

static void sort_libc_bm(benchmark::State& state)
{
    const auto data = make_random_data(state.range(0));
    for (auto _ : state) {
        auto res = sort_libc(data);
        benchmark::DoNotOptimize(res.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(sort_libc_bm)->Arg(128)->Arg(8192)->Arg(524288);
