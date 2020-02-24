#include <iostream>
#include <algorithm>

template <typename First, typename ...T>
auto variadicFMin(const First &f, const T &...t)
{
	static_assert((std::is_same_v<First, T> && ...));
	First retVal = f;
	std::initializer_list<First> lst{(retVal = std::fmin(retVal, t))...};
	return *lst.begin();
	//return *std::next(lst.begin(), 1);
}

int main()
{
	std::cout << std::min(-3.0f, 2.0f) << '\n';

	std::cout << std::min(-3.0f, NAN) << '\n'; // -3
	std::cout << std::min(NAN, -3.0f) << '\n'; // NAN

	// any value that is NAN, is treated as empty placeholder value
	std::cout << std::fmin(-3.0f, NAN) << '\n'; // -3
	std::cout << std::fmin(NAN, -3.0f) << '\n'; // -3
	std::cout << std::fmin(NAN, NAN) << '\n'; // NAN

	std::cout << variadicFMin(NAN, -3.0f, NAN, 3.0f, NAN) << '\n'; // -3
}