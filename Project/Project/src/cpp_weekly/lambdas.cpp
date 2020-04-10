#include <iostream>

template <typename ...T>
auto doStuff1(T ...t)
{
	return (t + ...);
}

template <typename ...T>
auto doStuff2(T ...t)
{
	return ([t]() { return t; }() +...);
}

int main()
{
	std::cout << doStuff1(1, 2, 3, 4, 5) << '\n';
	std::cout << doStuff2(1, 2, 3, 4, 5) << '\n';
}
