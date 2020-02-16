#include <iostream>
#include <functional>
#include <type_traits>
#include <variant>
#include <array>
#include <string>

template <typename ...L>
struct Visitor : L...
{
	// to make it work with perfect forwarding
	template <typename ...T>
	Visitor(T &&...ls)
		: L(std::forward<T>(ls))...
	{
	}

	// dispatch to appropriate operator() depending on what's passed
	// with this variadic using declaration
	using L::operator()...;
};

// constructor of S has different parameter pack than the struct
// and class template type deduction cannot work, so adding guide
// decay_t to get the underlying type, not & or && or whatever
template <typename ...T>
Visitor(T...)->Visitor<std::decay_t<T>...>;

//template <typename L1, typename L2>
//auto makeCombined(L1 &&l1, L2 &&l2)
//{
//	return S<std::decay_t<L1>, std::decay_t<L2>>
//		(std::forward<L1>(l1), std::forward<L2>(l2));
//}

int main()
{
	std::array<std::variant<double, int, char, std::string>, 3> vars{ 3.5, 2, "Hello World" };
	int intTotal = 0;
	double dblTotal = 0.0;

	Visitor visitor{
		[&intTotal](const int i)
	{
		intTotal += i;
	},
		[&dblTotal](const double d)
	{
		dblTotal += d;
	},
		[](const char c)
	{
	},
		[](const std::string &s)
	{
	}
	};

	std::for_each(std::begin(vars), std::end(vars),
		[&visitor](const auto &v)
	{
		std::visit(visitor, v);
	});

	std::cout << "int total: " << intTotal << '\n';
	std::cout << "double total: " << dblTotal << '\n';
}