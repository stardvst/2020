#include <iostream>
#include <string>

int main()
{
	// error
	//std::cout << "Hello

	//	World" << '\n';

	std::cout << R"(Hello"

		"World)" << '\n';

	// to have "s inside raw string, enclose it in expression
	std::cout << R"stuff("Hello" "World")stuff" << '\n';
}
