#include <iostream>
#include <functional>

// uniform interface for calling callable things

int doSomething(const int i)
{
	return i + 5;
}

struct S
{
	int doSomething(const int i)
	{
		return i + j;
	}

	int doSomething2(const int i)
	{
		return i * j;
	}

	int j = 5;
};

int main()
{
	std::cout << std::invoke(&doSomething, 5) << '\n'; // 10

	S s;
	std::cout << s.doSomething(3) << '\n'; // 8

	auto fp = &S::doSomething;
	std::cout << (s.*fp)(3) << '\n'; // 8

	int (S:: *fp2)(int) = &S::doSomething;
	std::cout << (s.*fp2)(3) << '\n'; // 8

	int (S:: *fp3)(int) = nullptr;
	if (true)
		fp3 = &S::doSomething2;
	else
		fp3 = &S::doSomething;
	std::cout << (s.*fp3)(3) << '\n'; // 15

	// instead...
	std::cout << std::invoke(&S::doSomething, s, 1) << '\n'; // 6
	std::cout << std::invoke(&S::doSomething2, s, 2) << '\n'; // 10
	std::cout << std::invoke(&S::j, s) << '\n'; // 5, access member
}