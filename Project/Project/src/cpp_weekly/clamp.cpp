#include <iostream>
#include <algorithm>

int main(const int argc, const char *[])
{
	// make sure value is in given range:
	// 1. if it's less than lo, returns lo
	// 2. if it's greater than hi, returns hi
	// 3. else returns value
	std::cout << ((argc < 2) ? 2 : (argc > 5) ? 5 : argc) << '\n';
	std::cout << std::clamp(argc, 2, 5) << '\n';
}