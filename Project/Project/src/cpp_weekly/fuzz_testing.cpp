#include <iostream>

// g++ fuzz_testing.cpp -fsanitize=address -g
// ./a.out -> crash!

std::size_t findNewlineBad(const char *str)
{
	// what if string doesn't have a newline?
	// but what if all tests DO HAVE newline in them?
	// => fuzzy testing to the rescue!
	std::size_t loc = 0;
	while (str[loc] != '\n')
		++loc;
	return loc;
}

std::size_t findNewlineGood(const char *str, const std::size_t size)
{
	// take into account string size too
	std::size_t loc = 0;
	while (loc < size && str[loc] != '\n')
		++loc;
	return loc;
}

// fuzz testing
// 1. add this declaration
// 2. clang++-6.0 fuzz_testing.cpp -fsanitize=address,fuzzer -g
// 3. ./a.out
// crash* file is generated for findNewlineBad, containing empty string
// for findNewlineGood, to this to see to see what is generated
// mkdir CORPUS && ./a.out CORPUS
extern "C" int LLVMFuzzerTestOneInput(const uint8_t * Data, size_t Size)
{
	//findNewlineBad(reinterpret_cast<const char *>(Data));
	findNewlineGood(reinterpret_cast<const char *>(Data), Size);
	return 0;  // Non-zero return values are reserved for future use.
}

//
//int main()
//{
//	std::cout << findNewline("Hello\n");
//}
