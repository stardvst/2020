#include <iostream>
#include <mutex>

constexpr /* must */ int getValue()
{
	return 42;
}

int useValue()
{
	//static auto val = getValue(); // init-ed compile time
	constinit static auto val = getValue(); // surely init-ed compile time
	return ++val; // val is not constant
}

void f()
{
	constinit static std::mutex m; // init-ed compile time, before function executes

	std::scoped_lock l(m); // global mutable thread-safe lock-protected value
	constinit static auto val = 4; // init-ed compile time
	++val;
	return val;
}

int main()
{
	constinit static /* must */ auto i = 4;

	constinit static auto j = getValue();


}
