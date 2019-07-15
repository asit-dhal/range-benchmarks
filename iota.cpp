#include <benchmark/benchmark.h>

#include <range/v3/core.hpp>
#include <range/v3/numeric/iota.hpp>

#include <boost/range/algorithm_ext/iota.hpp>

#include <iostream>
#include <vector>
#include <numeric>

static void BM_std_iota(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        std::iota(v.begin(), v.end(), -10);
    }
}

static void BM_range_iota(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        ranges::iota(v, -10);
    }
}

static void BM_boost_iota(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        boost::range::iota(v, -10);
    }
}


BENCHMARK(BM_std_iota);
BENCHMARK(BM_range_iota);
BENCHMARK(BM_boost_iota);

BENCHMARK_MAIN();
