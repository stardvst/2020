#include <random>
#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <future>

std::set<int> makeSortedRandom(const int nElements)
{
	std::set<int> setResult;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, nElements - 1);

	std::generate_n(std::inserter(setResult, setResult.end()), nElements,
		[&]()
	{
		return dis(gen);
	});

//	throw std::runtime_error("Hello World");

	return setResult;
}

int main()
{
	// how many unique?
	//std::cout << makeSortedRandom(1000000).size() << '\n';

	// compare two calls
	//std::cout << makeSortedRandom(1000000).size() << ' ' << makeSortedRandom(1000000).size() << '\n

	// still same as above... why?
	//std::cout << std::async(makeSortedRandom, 1000000).get().size() << ' ' << std::async(makeSortedRandom, 1000000).get().size() << '\n';

	auto f1 = std::async(std::launch::async, makeSortedRandom, 1000000);
	auto f2 = std::async(std::launch::async, makeSortedRandom, 1000000);

	try
	{
		std::cout << f1.get().size() << '\n';
	}
	catch (const std::exception &ex)
	{
		std::cout << "Threw: " << ex.what() << '\n';
	}

	std::cout << f2.get().size() << '\n';
}