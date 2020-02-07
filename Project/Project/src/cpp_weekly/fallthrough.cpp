#include <iostream>

int main()
{
	auto n = 5;
	switch (n)
	{
		case 5:
			std::cout << n + 1 << '\n';
			[[fallthrough]];
		case 2:
			std::cout << n + 2 << '\n';
			break;
	}

	// prints 67
}