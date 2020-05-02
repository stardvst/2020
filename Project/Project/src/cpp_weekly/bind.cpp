#include <iostream>
#include <functional>
#include <utility>

template <typename Func, typename ...Params>
auto bind_front(Func &&f, Params &&...params)
{
	// return how many params passed, bound to the callable
	return[f = std::forward<Func>(f),
		...boundParams = std::forward<Params>(params)]
		(auto &&... restParams) -> decltype(auto) // perfect returning
	{
		return f(boundParams...,
			std::forward<decltype(restParams)>(restParams)...);
	};
}

int add(int i, int j, int k)
{
	std::cout << "i: " << i << ", j: " << j << ", K: " << k << '\n';
	return i + j + k;
}

int main()
{
	// binds first two arguments
	auto func = bind_front(&add, 1, 2);

	// bind the 3rd argument
	std::cout << func(3);
}
