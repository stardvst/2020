#include <iostream>
#include <functional>

int add(int i, int j, int k)
{
	std::cout << "i: " << i << ", j: " << j << ", K: " << k << '\n';
	return i + j + k;
}

int main()
{
	// binds first two arguments
	auto func = std::bind_front(&add, 1, 2);

	// bind the 3rd argument
	std::cout << func(3);
}
