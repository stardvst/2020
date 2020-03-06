#include <string>

// compile with:
// 1. g++ sanitize.cpp -g -fsanitize=address
// ./a.out
// 2. clang++-6.0 sanitize.cpp -fsanitize=address -g
// ASAN_SYMBOLIZER_PATH=/usr/lib/llvm-6.0/bin/llvm-symbolizer ./a.out

int main()
{
	const char *names[] = { "bob", "fred" };
	std::string lastArg = names[3];
	return lastArg.size();
}
