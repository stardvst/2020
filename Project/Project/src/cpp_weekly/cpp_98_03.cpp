// #1 C++ is an international standard, ISO
// C++98 1998, C++03 2003

// #2 Deterministic object lifetime, AKA RAII

#include <string>

void useString()
{
	{
		std::string s1("Hello World 1"); // s1 is created here
		std::string s2("Hello World 2"); // s2 is created here
	} // s2 is destroyed here, s1 is destroyed here

	// s1.size()
}

// #3 Destructors (to make RAII possible)

struct type
{
	type() : ptr(new int(5))
	{
	}

	~type()
	{
		delete ptr;
	}

	int *ptr;
};

void useType()
{
	type obj;
} // obj goes out of scope, destructor called

// #4 Templates (STL, algorithms, containers)

template <typename First, typename Second>
struct pair
{
	First i;
	Second j;
};

#include <vector>

void usePair()
{
	pair<int, double> p;
	std::vector<pair<double, int>> vec;
}

int main()
{
}
