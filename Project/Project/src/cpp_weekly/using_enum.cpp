#include <iostream>
#include <string>

enum struct Values
{
	value1,
	value2
};

std::string choose(Values val)
{
	switch (val)
	{
		using enum Values;
		case value1:
			return "value1";
		case value2:
			return "value2";
	}

	return "unknown value";
}

struct A
{
	using enum Values;
	Values val;

	A(Values v) : val(v) {}
};

int main()
{
	A a1(Values::value1);
	A a2(Values::value2);
	std::cout << choose(a1.val) << '\n';
	std::cout << choose(a2.val) << '\n';
}
