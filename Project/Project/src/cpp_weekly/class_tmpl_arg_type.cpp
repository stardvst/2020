#include <tuple>
#include <string>
#include <utility>

std::pair<std::string, std::string> getStrings();

int main()
{
	// fine
	// without assigning same code will be generated
	// (compiler has do do cleanup created strings)
	const auto s = getStrings();

	// inefficient code is generated
	// with deduction guide, implicitly converts pair to tuple... oops!
	const std::tuple t = getStrings();

	// fine
	const std::pair p = getStrings();
}
