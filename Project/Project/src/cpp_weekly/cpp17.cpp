#include <iostream>
#include <memory>
#include <string_view>
#include <array>

// 1. guaranteed copy/move elision

auto factory()
{
	return std::make_unique<int>();
}

// 2. beginning constexpr support in std lib

// c++17: constexpr reference operator[](size_type pos);
// c++14: constexpr const_reference operator[](size_type pos) const;

// 3. `constexpr` lambdas

constexpr auto l = []() {};

// 4. string_view

constexpr std::string_view name = "Hello";

// 5. class template argument deduction

std::array<int, 5> data1{ 1, 2, 3, 4, 5 };
std::array data2{ 1, 2, 3, 4, 5 };

// 6. fold expressions
template <typename ...T>
auto add(const T &...param)
{
	return (param + ...);
}

// 7. structured bindings

std::pair values{ 1, 2 };
auto [f, s] = values;

// 8. if-init expressions

void g()
{
	if (auto [f, s] = values; f == 1)
		std::cout << "f == 1\n";
}

int main()
{
	// widget will be created in-place
	auto widget = factory();

	std::cout << add(1, 2, 3, 4, 5) << '\n';

	g();
}
