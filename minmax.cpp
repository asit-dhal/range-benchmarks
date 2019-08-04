#include <benchmark/benchmark.h>

#include <range/v3/core.hpp>
#include <range/v3/algorithm.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/algorithm/minmax_element.hpp>

#include <iostream>
#include <vector>
#include <numeric>

static void BM_std_min(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6};
        state.ResumeTiming();

        auto itr = std::min_element(v.begin(), v.end());
    }
}

static void BM_std_max(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6};
        state.ResumeTiming();

        auto itr = std::max_element(v.begin(), v.end());
    }
}

static void BM_std_minmax(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6};
        state.ResumeTiming();

        auto itr = std::minmax_element(v.begin(), v.end());
    }
}

static void BM_range_min(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6};
        state.ResumeTiming();

        auto itr = ranges::min_element(v);
    }
}

static void BM_range_max(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6};
        state.ResumeTiming();

        auto itr = ranges::max_element(v);
    }
}

static void BM_range_minmax(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6};
        state.ResumeTiming();

        auto itr = ranges::minmax_element(v);
    }
}


static void BM_boost_min(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6};
        state.ResumeTiming();

        auto itr = boost::range::min_element(v);
    }
}

static void BM_boost_max(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6,3, 1, 4, 1, 5, 9, 2, 6};
        state.ResumeTiming();

        auto itr = boost::range::max_element(v);
    }
}


BENCHMARK(BM_std_min);
BENCHMARK(BM_std_max);
BENCHMARK(BM_std_minmax);

BENCHMARK(BM_range_min);
BENCHMARK(BM_range_max);
BENCHMARK(BM_range_minmax);

BENCHMARK(BM_boost_min);
BENCHMARK(BM_boost_max);

BENCHMARK_MAIN();
