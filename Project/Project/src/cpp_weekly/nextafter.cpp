#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	const auto f1 = .00120230222467f;
	const auto n1 = f1;
	std::cout << std::setprecision(30) << f1 << '\n' << n1 << "\n\n";

	const auto f2 = .00120230222467f;
	const auto n2 = std::nextafter(f2, 0);
	const auto n3 = std::nextafter(f2, std::numeric_limits<decltype(f2)>::infinity());
	std::cout << std::setprecision(30) << f2 << '\n' << n2 << '\n' << n3 << "\n\n";

	const auto d4 = .00120230222467;
	const auto n4 = d4;
	std::cout << std::setprecision(30) << d4 << '\n' << n4 << '\n';
}
