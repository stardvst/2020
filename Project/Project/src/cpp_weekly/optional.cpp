#include <iostream>
#include <optional>

// std::optional will not do dynamic allocation on its own

struct S
{
	S() = default;
	S(const S &) = delete;
	S(S &&) = delete;
};

int main()
{
	std::optional<int> io;
	std::cout << sizeof(io) << '\n'; // 8, size of int + its holder (pointer?)

	//std::cout << io.value(); // crash, value not set
	std::cout << io.value_or(2) << '\n';

	std::optional<std::string> so;
	so = "Hello"; // assigns to empty values, assignment to optional
	so = "World!"; // calls assignment operator on int, i.e. to the thing that optional contains
	std::cout << so.value() << '\n';

	so = std::string("Hello"); // move assignment

	std::optional<S> o;
	// o = S(); // compile error, no move/copy ctor available
	o.emplace(); // instead, constructs in place, no move/copy needed
}
