#include <iostream>
#include <vector>

int main()
{
	auto l1 = [](auto first, auto second)
	{
		return first + second;
	};

	std::cout << l1(2, 4) << '\n';
	std::cout << l1(2.1, 4.9) << '\n';

	// same as above because auto uses the same rules
	// as template type deduction
	auto l2 = []<typename T>(T first, T second)
	{
		return first + second;
	};

	std::cout << l2(2, 4) << '\n';
	//std::cout << l2(2, 4.5) << '\n'; // doesn't work
	//std::cout << l2(2.1, 4) << '\n'; // doesn't work

	auto l3 = []<typename T>(const std::vector<T> &v)
	{
		return v.size();
	};

	std::vector<int> vec{ 1, 2, 3, 4 };
	std::cout << l3(vec) << '\n';
}
