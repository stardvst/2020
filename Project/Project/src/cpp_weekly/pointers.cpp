#include <iostream>
#include <memory>
#include <vector>

int main()
{
	auto printAddress = [](const auto &p)
	{
		std::cout << std::to_address(p) << '\n';
	};

	auto intPtr = std::make_unique<int>(15);
	printAddress(intPtr); // heap address

	int i{ 17 };
	//printAddress(i); // can't do, to_address expects pointer-like thing
	printAddress(&i); // stack address

	std::vector<int> vec{ 1, 2, 3 };
	printAddress(vec.begin()); // heap address
}
