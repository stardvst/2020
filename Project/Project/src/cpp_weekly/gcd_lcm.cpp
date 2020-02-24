#include <iostream>
#include <numeric>

int main()
{
	// they're constexpr
	constexpr auto gcd = std::gcd(640, 480);
	std::cout << gcd << '\n';
	std::cout << std::lcm(14, 21) << '\n';
}