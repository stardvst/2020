#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

int addLocalOld(std::map<std::string, int> vars, const std::string &varName)
{
	std::pair<std::map<std::string, int>::iterator, bool> newVar =
		vars.insert(std::make_pair(varName, 0));

	// inserted?
	if (!newVar.second)
		throw std::runtime_error("variable already exists");

	// return new pair's second value, i.e. 0
	return newVar.first->second;
}

int addLocalNew(std::map<std::string, int> vars, const std::string &varName)
{
	if (auto [itr, bSuccess] =
		vars.insert(std::make_pair(varName, 0));
		bSuccess == false)
	{
		throw std::runtime_error("variable already exists");
	}
	else
	{
		// return itr->second;
		auto [key, value] = *itr;
		return value;
	}
}

struct S
{
	int i = 4;
	int j = 5;
};

int main()
{
	std::map<std::string, int> locals;

	int it = addLocalOld(locals, "myVar1");
	std::cout << it << '\n';

	it = addLocalNew(locals, "myVar2");
	std::cout << it << '\n';

	S s;
	auto [i, j] = s;
	std::cout << i << ' ' << j << '\n';
}
