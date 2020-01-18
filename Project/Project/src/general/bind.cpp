#include <iostream>
#include <functional>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>

void f(int n1, int n2, int n3, const int &n4, int n5)
{
	std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
	return n1;
}

struct Foo
{
	void printSum(int n1, int n2)
	{
		std::cout << n1 + n2 << '\n';
	}
	int data = 10;
};

int main()
{
	using namespace std::placeholders;

	int n = 7;
	auto f1 = std::bind(f, _2, 42, _1, std::cref(n), n);
	n = 10;
	f1(1, 2, 1001);
	// prints 2, 42, 1, 10, 7

	auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
	f2(10, 11, 12);
	// prints 12, 12, 12, 4, 5

	std::default_random_engine engine;
	std::uniform_int_distribution<> dis(0, 10);
	auto rnd = std::bind(dis, engine);
	for (auto n = 0; n < 10; ++n)
		std::cout << rnd() << ' ';
	std::cout << '\n';

	Foo foo;
	auto f3 = std::bind(&Foo::printSum, &foo, 95, _1);
	f3(5);
	// prints 100

	auto f4 = std::bind(&Foo::data, _1);
	std::cout << f4(foo) << '\n';
	// prints 10

	std::cout << f4(std::make_shared<Foo>(foo)) << ' '
		<< f4(std::make_unique<Foo>(foo)) << '\n';
	// prints 10, 10

	std::vector<double> vec{ 1, 2, 3, 4, 5 }, res(vec.size());
	std::transform(vec.begin(), vec.end(), res.begin(), std::bind(static_cast<double(*)(double, double)>(&std::pow), _1, 2.0));
	for (const auto &v : res)
		std::cout << v << ' ';
	std::cout << '\n';
}
