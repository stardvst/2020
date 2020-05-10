#include <iostream>
#include <iomanip>

// example 1
template <typename T>
constexpr T pi = T(3.1415926535897932385L);

// example 2
constexpr auto get()
{
	return 42.4;
}

template <typename T>
constexpr T value = T(get());

// example 4, specilization
template <int Value>
constexpr auto fib = fib<Value - 1> +fib<Value - 2>;

template <>
constexpr auto fib<0> = 0;

template <>
constexpr auto fib<1> = 1;

// example 5
template <typename T, typename U>
constexpr bool is_same = false;

template <typename T>
constexpr bool is_same<T, T> = true;

// example 6
template <typename T>
constexpr auto add = [](const T &lhs, const T &rhs)
{
	return lhs + rhs;
};

int main()
{
	std::cout << std::setprecision(20);
	std::cout << pi<float> << '\n';
	std::cout << pi<double> << '\n';
	std::cout << pi<long double> << '\n';
	std::cout << pi<int> << '\n';

	std::cout << value<double> << '\n';

	std::cout << fib<8> << '\n';

	std::cout << is_same<int, int> << '\n';
	std::cout << is_same<int, bool> << '\n';

	std::cout << add<int>(3.1, 4234.2) << '\n';
}
