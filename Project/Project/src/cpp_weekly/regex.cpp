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
	std::regex rx(R"((\d+): \[([^\]]+)\] (.*))");

	std::cmatch match;
	std::regex_match("123: [error] Hello World", match, rx);

	dumpRegex(match);
}