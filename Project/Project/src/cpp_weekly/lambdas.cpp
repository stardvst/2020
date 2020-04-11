#include <iostream>
#include <variant>
#include <type_traits>

template <typename ...Base>
struct Visitor : Base...
{
	// no need for ctor, no need to worry whether all bases are
	// move constructible, thanks to c++17 aggregate initialization
	// of base classes, and behavior is exactly the same
	// to make it work with perfect forwarding

	//template <typename ...T>
	//constexpr Visitor(T &&...t) noexcept(
	//	(std::is_nothrow_move_constructible_v<Base> && ...)
	//	) : Base{ std::forward<T>(t) }...
	//{
	//}

	// dispatch to appropriate operator() depending on what's passed
	// with this variadic using declaration
	using Base::operator()...;
};

// constructor of S has different parameter pack than the struct
// and class template type deduction cannot work, so adding guide
// decay_t to get the underlying type, not & or && or whatever
template <typename ...T>
Visitor(T...)->Visitor<T...>;

int main()
{
	constexpr Visitor visitor{
		[](double d) -> int { return d + 3.4; },
		[](int i) -> int { return i - 2; }
	};

	constexpr auto v = std::variant<double, int>{ 9.0 };
	std::cout << std::visit(visitor, v) << '\n';
}
