#include <iostream>
// a global variable std::cout is created

#include <cstdio>

int main(int, const char *argv[])
{
	// compiler instantiates operator<< that takes const char *
	// and another one that takes std::endl
	std::cout << "Hello World from std::cout" << std::endl;

	std::printf("Hello World from printf with newline\n"); // detects newline at the end and calls puts()
	std::printf("Hello World from printf"); // calls printf()
	std::printf("\n");

	std::puts("Hello World from puts"); // prints string with newline at end
	// but puts() requires null-terminated string, so can't be used with string_view

	// security risk (printf control characters may be passed)
	//std::printf(argv[1]);
	std::printf("%s\n", argv[0]); // safe
}
