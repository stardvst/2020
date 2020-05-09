#include <iostream>
#include <algorithm>

// many algorithms have become constexpr in c++20!

// works in gcc trunk for now
constexpr auto sort(auto data)
{
	std::sort(begin(data), end(data));
	return data;
}

int main()
{
	constexpr auto sortedData = sort(std::array{ 34, 21, 13, 1, 9 });
	static_assert(std::is_sorted(begin(sortedData), end(sortedData)));
	std::cout << sortedData[0] << '\n';
}
