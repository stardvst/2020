#include <iostream>
#include <vector>

int main()
{
	std::vector<int> data{ 1, 2, 3, 4, 5, 6 };

	// no warning until c++20; deprecated in c++20
	std::cout << data[2, 3]; // prints 4
}
