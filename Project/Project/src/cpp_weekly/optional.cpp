#include <iostream>
#include <optional>
#include <variant>

constexpr std::optional<int> getValue1()
{
	// operator= is constexpr => can be called from function
	std::optional<int> val = 1;
	val = 3;
	return val;
}

constexpr std::variant<int, double> getValue2()
{
	std::variant<int, double> val = 1;
	// val = 3; // no operator=(T &&) is constexpr
	return val;
}

int main()
{
	constexpr auto val1 = getValue1();
	std::cout << *val1 << '\n';

	constexpr auto val2 = getValue2();
	std::cout << std::get<int>(val2) << '\n';
}
