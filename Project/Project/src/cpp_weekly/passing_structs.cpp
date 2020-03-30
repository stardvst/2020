#include <cstdint>

struct ints
{
	std::uint8_t i1;
	std::uint8_t i2;
	std::uint8_t i3;
	std::uint8_t i4;
};

void useVals(std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t,
	std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t)
{
}

void useVals(ints, ints)
{
}

void callViaInts()
{
	// uses 8 registers to pass params
	// no more registers, pushes to stack
	useVals(1, 2, 3, 4, 1, 2, 3, 4);
}

void callViaStructs()
{
	// one move for each param, one thing being passed, stored in 1 32-bit register
	useVals(ints{ 1, 2, 3, 4 }, ints{ 1, 2, 3, 4 });
}

int main()
{
}
