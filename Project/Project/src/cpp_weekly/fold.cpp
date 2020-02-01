#include <iostream>
#include <type_traits>
#include <vector>

// c++14
template <typename ...T>
auto sum14(T ...t)
{
	std::common_type_t<T...> result{};
	(void)std::initializer_list<int>{(result += t, 0)...};
	return result;
}

template <typename ...T>
auto sum17(T ...t)
{
	return (t + ...);
}

template <typename ...T>
auto div17left(T ...t)
{
	// (((E[1] op E[2]) op ...) op E[N])
	return (... / t);
}

template <typename ...T>
auto div17right(T ...t)
{
	// (E[1] op(... op(E[N-1] op E[N])))
	return (t / ...);
}

template <typename ...T>
auto avg17(T ...t)
{
	return (t + ...) / sizeof...(T);
}

template <typename ...T>
auto print17(T ...t)
{
	(std::cout << ... << t) << '\n';
}

template <typename T, typename ...Args>
void foldPushBack(std::vector<T> &v, Args &&...args)
{
	(v.push_back(args), ...);
}

int main()
{
	std::cout << sum14(1, 2, 3.0, 4.5) << '\n';
	std::cout << sum17(1, 2, 3.0, 4.5) << '\n';
	std::cout << div17left(1, 2, 3.0, 4.5) << '\n';
	std::cout << div17right(1, 2, 3.0, 4.5) << '\n';
	std::cout << avg17(1, 2, 3.0, 4.5) << '\n';
	print17(1, 2, 3, "hello world");

	std::vector<int> v;
	foldPushBack(v, 1, 2, 3, 4);
	for (const auto &i : v)
		std::cout << i << ' ';
}