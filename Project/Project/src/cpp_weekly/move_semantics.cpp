#include <iostream>
#include <string>

struct S
{
	S(const S &)
	{
		std::cout << "copy ctor\n";
	}

	S(S &&)
	{
		std::cout << "move ctor\n";
	}

	S &operator=(const S &) = default;
	S &operator=(S &&) = default;

	S() = default;
	~S() = default;

	std::string str = "Hello world long string";
};

int main()
{
	std::string s1 = "Hello World!";
	const std::string s2 = "Hello World!";

	std::string &&ref1 = std::move(s1); // move returns &&
	const std::string &&ref2 = std::move(s2); // move returns const &&...
	//^^^
	// so const is mandatory

	S o1;
	S o2(std::move(o1)); // move ctor expects S &&, ok

	// const S && is passed to move ctor, which cannot be bind to
	// non-const r-value reference (which move ctor expects), and
	// so it uses normal overloading rules, and uses copy ctor instead!
	const S o3;
	S o4(std::move(o3));
}