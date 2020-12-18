#include <iostream>
#include <typeinfo>

// valid since C++98
class Outer
{
	struct Inner {};
public:
	Inner get() { return Inner(); }
};

auto localClass()
{
	struct MyStruct{};
	MyStruct s;
	return s;
}

auto lambda()
{
	return []() {};
}

int main()
{
	const auto l = lambda();
	std::cout << typeid(l).name() << '\n';

	const auto s = localClass();
	std::cout << typeid(s).name() << '\n';

	Outer o;
	/*Outer::Inner */const auto i = o.get();
	std::cout << typeid(i).name() << '\n';
}
