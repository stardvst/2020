#include <iostream>

// suppress "unary minus operator applied to unsigned type result still unsigned"
#pragma warning (disable : 4146)

auto val()
{
	// 0b11111111111111111111111111111111
	// 0b00000000000000000000000000000000
	// 0b00000000000000000000000000000001
	return -0xFFFFFFFF;
}

int main()
{
	std::cout << val() << '\n';

	static_assert(-0xFFFFFFFF == 1); // hex
	static_assert(std::is_same_v<decltype(val()), uint32_t>); // type
	static_assert(-4294967295u == 1); // dec
}