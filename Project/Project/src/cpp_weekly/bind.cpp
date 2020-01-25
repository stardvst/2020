#include <iostream>
#include <functional>

void print(const int &i)
{
	std::cout << i << '\n';
}

void printStr(int i, const std::string &s)
{
	std::cout << i << ' ' << s << '\n';
}

template <typename T>
void printTemplate(T i, const std::string &s)
{
	std::cout << i << ' ' << s << '\n';
}

int main()
{
	int i = 5;
	const auto f = std::bind(&print, i);
	f();
	i = 6;
	f(); // prints 5, bind copies arguments

	i = 5;
	const auto fref = std::bind(&print, std::ref(i));
	fref();
	i = 6;
	fref(); // prints 6

	i = 5;
	const auto defer = std::bind(&printStr, std::ref(i), std::placeholders::_1);
	defer("hello");
	i = 6;
	defer("world");

	// swallows extra parameters
	defer("string", 1, 2, 3, 4);

	// bind template function
	const auto fTemplate = std::bind(&printTemplate<int>, std::placeholders::_2, std::placeholders::_1);
	fTemplate("hello world", 7);

	// create a wrapper
	std::function<void(const std::string &, int)> wrapper(fTemplate);
	wrapper("hello world", 8);

	// cannot do with function, it requires all params to match!
	//wrapper("hello world", 8, 9, 10);
}