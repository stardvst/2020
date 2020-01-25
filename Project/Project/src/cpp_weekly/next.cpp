#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main()
{
	std::vector v{ 1, 2, 3, 4, 5, 6, 7 };

	std::cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';

	// everything except 1st element is sorted
	v = { 3, 2, 3, 4, 5, 6, 7 };
	auto begin = v.cbegin();
	++begin;
	std::cout << std::is_sorted(begin, v.cend()) << '\n';

	// cannot +1, not a random access iterator
	std::list l{ 3, 2, 3, 4, 5, 6, 7 };
	//std::cout << std::is_sorted(std::begin(l) + 1, std::end(l)) << '\n';

	// correct way
	std::cout << std::is_sorted(std::next(std::begin(v)), std::end(v)) << '\n';
	std::cout << std::is_sorted(std::next(std::begin(l)), std::end(l)) << '\n';
}