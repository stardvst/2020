#include <string>
#include <set>

struct Person
{
	std::string name;
};

int main()
{
	// lambdas can be converted into function pointers
	// it must be non-capturing lambda (which has state)
	using fp = bool(*)(const Person & lhs, const Person & rhs);

	std::set<Person, fp> set{ [](const Person &lhs, const Person &rhs)
	{
		return lhs.name < rhs.name;
	} };
}
