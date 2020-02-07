#include <vector>
#include <list>

int main()
{
	std::vector<std::vector<int>> v;

	//v.push_back(std::vector<int>());
	v.emplace_back(3, 1); // vector of 3 1s

	auto &vec = v.back();
	vec.push_back(4);

	// or
	auto &newVec = v.emplace_back(2, 4);
	newVec.push_back(4);

	// or
	v.emplace_back(2, 6).push_back(7);

	std::list<int> l;
	l.emplace_front(2);
}