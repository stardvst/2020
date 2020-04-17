#include <iostream>

[[gnu::pure]] int square(int i);

int main(int argc, const char *[])
{
	// since squre() is pure, it will be called once, then multiplied by 2!
	std::cout << square(argc) + square(argc) << '\n';
}

