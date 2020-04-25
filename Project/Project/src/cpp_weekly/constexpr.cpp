#include <iostream>
#include <type_traits>

// why is there such function?
constexpr double tan1(double angle)
{
	if /*constexpr*/ (std::is_constant_evaluated())
		// do the fast thing that doesn't rely on inline assembly
		return 5;
	else
		// do the fast thing that does use inline assembly
		return 10;
}

int main()
{
	std::cout << tan1(1) << '\n'; // 10

	constexpr auto v = tan1(1);
	std::cout << v << '\n'; // 5

	const auto s = tan1(1);
	std::cout << s << '\n'; // 5
}
