#include <iostream>
#include <string>

std::size_t length(const std::string &s)
{
	return s.size();
}

std::size_t length_view(const std::string_view &s)
{
	return s.size();
}

int main()
{
	// creates string, but do we it to?
	std::cout << length("long string, really...") << '\n';

	// constructs string_view, no allocation, plus it's constexpr
	constexpr auto v = std::string_view("long string, really...");
	std::cout << length_view(v) << '\n';
}