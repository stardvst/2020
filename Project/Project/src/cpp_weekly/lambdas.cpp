#include <iostream>
#include <thread>
#include <future>

int main()
{
	auto l1 = [val = 0]() mutable
	{
		return ++val;
	};

	// cannot copy with initial state
	// is not thread-safe
	auto l2 = []
	{
		static auto val = 0;
		return ++val;
	};

	// will increment the same val as in l2
	auto l3 = l2;

	std::cout << l1() << '\n';
	std::cout << l1() << '\n';

	std::cout << l2() << '\n';
	std::cout << l2() << '\n';

	std::cout << l3() << '\n';
	std::cout << l3() << '\n';

	// val is shared in across main and other threads
	auto f1 = std::async(std::launch::async, l2);
	f1.get();
	std::cout << l2() << '\n';

	auto l4 = []
	{
		thread_local auto val = 0;
		return ++val;
	};

	auto f2 = std::async(std::launch::async, l4);
	f2.get();

	std::cout << l4() << '\n';
	std::cout << l4() << '\n';
}
