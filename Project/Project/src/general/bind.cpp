#include <iostream>
#include <functional>

void f(int n)
{
	std::cout << n << '\n';
}

void g(int &n)
{
	n = 4;
	std::cout << n << '\n';
}

int main()
{
	int n = 4;
	std::bind(f, std::placeholders::_1);
	n = 5;
	f(n);

	g(n);
}
