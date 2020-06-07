#include <list>
#include <vector>
#include <memory_resource>

static void List(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::list<int> lst{ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 } };
	}
}
BENCHMARK(List);

static void PMRList(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::byte stackBuf[2048];
		std::pmr::monotonic_buffer_resource rsrc(stackBuf, sizeof stackBuf);
		std::pmr::list<int> lst{ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }, &rsrc };
	}
}
BENCHMARK(PMRList);

static void Vector(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::vector<int> vec{ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 } };
	}
}
BENCHMARK(Vector);

static void PMRVector(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::byte stackBuf[2048];
		std::pmr::monotonic_buffer_resource rsrc(stackBuf, sizeof stackBuf);
		std::pmr::vector<int> vec{ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }, &rsrc };
	}
}
BENCHMARK(PMRVector);
