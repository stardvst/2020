#include <iostream>

#include <array>

struct Base
{
	// why on earth constexpr + virtual?
	[[nodiscard]] constexpr virtual int get() const = 0;
};

struct Derived1 : Base
{
	[[nodiscard]] constexpr int get() const override
	{
		return 5;
	}
};

struct Derived2 : Base
{
	[[nodiscard]] constexpr int get() const override
	{
		return 10;
	}
};

constexpr auto getSomeValues()
{
	const Derived1 d1_1;
	const Derived1 d1_2;
	const Derived1 d1_3;
	const Derived2 d2_1;
	const Derived2 d2_2;

	const std::array<const Base *, 5> data
	{
		&d1_1, &d1_2, &d1_3, &d2_1, &d2_2
	};

	int sum = 0;
	for (const auto *elem : data)
		sum += elem->get();
	return sum;
}

int main()
{
	constexpr auto v = getSomeValues();
	return v;
}
