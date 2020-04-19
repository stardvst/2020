#include <iostream>
#include <memory>
#include <cstdio>
#include <set>

// topics covered:
// 1. default constructible lambdas
// 2. assignable lambdas
// 3. lambdas in unevaluated context

struct MyData
{
	std::string key;
	std::string value;
};

int main()
{
	auto l = [] { return 5; };
	auto m = l; // copy of lambda, same type, c++17
	l = m; // operator= is deleted in c++17, works in c++20

	decltype(l) k; // lambda of above type, c++20
	(void)k();

	decltype([] {}) n; // lambda in unevaluated context error in c++17

	// c++17
	auto deleter = [](FILE *f) { fclose(f); };
	auto file17 = std::unique_ptr<FILE, decltype(deleter)>(
		fopen("a.txt", "w"), deleter);

	// c++20
	// lambdas are default constructible, no need to pass
	// lambdas in unevaluated context can be used
	auto file20 = std::unique_ptr <
		FILE,
		decltype([](FILE *f) { fclose(f); }) > (
			fopen("a.txt", "w")
			);

	// 3. lambdas in unevaluated context
	std::set < MyData, decltype([](const MyData &lhs, const MyData &rhs)
	{
		return lhs.key < rhs.key;
	}) > set2;
}
