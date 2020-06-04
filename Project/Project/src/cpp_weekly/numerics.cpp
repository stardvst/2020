#include <iostream>
#include <numeric>
#include <cmath>

int main()
{
	std::cout << std::midpoint(5, 7) << '\n';
	std::cout << (5 + 7) / 2 << '\n';

	// ok
	std::cout << std::midpoint(std::numeric_limits<int>::max(), std::numeric_limits<int>::max() - 2) << '\n';

	// signed int overflow
	std::cout << (std::numeric_limits<int>::max() + std::numeric_limits<int>::max() - 2) / 2 << '\n';

	// the linear interpolation between a and b for the parameter t
	// (or extrapolation, when t is outside the range [0, 1])
	float a = 10.0, b = 20.0, t = 0.5f;
	std::cout << "mid point = " << std::lerp(a, b, t) << '\n';
}
