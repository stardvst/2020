#include <iostream>

struct A
{
	virtual void print()
	{
		std::cout << 'a';
	}
};

struct B : A
{
	void print() override
	{
		std::cout << 'b';
	}
};

int main()
{
	B b1;
	A a1 = b1, &a2 = b1;

	a1.print();
	a2.print();
}