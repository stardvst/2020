#include <iostream>
#include <string>

const std::string sEscapedDblQoute(R"(\")");
const char chSpace(' ');
const char chNewline('\n');

template <typename T>
std::string toString(const T &value)
{
	if constexpr (std::is_integral_v<T> || std::is_floating_point_v<T>)
	{
		return std::to_string(value);
	}
	else
	{
		std::string sValue(value);
		if (sValue.find_first_of(chSpace) != std::string::npos)
			return sEscapedDblQoute + sValue + sEscapedDblQoute;

		return value;
	}
}

template <typename ...T>
std::string stringify(const std::string &message, T...params)
{
	std::string result(message + chSpace);

	const auto concat = [&](auto &&input)
	{
		result += toString(input) + chSpace;
	};

	(concat(params), ...);

	result.back() = chNewline;
	return result;
}

template <typename ...T>
void print(const std::string &message, T ...params)
{
	std::cout << stringify(message, params...) << std::endl;
}

int main()
{
	print("open_dialog");
	print("execute", 1, 2, 3, 4);
	print("select", 1, "text with spaces");
	print("select", 1.4, "text with spaces");
}
