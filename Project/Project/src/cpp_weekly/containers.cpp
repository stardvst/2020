#include <iostream>
#include <set>

bool hasData(const std::set<int> &s)
{
	//return s.count(4) > 0;
	return s.contains(4);
}

bool hasDataMulti(const std::multiset<int> &ms)
{
	//return ms.count(4) > 0; // more costly calculation
	return ms.contains(4);
}

int main()
{
}
