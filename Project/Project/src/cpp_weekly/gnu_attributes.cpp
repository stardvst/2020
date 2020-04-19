#include <iostream>

struct S
{
	[[gnu::pure]] int incr()
	{
		return ++val;
	}

	int non_const()
	{
	}

	int val = 0;
};

int main(int argc, const char *[])
{
	S s;

	// prints 0, since compiler optimized away based on gnu::pure
	// no calls to this are generated
	s.incr();
	s.incr();
	std::cout << s.val << '\n';

	// function call is generated, since it's non-const and
	// can change object state
	int i = s.non_const();
	i += s.non_const();
}

