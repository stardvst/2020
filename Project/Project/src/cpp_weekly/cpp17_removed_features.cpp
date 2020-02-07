#include <iostream>
#include <array>

int doSomething(int i, int j)
{
	return i + j;
}

int main()
{
	// always store in register (for performance)
	// now compilers do that without the keyword
	register bool b;

	// incrementing bool
	++b;

	// auto_ptr, not optimized
	auto_ptr<int> i;

	// doesn't use good random number generator
	// is permitted to use the std::rand()
	// is permitted to allow data races for thread-unsafe version
	std::array<int, 5> a{ 1, 2, 3, 4, 5 };
	std::random_shuffle(std::begin(a), std::end(a));

	// bind 1st argument to some known value
	// but: requires function object, cannot work with ordinary function
	const auto f = std::bind1st(
		std::function<int(int, int)>(&doSomething), 1);
	std::cout << f(3) << '\n'; // prints 4

	// use these
	const auto f1 = std::bind(&doSomething, 1, std::placeholders::_1);
	const auto f2 = []
	{
		return doSomething(i, 1);
	};

}