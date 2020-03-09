#include <iostream>

void func()
try
{
}
catch (...)
{
}

struct Throwing
{
	Throwing(int i)
	{
		if (i > 2)
			throw i;
	}
};

struct S
{
	S(int val) try
		: t(val)
	{
	}
	catch (int i) // is S constructed at this point? no!
	{
		std::cerr << i << " was thrown.\n";
	}

	Throwing t;
};

int main()
{
	func();

	S s1(5); // throws at construction
	S s2(1); // does not throw
}
