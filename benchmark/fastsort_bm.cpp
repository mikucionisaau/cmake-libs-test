#include "fastsort.hpp"

#include <benchmark/benchmark.h>

static const auto data = make_random_data(1000000);

static void sort_algo_bm(benchmark::State& state)
{
    for (auto _ : state) {
        auto res = sort_algo(data);
        benchmark::DoNotOptimize(res.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(sort_algo_bm);

static void sort_ranges_bm(benchmark::State& state)
{
    for (auto _ : state) {
        auto res = sort_ranges(data);
        benchmark::DoNotOptimize(res.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(sort_ranges_bm);

static void sort_libc_bm(benchmark::State& state)
{
    for (auto _ : state) {
        auto res = sort_libc(data);
        benchmark::DoNotOptimize(res.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(sort_libc_bm);
