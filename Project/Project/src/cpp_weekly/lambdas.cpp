#include <string>
#include <functional>

int main()
{
	// lambdas can be converted into function pointers
	// it must be non-capturing lambda (which has state)
	std::vector<std::function<int(int, int)>> functions1;
	functions1.emplace_back([](int i, int j)
	{
		return i + j;
	});
	functions1.emplace_back([](int i, int j)
	{
		return i - j;
	});

	// above has overhead for generating type erasure, instead take
	// advantage of lambda to function pointer conversion.
	// in this case less code is generated
	std::vector<int (*)(int, int)> functions2;
	functions2.emplace_back([](int i, int j)
	{
		return i + j;
	});
	functions2.emplace_back([](int i, int j)
	{
		return i - j;
	});
}
