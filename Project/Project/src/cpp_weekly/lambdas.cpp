#include <iostream>
#include <array>

int main()
{
	auto l = [val = 2]{ return val; };

	// cannot access private member declared in class
	// 'main::<lambda_7353eea49db4595be34d9f57d4c82dc6>'
	// l.val = 4;

	std::cout << l() << '\n';

	std::array arr = { 1, 2, 3, 4, 5 };
	int sum = 0;
	for (const auto &v : arr)
	{
		sum += v;
		//++__for_begin;
	}

	std::cout << sum << '\n';
}
