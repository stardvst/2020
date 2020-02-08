#include <cassert>

int main(int /* argc */, [[maybe_unused]] const char *argv[])
{
	// argc is 100% unused

	[[maybe_unused]]  int i = 0; // unused in release build
	assert(i == 0);
}