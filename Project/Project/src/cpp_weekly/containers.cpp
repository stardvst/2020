#include <string>
#include <set>

struct MyData
{
	std::string key;
	std::string value;
};

struct Compare
{
	bool operator()(const MyData &lhs, const MyData &rhs) const
	{
		return lhs.key < rhs.key;
	}

	// transparent comparator, i.e. doesn't have to compare with MyData,
	// can be any other type
	template <typename T>
	bool operator()(const MyData &lhs, const T &str) const
	{
		return lhs.key < str;
	}

	template <typename T>
	bool operator()(const T &str, const MyData &rhs) const
	{
		return str < rhs.key;
	}

	// activate transparent comparators
	using is_transparent = int;
};

int main()
{
	// error: lambda expression in template argument
	// argument expects type, but we passed value, so added decltype
	// but error is now about type instead of value
	//std::set < MyData, decltype([](const MyData &lhs, const MyData &rhs)
	//{
	//	return lhs.key < rhs.key;
	//}) > set;

	const auto lambda = [](const MyData & lhs, const MyData & rhs)
	{
		return lhs.key < rhs.key;
	};

	// cannot take type of lambda
	//const decltype(lambda) l2;
	//std::set<MyData, decltype(lambda)> set;

	// pass lambda to set constructor
	std::set<MyData, decltype(lambda)> set1(lambda);
	set1.insert(MyData{ "Bob" });

	// c++17
	std::set set2({ MyData{ "Bob" } }, // initializer list
		[](const MyData &lhs, const MyData &rhs) // comparator
	{
		return lhs.key < rhs.key;
	});

	std::set<MyData, Compare> set3;
	set3.insert(MyData{ "Bob" });

	const auto count1 = set3.count(MyData{ "Bob" }); // have to create an object

	// works only with overloads
 	auto count2 = set3.count(std::string("Bob"));
}
