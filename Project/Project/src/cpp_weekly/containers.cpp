#include <string>
#include <set>

struct Person
{
	std::string name;
};

template <typename Type, typename Comparator>
auto makeSet(Comparator &&comparator)
{
	return std::set<Type, std::decay_t<Comparator>>{
		std::forward<Comparator>(comparator)};
}

template <typename Type, typename ...Comparator>
auto makeSetVar(Comparator &&...comparator)
{
	// need to expand parameter pack, inherit from all comparators
	struct Compare : std::decay_t<Comparator>...
	{
		// pull call operators from all comparators
		using std::decay_t<Comparator>::operator()...;
		using is_transparent = int;

		// cannot have member template in local class,
		// so we'll pass compare object to set ctor
		//template <typename ...T>
		//Compare(T &&...t)
		//{
		//}
	};
	return std::set<Type, Compare>{Compare{ std::forward<Comparator>(comparator)... }};
}

int main()
{
	auto comparator1 = [](const Person &lhs, const Person &rhs)
	{
		return lhs.name < rhs.name;
	};

	std::set<Person, decltype(comparator1)> set{ std::move(comparator1) };

	// make set
	auto set1 = makeSet<Person>([](const Person &lhs, const Person &rhs)
	{
		return lhs.name < rhs.name;
	});

	// make set variadic
	auto set2 = makeSetVar<Person>(
		[](const Person &lhs, const Person &rhs)
	{
		return lhs.name < rhs.name;
	},
		[](const Person &lhs, const auto &rhs)
	{
		return lhs.name < rhs;
	},
		[](const auto &lhs, const Person &rhs)
	{
		return lhs < rhs.name;
	});

	const auto count = set2.count("Bob");
}
