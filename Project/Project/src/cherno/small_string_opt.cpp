#include <iostream>
#include <string>

// check out string header
// run program in debug and release modes

void *operator new(size_t size)
{
	std::cout << "allocating " << size << " bytes\n";
	return malloc(size);
}

int main()
{
	// small string (<=15): no heap allocation!
	std::string name = "Cherno";
	std::string name1 = "Cherno Small St";

	// this will cause heap allocation
	std::string name2 = "Cherno Small Str";
}