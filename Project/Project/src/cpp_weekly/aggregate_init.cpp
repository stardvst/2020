#include <iostream>

struct A
{
	A() = delete;
	//A(int) {}
	//A(int, int) {}
	int m_i;
	int m_j;
};

int main()
{
	// no instance of constructor "A::A" matches the argument list
	// since ctor is deleted, c++20 rule
	A a{ 1, 2 };
}
