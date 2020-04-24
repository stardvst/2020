#include <iostream>

// #1: name 'fib' cannot be used before it is initialized
//constexpr auto fib = [](int input)
//{
//	if (input < 2)
//		return input;
//	return fib(input - 1) + fib(input - 2);
//};

// #2
constexpr auto fib = [](const auto fib, int input)
{
	if (input < 2)
		return 1;
	return fib(fib, input - 1) + fib(fib, input - 2);
};

// #3
constexpr auto fibBase = [](const auto fib, int input)
{
	if (input < 2)
		return 1;
	return fibBase(fibBase, input - 1) + fibBase(fibBase, input - 2);
};

constexpr auto fibRec = [](int input)
{
	return fibBase(fibBase, input);
};

// #4
constexpr auto fibRec2 = [](int input)
{
	auto fibLocal = [](const auto fibParam, int input)
	{
		if (input < 2)
			return 1;
		return fibParam(fibParam, input - 1) + fibParam(fibParam, input - 2);
	};
	return fibLocal(fibLocal, input);
};

// #5: mutually exclusive recursive lambdas
auto fibMutExcl1 = [](const auto f1, const auto f2, int input)
{
	if (input < 2)
		return 1;
	return input + f2(f1, f2, input - 1);
};

auto fibMutExcl2 = [](const auto f1, const auto f2, int input)
{
	if (input < 2)
		return 1;
	return input + f1(f1, f2, input - 1);
};

int main()
{
	std::cout << fib(fib, 3) << '\n';
	std::cout << fibRec(3) << '\n';
	std::cout << fibRec2(3) << '\n';
	std::cout << fibMutExcl1(fibMutExcl1, fibMutExcl2, 3) / 2 << '\n';
}
