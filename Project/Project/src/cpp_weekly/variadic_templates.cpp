#include <iostream>
#include <vector>
#include <sstream>

template <typename ...Args>
void print(const Args &...t)
{
	(void)std::initializer_list<int>{ (std::cout << t << '\n', 0)... };
}

int f1()
{
	std::cout << __FUNCTION__ << '\n';
	return 1;
}

int f2()
{
	std::cout << __FUNCTION__ << '\n';
	return 2;
}

template <typename ...T>
std::vector<std::string> succintToString(const T &...t)
{
	// most succinct way, also least executable size
	std::vector<std::string> result;
	std::stringstream ss;
	(void)std::initializer_list<int>{
		(ss.str(""),
		ss << t,
		result.push_back(ss.str()), 0)...
	};
	return result;
}

int main()
{
	// gcc, msvc print f2(), f1()
	// clang prints f1(), f2()
	print(f1(), f2());

	std::cout << "----" << '\n';

	// order is guaranteed
	(void)std::initializer_list<int>{f1(), f2()};
	auto i = (f1(), f2());
	std::cout << i << '\n';

	std::cout << "----" << '\n';

	for (const auto &v : succintToString("Hello", "World", 5.4, 1.1, 2.2))
		std::cout << v << '\n';
}