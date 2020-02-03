#include <iostream>

struct A
{
	int m_i;
};

struct B
{
	B(const int i) : m_i(i)
	{
	}

	int m_i;
};

struct S17Base
{
	double m_d;
};

struct S17 : S17Base
{
	int m_i;
	float m_f;
};

int main()
{
	//A a(1); // cannot do; no ctor, so we add one, that's class B

	B b(1);

	// uniform init
	S17Base base{ 33.5 };
	std::cout << base.m_d << '\n';
	//S17 sd{ 1, 2.3 }; // cannot init base

	S17 sb{ { 54.8 }, 1, 2.3 };
	std::cout << (sb.m_d + sb.m_f) << '\n';
}
