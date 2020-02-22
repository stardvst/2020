#include <iostream>
#include <iomanip>
#include <sstream>

int main()
{
	std::string str = "Say \"Hello World!\"";
	std::string out;

	std::cout << "original: " << str << '\n';

	std::stringstream ss;
	ss << std::quoted(str);

	std::cout << "stored as: " << ss.str() << '\n';

	ss >> std::quoted(out);
	std::cout << "written out: " << out << '\n';
}