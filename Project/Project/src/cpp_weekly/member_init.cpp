#include <iostream>

struct S
{
	// c++20
	int i : 3 = 0;
	int j : 5 = 0;

	// before
	S() : i(0), j(0)
	{
	}
};

int main()
{
	// 4 bytes, we're getting padding
	std::cout << sizeof(S);
}
