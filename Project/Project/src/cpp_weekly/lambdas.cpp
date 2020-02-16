#include <iostream>
#include <functional>
#include <type_traits>

template <typename ...L>
struct S : L...
{
	// to make it work with perfect forwarding
	template <typename ...T>
	S(T &&...ls)
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
S(T...)->S<std::decay_t<T>...>;

//template <typename L1, typename L2>
//auto makeCombined(L1 &&l1, L2 &&l2)
//{
//	return S<std::decay_t<L1>, std::decay_t<L2>>
//		(std::forward<L1>(l1), std::forward<L2>(l2));
//}

int main()
{
	auto l = []()
	{
		return 4;
	};

	auto l2 = [](int i)
	{
		return 10 * i;
	};

	// combined l(4), combined l()

	//auto combined = makeCombined(l, l2);

	// c++17 automatic class type deduction
	auto combined = S(l, l2,
		[](double d)
	{
		return d * 3.2;
	},
		// with use of forwarding passing non-copyable lambda
		[i = std::make_unique<int>(5)](char c)
	{
	});

	std::cout << combined() << '\n';
	std::cout << combined(4) << '\n';
	std::cout << combined(3.5) << '\n';
}