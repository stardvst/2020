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
	std::set<MyData, Compare> set;
	set.insert(MyData{ "Bob" });
}
