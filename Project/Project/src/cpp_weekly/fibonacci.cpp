#include <iostream>
#include <array>
#include <utility>
#include <cmath>

int fib_recursive(const int n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return fib_recursive(n - 1) + fib_recursive(n - 2);
}

//////////////////////////////////////////////////////////////////////////

template <int N>
struct Fib
{
	static const int val = Fib<N - 1>::val + Fib<N - 2>::val;
};

template <>
struct Fib<0>
{
	static const int val = 0;
};

template <>
struct Fib<1>
{
	static const int val = 1;
};

//////////////////////////////////////////////////////////////////////////

template <size_t ...N>
int fibImpl(std::index_sequence<N...>, const int n)
{
	constexpr std::array<int, sizeof ...(N)> arr = { Fib<N>::val... };
	return arr[n];
}

int fibFaster(const int n)
{
	return fibImpl(std::make_index_sequence<47>(), n);
}

//////////////////////////////////////////////////////////////////////////

int fibBinet(const int n)
{
	static const auto sqrt_5 = std::sqrt(5);

	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return static_cast<int>((
		std::pow(1 + sqrt_5, n) - std::pow(1 - sqrt_5, n)) /
		(std::pow(2, n) + sqrt_5));
}

int main(int argc, const char *[])
{
	// slow, bigger executable
	// std::cout << fib_recursive(50) << '\n';

	// faster, smaller executable
	std::cout << Fib<45>::val << '\n';
	//std::cout << Fib<argc>::val << '\n'; // must be compile-time expression

	std::cout << fibFaster(45) << '\n';
}