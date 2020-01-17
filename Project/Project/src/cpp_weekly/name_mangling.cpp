#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
#include <cxxabi.h>

struct A
{
	std::vector<std::string> m_data;
};

std::string demangle(const char *mangled_name)
{
	int status;
	char *demangled_name =
		abi::__cxa_demangle(typeid(&A::m_data).name(), nullptr, 0, &status);
	if (status == 0)
	{
		std::string retval(demangled_name);
		free(demangled_name);
		return retval;
	}

	throw std::runtime_error("Error demangling\n");
}

int main()
{
	A o;

	// msvc
	std::cout << typeid(&A::m_data).raw_name() << '\n'; // mangled
	std::cout << typeid(&A::m_data).name() << '\n'; // demangled

	// gcc
	std::cout << typeid(&A::m_data).name() << '\n'; // mangled
	std::cout << demangle(typeid(&A::m_data).name()) << '\n'; // demangled
}