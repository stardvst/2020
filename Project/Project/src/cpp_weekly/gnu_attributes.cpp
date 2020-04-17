#include <iostream>

// not standard, compiler-specific
#ifndef _MSC_VER
__attribute__((always_inline))
#endif
int add1(int i, int j)
{
	return i + j;
}

// c++14 standard, portable!
[[msvc::always_inline]] [[gnu::always_inline]] int add2(int i, int j)
{
	return i + j;
}

int main()
{
	std::cout << add1(1, 2) << '\n';
	std::cout << add2(1, 2) << '\n';
}

