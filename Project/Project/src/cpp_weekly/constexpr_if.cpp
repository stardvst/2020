#include <iostream>

template <typename T>
void printTypeInfo(const T &)
{
	if /*constexpr*/ (std::is_integral_v<T>)
		std::cout << "is integral\n";
	else
		std::cout << "is not integral\n";
}

template <typename T>
auto returnSomething(const T &t)
{
	if constexpr (std::is_integral_v<T> && !std::is_same_v<bool, T>)
	{
		// compile error for char *, no specilization.
		// yes, whole if is evaluated...
		//&& std::numeric_limits<T>::min() < 1000)

		// but this will not do what we intended to...
		if constexpr (std::numeric_limits<T>::min() < 1000)
			return t + 1;
	}
	else if constexpr (std::is_floating_point_v<T>)
		return t + 0.1;
	else
		return t;
}

// so we'll have another function
template <typename T>
constexpr bool isBoth()
{
	if constexpr (std::is_integral_v<T> && !std::is_same_v<bool, T>)
	{
		if constexpr (std::numeric_limits<T>::max() < 1000)
			return true;
	}
	return false;
}

template <typename T>
auto returnSomethingCond(const T &t)
{
	if constexpr (isBoth<T>())
		return t + 1;
	else if constexpr (std::is_floating_point_v<T>)
		return t + 0.1;
	else
		return t;
}

int main()
{
	printTypeInfo(5);
	printTypeInfo(2.3);

	std::cout << "---\n";

	std::cout << returnSomething(5) << '\n';
	std::cout << returnSomething(2.3) << '\n';
	std::cout << returnSomething(true) << '\n'; // true is integral
	std::cout << returnSomething("hello world") << '\n';

	std::cout << "---\n";

	std::cout << returnSomethingCond(char(5)) << '\n';
}