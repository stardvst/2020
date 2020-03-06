#include <iostream>

// clang++-6.0 sanitize.cpp -g -fsanitize=memory -fsanitize-memory-track-origins
// MSAN_SYMBOLIZER_PATH=/usr/lib/llvm-6.0/bin/llvm-symbolizer ./a.out

void setValue(bool &b, int value)
{
	if (value > 1)
		b = false;
}

int main(int argc, const char *[])
{
	bool b;
	setValue(b, argc);
	if (b)
		std::cout << "value set\n";
}
