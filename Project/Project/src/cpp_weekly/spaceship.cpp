#include <set>
#include <compare>

struct A
{
	int i;
	int j;

	//bool operator<(const A &a) const
	//{
	//	return i < a.i || j < a.i;
	//}

	// this will define all comparison operators!
	// a1 == a2, a1 < a2, a1 <= a2...
	auto operator<=>(const A &) const = default;
};

int main()
{
	std::set<A> set;
	set.insert({ 1, 2 });
}
