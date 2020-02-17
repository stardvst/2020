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
	std::array<std::variant<double, int>, 2> vars{ 3.5, 2 };
	int intTotal = 0;
	double dblTotal = 0.0;
	std::common_type_t<decltype(intTotal), decltype(dblTotal)> grandTotal = 0;

	// there's no way to share variables between lambdas other than capturing
	Visitor visitor{
		[&intTotal, &grandTotal](const int i)
	{
		intTotal += i;
		grandTotal += i;
	},
		[&dblTotal, &grandTotal](const double d)
	{
		dblTotal += d;
		grandTotal += d;
	}
	};

	auto genericVisitor = [&intTotal, &dblTotal, &grandTotal](const auto &v)
	{
		grandTotal += v;

		if constexpr (std::is_same_v<std::decay_t<decltype(v)>, double>)
			dblTotal += v;
		else
			intTotal += v;
	};

	std::for_each(std::begin(vars), std::end(vars),
		[&genericVisitor](const auto &v)
	{
		std::visit(genericVisitor, v);
	});

	std::cout << "int total: " << intTotal << '\n';
	std::cout << "double total: " << dblTotal << '\n';
	std::cout << "grand total: " << grandTotal << '\n';
}