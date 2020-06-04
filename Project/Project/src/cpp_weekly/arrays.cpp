#include <iostream>
#include <array>
#include <typeinfo>

int main()
{
	const int data[3] = { 1, 2, 3 };
	const auto dArray = std::to_array(data);
	std::cout << typeid(dArray).name() << '\n';

	// fails because type of str is const char * (arrays decay to pointers)
	/*const auto str = "Hello world";
	const auto sArray1 = std::to_array(str);*/

	// type is const char[]
	const auto sArray2 = std::to_array("Hello world");
	std::cout << typeid(sArray2).name() << '\n';
}
