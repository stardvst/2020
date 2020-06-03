#include <iostream>
#include <regex>
#include <string_view>

bool isErrorString(std::string sv)
{
	return std::regex_match(sv.begin(), sv.end(), std::regex(".*ERROR.*"));
}

const std::regex errRx(".*ERROR.*");

bool isErrorStringSomewhatBetter(std::string sv)
{
	return std::regex_match(sv.begin(), sv.end(), errRx);
}

#include <ctre.hpp>

bool isErrorStringCompileTime(std::string sv)
{
	return ctre::match<".*ERROR.*">(sv).matched();
}

int main()
{
}
