#include <iostream>
#include <functional>
#include <utility>

// for objects
template <
	typename Class,
	typename Ret,
	typename ...Param,
	typename Obj,
	typename ...Args
>
auto invoke(Ret (Class::*func)(Param...) const noexcept,
	Obj &&obj,
	Args &&...args)
{
	return (std::forward<Obj>(obj).*func)(std::forward<Args>(args)...);
}

// free function
template <
	typename Ret,
	typename ...Param,
	typename ...Args
>
auto invoke(Ret(*func)(Param...),
	Args &&...args)
{
	return (func)(std::forward<Args>(args)...);
}

template <
	typename Callable,
	typename ...Param
>
auto invoke(Callable &&callable, Param &&...param)
{
	return callable(param...);
}

template <typename Func, typename ...Params>
auto bind_front(Func &&f, Params &&...params)
{
	// return how many params passed, bound to the callable
	return[f = std::forward<Func>(f),
		...boundParams = std::forward<Params>(params)]
		(auto &&... restParams) -> decltype(auto) // perfect returning
	{
		return invoke(f, boundParams...,
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
	// without ::, due to ADL, std version is also available => ambuguity!
	std::string s;
	auto func = ::bind_front(&std::string::size, s);
	std::cout << func() << '\n';

	auto ret = bind_front(&add, 1, 2);
	std::cout << ret(3);
}
