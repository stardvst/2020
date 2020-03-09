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
}
