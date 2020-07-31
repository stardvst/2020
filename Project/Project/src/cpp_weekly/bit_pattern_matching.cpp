#include <cstdint>
#include <stdexcept>

class BitPattern
{
private:
	// input & mask = expected

	// expected result after masking
	std::uint64_t expected{};

	// set of bits to match
	std::uint64_t mask{0xFFFFFFFFFFFFFFFF};

public:
	// if passed without size, would decay to pointer
	template <std::size_t TSize>
	explicit constexpr BitPattern(const char(&input)[TSize])
	{
		std::uint64_t currBit = (1 << (TSize - 2));
		for (const char val : input)
		{
			if (val == 0)
				return;

			if (val == '1')
				expected |= currBit;
			else if (val == 'x' || val == 'X')
			{
				// currBit = 000010, ~currBit = 111101
				// mask = 110111, mask & ~currBit = 110111 & 111101 = 110101
				mask &= ~currBit;
			}
			else if (val != 0)
			{
				throw std::logic_error("Unknown character");
			}

			currBit >>= 1;
		}
	}

	constexpr friend bool operator==(const std::uint64_t val, const BitPattern &bp)
	{
		return (val & bp.mask) == bp.expected;
	}
};

int main()
{
	static_assert(0b1101010 == BitPattern("11XXX10"));
}
