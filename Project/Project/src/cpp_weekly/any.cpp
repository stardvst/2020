#include <iostream>
#include <any>
#include <vector>
#include <type_traits>

// type-safe container for single values of any type

struct S
{
	//S(const S &s) = delete;
	S(const S &s) = default;
	S() = default;
};

int main()
{
	static_assert(std::is_nothrow_move_constructible_v<S>);

	std::cout << sizeof(std::any) << '\n';

	std::any v = 5;
	std::cout << std::any_cast<int>(v) << " is of type " << v.type().name() << '\n';

	std::vector<std::any> vec{ 5, 3.4, std::string("Hello World") };

	try
	{
		std::cout << std::any_cast<float>(vec.front());
	}
	catch (const std::bad_any_cast &ex)
	{
		std::cout << ex.what() << '\n';
	}

	// if we wanna modify object, must get by pointer
	auto i = std::any_cast<int>(&vec[0]);
	*i = 10;
	std::cout << std::any_cast<int>(vec[0]);
}