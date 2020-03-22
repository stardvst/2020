#include <iostream>

struct S1
{
	constexpr void f(int) const noexcept
	{
	}

	constexpr void f(double) const noexcept = delete;
};

struct S2
{
	template <typename T>
	constexpr void f(T) const noexcept
	{
	}

	// specifically delete the double version
	constexpr void f(double) const noexcept = delete;
};

int main()
{
	S1 s1;
	s1.f(1);
	//s1.f(1.0); // deleted
	//s1.f(1.0f); // implicit conversion to double
	//s1.f(2ll); // ambiguous

	S2 s2;
	s2.f(1);
	//s2.f(1.0);
	s2.f(1.0f);
	s2.f(2ll);
}
