#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> makeVec()
{
	return { 1, 2, 3, 4 };
}

int main()
{
	auto vec = makeVec();

	// because it lasts longer than needed...
	{
		const auto it = std::find(vec.begin(), vec.end(), 2);
		if (it != vec.cend())
			*it = 3;
		else
			vec.insert(it, 6);
	}

	for (const auto &v : vec)
		std::cout << v << ' ';
	std::cout << '\n';

	{
		const auto it = std::find(vec.rbegin(), vec.rend(), 3);
		if (it != vec.rend())
			*it = 4;
	}

	for (const auto &v : vec)
		std::cout << v << ' ';
	std::cout << '\n';

	// so, in c++17...
	if (const auto it = std::find(vec.begin(), vec.end(), 5);
		it != vec.cend())
	{
		*it = 6;
	}
	else if (const auto front = vec.front(); front != 2)
	{
		// it exists here too!
		vec.insert(it, 2);
	}

	for (const auto &v : vec)
		std::cout << v << ' ';
	std::cout << '\n';
}