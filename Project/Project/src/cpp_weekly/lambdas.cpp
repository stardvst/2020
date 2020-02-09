#include <iostream>

int main()
{
	int i = 1;
	auto l = [i]
	{
		return i;
	};

	auto l2 = [&i]
	{
		return ++i;
	};

	auto l3 = [i]() mutable
	{
		return ++i;
	};

	// c++14, stateful lambda
	auto l4 = [counter = 0]() mutable
	{
		return ++counter;
	};
	l4();
	l4();

	// Fibonacci sequence, probably fastest way
	auto l5 = [a1 = 0, a2 = 1]() mutable
	{
		a1 = std::exchange(a2, a1 + a2);
		return a1;
	};

	std::cout << l() << '\n';
	std::cout << l2() << '\n';
	std::cout << l3() << '\n';
	std::cout << l4() << '\n';

	std::cout << "Fibonacci sequence: ";
	for (auto i = 0; i < 6; ++i)
		std::cout << l5() << ' ';
}