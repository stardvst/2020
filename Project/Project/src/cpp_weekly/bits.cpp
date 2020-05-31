#include <iostream>
#include <bitset>
#include <bit> // c++20

int main()
{
	std::cout << std::bitset<32>(0).count() << '\n';
	std::cout << std::bitset<32>(1).count() << '\n';

	std::cout << std::popcount(3u) << '\n';

	std::uint8_t i = 0b00011101;
	std::cout << "i          = " << std::bitset<8>(i) << '\n';
	std::cout << "rotl(i,0)  = " << std::bitset<8>(std::rotl(i, 0)) << '\n';
	std::cout << "rotl(i,1)  = " << std::bitset<8>(std::rotl(i, 1)) << '\n';
}
