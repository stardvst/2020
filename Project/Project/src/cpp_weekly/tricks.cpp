#include <iostream>
#include <vector>

struct S
{
	int i;

	// more code with string
	//std::string s;

	// when dtor is declared, move operations are implicitly
	// deleted, so copy will be used, more operations are generated
	//~S();
};

//S::~S()
//{
//	i = 0;
//}

int main()
{
	std::vector<S> vec;
	vec.emplace_back();
	vec.emplace_back();
}
