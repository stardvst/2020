#include <iostream>
#include <type_traits>

template <typename Float>
auto go(const Float value1, const Float value2)
{
	return value1 + value2;
}

// SFINAE
template <typename Float, typename = std::enable_if_t<std::is_floating_point_v<Float>>>
auto goFloat(const Float value1, const Float value2)
{
	return value1 + value2;
}

// c++20, more clear error if not float
template <typename Float>
auto goFloat20(const Float value1, const Float value2) requires std::is_floating_point_v<Float>
{
	return value1 + value2;
}

// or pass concept to template
template <typename T>
concept floating_point = std::is_floating_point_v<T>;

template <floating_point Float>
auto goFloat20Con1(const Float value1, const Float value2)
{
	return value1 + value2;
}

floating_point goFloat20Con2(const floating_point auto value1, const floating_point auto value2)
{
	return value1 + value2;
}

int main()
{
	std::cout << go(1, 1) << '\n';
	std::cout << go(1.3, 1.2) << '\n';
	//std::cout << go(1.3, 2) << '\n';

	//std::cout << goFloat(1, 1) << '\n';
	std::cout << goFloat(1.3, 1.2) << '\n';
	//std::cout << goFloat(1.3, 2) << '\n';

	////std::cout << goFloat20(1, 1) << '\n';
	//std::cout << goFloat20(1.3, 1.2) << '\n';
	////std::cout << goFloat20(1.3, 2) << '\n';

	//std::cout << goFloat20Con1(1, 1) << '\n';
	std::cout << goFloat20Con1(1.3, 1.2) << '\n';
	//std::cout << goFloat20Con1(1.3, 2) << '\n';

	//std::cout << goFloat20Con2(1, 1) << '\n';
	std::cout << goFloat20Con2(1.3, 1.2) << '\n';
	//std::cout << goFloat20Con2(1.3, 2) << '\n';

	floating_point auto val = goFloat20Con2(1.2, 2.3f);
}
