#include <iostream>
#include <algorithm>

int myMin(int x, int y, int z)
{
	return std::min(std::min(x, y), z);
}

int myMin2(int x, int y, int z)
{
	// not efficient, construct temporary initializer list...
	return std::min({ x, y, z });;
}

// this is as efficient as myMin
template <typename First, typename ...T>
decltype(auto) variadicMin(const First &f, const T &...t)
{
	static_assert((std::is_same_v<First, T> && ...));
	const First *retVal = &f;
	((retVal = std::addressof(std::min(*retVal, t))), ...);
	return *retVal;
}

int main()
{
	std::cout << myMin(4, 5, 1) << '\n';
	std::cout << myMin2(4, 5, 1) << '\n';
	std::cout << variadicMin(4, 5, 7, 1) << '\n';
	// std::cout << variadicMin(4, 5, 7, 1u) << '\n'; // static assertion failed
}