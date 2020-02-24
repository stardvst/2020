#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

// Fills the range [first, last) with sequentially increasing values,
// starting with value and repetitively evaluating ++value

int main()
{
	std::array<int, 10> arr;
	std::iota(std::begin(arr), std::end(arr), 0);
	std::cout << arr.back() << '\n'; // 9

	// same as above, and more... can do i++ or ++i, etc.
	std::generate(std::begin(arr), std::end(arr),
		[i = 0]() mutable
	{
		return i++;
	});
	std::cout << arr.back() << '\n'; // 9
}