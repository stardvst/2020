#include <iostream>

[[nodiscard]] constexpr int add(const int lhs, const int rhs) noexcept
{
	return lhs + rhs;
}

[[nodiscard]] constexpr int mult(const int lhs, const int rhs) noexcept
{
	return lhs * rhs;
}

[[nodiscard]] constexpr auto calc(const int val1, const int val2, const int val3) noexcept
{
	return add(val1, mult(val2, val3));
}

int main()
{
}