#include <benchmark/benchmark.h>

#include <range/v3/core.hpp>
#include <range/v3/algorithm/fill.hpp>
#include <range/v3/algorithm/fill_n.hpp>

#ifdef BoostDefined
#include <boost/range/algorithm/fill.hpp>
#include <boost/range/algorithm/fill_n.hpp>
#endif

#include <vector>
#include <algorithm>
#include <iterator>


static void BM_std_fill(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        std::fill(std::begin(v), std::end(v), -1);
    }
}

static void BM_std_fill_n(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        std::fill_n(std::begin(v), 5, -1);
    }
}

static void BM_range_fill(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        ranges::fill(v, -1);
    }
}

static void BM_range_fill_n(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        ranges::fill_n(v.begin(), 5, -1);
    }
}

#ifdef BoostDefined
static void BM_boost_fill(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        boost::range::fill(v, -1);
    }
}

static void BM_boost_fill_n(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> v(10);
        state.ResumeTiming();

        boost::range::fill_n(v, 5, -1);
    }
}
#endif

BENCHMARK(BM_std_fill);
BENCHMARK(BM_std_fill_n);
BENCHMARK(BM_range_fill);
BENCHMARK(BM_range_fill_n);
#ifdef BoostDefined
BENCHMARK(BM_boost_fill);
BENCHMARK(BM_boost_fill_n);
#endif


BENCHMARK_MAIN();
