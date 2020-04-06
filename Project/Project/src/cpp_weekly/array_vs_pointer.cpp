#include <iostream>

auto getArray()
{
	// address of local variable 'arr' returned
	// (it wants to be a pointer)
	const int arr[] = { 1, 2, 3, 4, 5 };
	return arr;
}

// we might think expects array, but no!
// it expects a pointer to const!
// it doesn't even matter what the size is!
void useArray(const int arr[5])
{
}

int main()
{
	// implicitly converts to pointer, not good!
	const int arr1[] = { 1, 2, 3, 4, 5 };
	const int *ptr1 = arr1;

	// compares pointers => always false!
	const int arr2[] = { 1, 2, 3, 4, 5 };
	std::cout << (arr1 == arr2) << '\n';

	// what is the type of copy
	const auto copy = arr1;
	std::cout << std::boolalpha;
	std::cout << std::is_array_v<decltype(copy)> << '\n'; // false
	std::cout << std::is_pointer_v<decltype(copy)> << '\n'; // true

	// compiles
	const int arr3[] = { 1, 2, 3 };
	useArray(arr3);
}
