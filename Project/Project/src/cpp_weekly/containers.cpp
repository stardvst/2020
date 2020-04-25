#include <iostream>
#include <vector>

void remove5s(std::vector<int> &vec, std::list<int> &lst)
{
	//vec.erase(std::remove(begin(vec), end(vec), 5), end(vec));
	std::erase(vec, 5);
	std::erase(lst, 5);
}

int main()
{
}
