#include <iostream>
#include <array>

auto getData()
{
	std::array data{ 1, 2, 3 };
	return data;
}

struct S
{
	std::array<int, 3> data{ 1, 2, 3 };
	const auto &getData()
	{
		return data;
	}
};

S getS()
{
	return S();
}

int main()
{
	std::array<int, 3> data{ 1, 2, 3 };

	// loop #1
	auto total = 0;
	for (std::size_t pos = 0; const auto & v : data)
	{
		total += (v * pos);
		++pos;
	}
	std::cout << total << std::endl;

	// loop #2, safe to use returned data
	total = 0;
	for (const auto & v : getData())
		total += v;
	std::cout << total << std::endl;

	// loop #3, not safe, UB, object lifetime issues
	total = 0;
	for (const auto &v : getS().getData())
		total += v;
	std::cout << total << std::endl;

	/*
	{
		auto &&__range = getS().getData(); // dangles here

		auto __begin = std::begin(__range);
		auto __end = std::end(__range);

		for (; __begin != __end; ++__begin)
		{
			const auto &v = *__begin;

			// ... (body of range-based for loop)
		}
	}
	*/

	// loop #4, safe!
	total = 0;
	for (auto s = getS(); const auto &v : s.getData())
		total += v;
	std::cout << total << std::endl;
}
