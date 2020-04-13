#include <iostream>

struct S
{
	int i;
	unsigned int j;
};

template <typename T>
struct ST
{
	ST(T i1, int j1)
		: i(i1), j(j1)
	{
	}

	T i;
	unsigned int j;
};

int main()
{
	//auto value1 = S{ .i{1}, .j = 2 }; // cannot do

	// even though braced-init is not allowed, it is more
	// equivalent to braced-init not allowed implicit conversions
	//auto value2 = S{ .i = 1, .j = -2 };

	auto value3 = S{ .i = 1, .j = 2 };
	std::cerr << value3.j << '\n';

	auto value4 =
	S{
		.i = []() { return 1; }(),
		.j = 2
	};
	std::cerr << value4.i << '\n';

	// ST must have constructor for deducing types,
	// even if we add one, it won't work with designated initializers
	auto value5 =
		ST<int>{
		/*.i = */[]() { return 1; }(),
		/*.j = */2
	};
	std::cerr << value5.i << '\n';
}
