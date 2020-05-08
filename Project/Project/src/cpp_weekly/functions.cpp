#include <iostream>

// higher order functions: something that takes a function
// and returns a function

template <typename F, typename G>
auto f_of_g(F &&f, G &&g)
{
	return[
		f = std::forward<F>(f),
		g = std::forward<G>(g)]
	{
		return f(g());
	};
}

int expensive(int)
{
	return 0;
}

int evenMoreExpensive()
{
	return 1;
}

int main()
{
	// lazily evaluated, will not do anything until calc() is called
	auto calc = f_of_g(expensive, evenMoreExpensive);

	int val;
	std::cin >> val;
	if (val > 2)
		std::cout << calc();
}
