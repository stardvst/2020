#include <iostream>
#include <regex>

void dumpRegex(const std::cmatch &match)
{
	std::cout << "matches:\n";
	for (std::size_t i = 0; i < match.size(); ++i)
	{
		std::cout << i << ": " << match.str(i) << '\n';
	}
}

int main()
{
	// this is slower than without optimize flag;
	// regex and matches should be constructed only as needed,
	// i.e. should be outside for loop, const and maybe static
	std::regex rx(R"((\d+): \[([^\]]+)\] (.*))", std::regex::optimize);
	std::cmatch match;

	std::regex_match("123: [error] Hello World", match, rx);

	dumpRegex(match);
}