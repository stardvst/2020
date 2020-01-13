#include <iostream>
#include <vector>
#include <sstream>

template <typename T>
std::string toStringImpl(const T &param)
{
	std::stringstream ss;
	ss << param;
	return ss.str();
}

std::vector<std::string> toString()
{
	return {};
}

template <typename T, typename ...Args>
std::vector<std::string> toString(const T &param, const Args &...args)
{
	std::vector<std::string> v;
	v.push_back(toStringImpl(param));

	const auto remainder = toString(args...);
	v.insert(v.end(), remainder.begin(), remainder.end());

	return v;
}

template <typename ...Args>
std::vector<std::string> toStringMid(const Args &...args)
{
	// generic lambda
	const auto toStrimgImplMid = [](const auto &t)
	{
		std::stringstream ss;
		ss << t;
		return ss.str();
	};
	return { toStrimgImplMid(args)... };
}

template <typename ...Args>
std::vector<std::string> toStringBetter(const Args &...args)
{
	return { toStringImpl(args)... };
}

int main()
{
	auto vec = toString("hello", 1, 5.3, 1.3f, 1, 2, 3, "world");
	vec = toStringMid("hello", 1, 5.3, 1.3f, 1, 2, 3, "world");
	vec = toStringBetter("hello", 1, 5.3, 1.3f, 1, 2, 3, "world");
	for (const auto &v : vec)
		std::cout << v << '\n';
}