#include <iostream>
#include <numeric>
#include <array>

template <typename Itr, typename Value>
auto myAccumulate(Itr begin, const Itr end, Value value)
{
	while (begin != end)
	{
		value += *begin;
		++begin;
	}
	return value;
}

int main()
{
	std::array values{ 1.1, 2.2, 3.3, 4.4, 5.5 };

	// prints 15, warning only with msvc
	std::cout << std::accumulate(std::begin(values), std::end(values), 0) << '\n';

	// prints 16.5, works as expected
	std::cout << std::accumulate(std::begin(values), std::end(values), 0.0) << '\n';

	// prints 15, warning only with msvc
	std::cout << myAccumulate(std::begin(values), std::end(values), 0) << '\n';

	// but this gives warning on all compilers
	int i = values[0];
}
