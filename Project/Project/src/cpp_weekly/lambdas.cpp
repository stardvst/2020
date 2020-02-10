#include <iostream>
#include <functional>
#include <type_traits>

template <typename L1, typename L2>
struct S : L1, L2
{
	S(L1 l1, L2 l2)
		: L1(std::move(l1))
		, L2(std::move(l2))
	{
	}

	// dispatch to appropriate operator() depending on what's passed
	using L1::operator();
	using L2::operator();
};

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
	auto combined = S(l, l2);

	std::cout << combined() << '\n';
	std::cout << combined(4) << '\n';
}