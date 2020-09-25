#include <iostream>

int main()
{
	/*const*/ auto l = [i = 0]() mutable { return i++; };
	std::cout << l() << '\n'; // cannot call operator()() (non-const) on const object
}
