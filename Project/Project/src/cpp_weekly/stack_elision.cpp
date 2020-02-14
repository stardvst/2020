#include <iostream>
#include <type_traits>
#include <numeric>
#include <iterator>

template <typename ...T>
int sum(T ...t)
{
	std::common_type_t<T...> arr[sizeof...(T)]{ t... };
	return std::accumulate(std::begin(arr), std::end(arr), 0);
}

int main()
{
	std::cout << sum(9, 8, 7, 6, 5, 4, 3, 2, 1);
}