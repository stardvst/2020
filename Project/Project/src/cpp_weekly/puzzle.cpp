#include <iostream>
#include <cmath>

int main()
{
	std::cout << 1 * 0 << '\n';
	std::cout << -1 * 0 << '\n';

	// floating point math, no 
	std::cout << -1.0 * 0 << '\n';

	std::cout << (-0.0 == 0.0) << '\n'; // 1
	std::cout << (-0.0 < 0.0) << '\n'; // 0
	std::cout << (-0.0 > 0.0) << '\n'; // 0

	// can't use < to check if number is negative...
	std::cout << std::signbit(0.0) << '\n'; // 0
	std::cout << std::signbit(-0.0) << '\n'; // 1
	std::cout << std::copysign(5, -0.0) << '\n'; // -5

	// error on msvc, -inf on gcc and clang
	//std::cout << (1.0 / -0.0) << '\n';
}
