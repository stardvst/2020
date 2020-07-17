#include <iostream>
#include <iomanip>
#include <numbers>
#include <corecrt_math_defines.h>

int main()
{
	std::cout << std::setprecision(30) << M_PI << '\n';
	std::cout << std::setprecision(30) << std::numbers::pi << '\n'; // same as above

	// more accurate
	std::cout << std::setprecision(30) << std::numbers::pi_v<long double> << '\n';
}
