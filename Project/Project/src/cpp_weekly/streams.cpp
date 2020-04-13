#include <iostream>

int main()
{
	std::cout << "Hello World\n"; // may not be flushed...

	std::cerr << "Hello World\n"; // WILL be flushed, cerr is unbuffered error stream
	std::clog << "Hello World\n"; // may not be flushed, clog is buffered error stream
}
