#include <iostream>
#include <typeinfo>

struct __main_lambda_0
{
	constexpr auto operator()() const
	{
		return 5;
	}
};

struct __main_lambda_1
{
	constexpr auto operator()(int i) const
	{
		return 5 + i;
	}
};

struct __main_lambda_2
{
	int val;
	constexpr auto operator()(int i) const
	{
		return 5 + i + val;
	}
};

struct __main_lambda_3
{
	int val;
	constexpr auto operator()(int i)
	{
		return 5 + i + ++val;
	}
};

struct __main_lambda_4
{
	int val;

	template <typename T>
	constexpr auto operator()(T i)
	{
		return 5 + i + ++val;
	}
};

int main()
{
	auto l0 = []() { return 5; };
	puts(typeid(l0).name());

	auto l1 = [](int i) { return 5 + i; };
	puts(typeid(l1).name());

	// can't mutate val
	int val = 10;
	auto l2 = [val](int i) { return 5 + i + val; };
	puts(typeid(l2).name());

	auto l3 = [val](int i) mutable { return 5 + i + ++val; };
	puts(typeid(l3).name());

	auto l4 = [val](auto i) mutable { return 5 + i + ++val; };
	puts(typeid(l4).name());
}
