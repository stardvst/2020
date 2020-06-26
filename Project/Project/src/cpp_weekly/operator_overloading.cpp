#include <cstdio>

struct S
{
	S(const bool b)
		: value(b)
	{
	}

	bool value;
};

bool getBool(const bool b)
{
	puts("getBool()");
	return b;
}

S makeS(const bool b)
{
	puts("makeS()");
	return S(b);
}

bool operator||(const S &lhs, const S &rhs)
{
	return lhs.value || rhs.value;
}

bool operator&&(const S &lhs, const S &rhs)
{
	return lhs.value && rhs.value;
}

struct Complex
{
	Complex(const double R)
		: r{ R }, i{ 0 }
	{
	}

	constexpr Complex(const double R, const double I)
		: r{ R }, i{ I }
	{
	}

	// free + friend + inline function, specified in the body of the class,
	// and all implicit conversions take place!
	[[nodiscard]] friend constexpr Complex operator+(const Complex &lhs, const Complex &rhs)
	{
		return Complex{ lhs.r + rhs.r, lhs.i + rhs.i };
	}

	// problem with member function: cannot do this: 4.5 + c
	/*
	Complex operator+(const Complex &rhs)
	{
		return Complex{ r + rhs.r, i + rhs.i };
	}
	*/

private:
	double r;
	double i;
};

// problem with free function: cannot access private members
/*
Complex operator+(const Complex &lhs, const Complex &rhs)
{
	return Complex{ lhs.r + rhs.r, lhs.i + rhs.i };
}
*/

#include <iostream>
#include <string>

struct Pointer
{
	std::string *p;

	constexpr auto *operator->()
	{
		return p;
	}

	constexpr auto *operator->() const
	{
		return p;
	}
};

int main()
{
	// only first is called
	getBool(true) || getBool(false);
	puts("---");

	// both are called - weird!
	makeS(true) || makeS(false);
	puts("---");

	// only 1st and 2nd are called!
	getBool(true) && (getBool(true) || getBool(false));
	puts("---");

	// all are called - weird!
	makeS(true) && (makeS(true) || makeS(false));

	Complex c{ 1, 2 };
	const auto r = 4.5 + c;
	const auto result = c + Complex{ 3, 4 };

	std::string s{ "Hello world" };
	Pointer dumbPointer{ &s };
	std::cout << dumbPointer->size() << '\n';
}
