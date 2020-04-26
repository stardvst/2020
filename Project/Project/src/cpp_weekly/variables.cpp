#include <iostream>

struct S
{
	const static std::string s1;

	// comes with cost, a check guard
	inline const static std::string s2 = "Hello World";

	// cheapest way is this:
	// 1. not constructing a std::string
	// 2. no static initialization
	// 3. no locks, guards
	// 4. taking advantage of std::string_view
	constexpr static std::string_view s()
	{
		// guaranteed for life of program
		return "Hello World";
	}
};

// give compiler place and time to initialize it
const std::string S::s1 = "Hello World";

int main()
{
}
