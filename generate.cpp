#include <benchmark/benchmark.h>

#include <range/v3/core.hpp>
#include <range/v3/algorithm/generate.hpp>
#include <range/v3/algorithm/generate_n.hpp>

#include <boost/range/algorithm/generate.hpp>

#include <iostream>
#include <vector>
#include <algorithm>


static void BM_std_generate(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        std::generate(v.begin(), v.end(), [n = 0] () mutable { return n++; });
    }
}

static void BM_std_generate_n(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        std::generate_n(v.begin(), 5, [n = 0] () mutable { return n++; });
    }
}


static void BM_range_generate(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        ranges::generate(v, [n = 0] () mutable { return n++; });
    }
}

static void BM_range_generate_n(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        ranges::generate_n(v.begin(), 5, [n = 0] () mutable { return n++; });
    }
}

static void BM_boost_generate(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        boost::generate(v, [n = 0] () mutable { return n++; });
    }
}

BENCHMARK(BM_std_generate);
BENCHMARK(BM_range_generate);
BENCHMARK(BM_boost_generate);

BENCHMARK(BM_std_generate_n);
BENCHMARK(BM_range_generate_n);

BENCHMARK_MAIN();
