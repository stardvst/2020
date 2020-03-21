#include <vector>

//int sum(const std::vector<int> &vec)
//{
//	int result = 0;
//	for (std::size_t pos = 0; pos < vec.size(); ++pos)
//		result += vec[pos];
//	return result;
//}

auto sum(const std::vector<int> &vec) -> int
{
	int result = 0;
	for (int pos : vec)
	{
		result += pos;
	}
	return result;
}

auto main() -> int
{
	//int *p1 = NULL;
	//int *p2 = 0;

	int *p1 = nullptr;
	int *p2 = nullptr;

	//if (!p1 && !p2)
	if ((p1 == nullptr) && (p2 == nullptr))
	{
		return 0;
	}
}
