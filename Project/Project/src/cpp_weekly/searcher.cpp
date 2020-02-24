#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	std::string s = "some rather long string";
	std::string toFind = "ath";

	// naive search
	auto foundAt = std::search(s.begin(), s.end(),
		toFind.begin(), toFind.end());
	std::cout << std::distance(s.begin(), foundAt) << '\n'; // 6

	// more efficient
	foundAt = std::search(s.begin(), s.end(),
		std::boyer_moore_searcher(toFind.begin(), toFind.end()));
	std::cout << std::distance(s.begin(), foundAt) << '\n'; // 6
}