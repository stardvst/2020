#include <pipes/pipes.hpp>
#include <vector>
#include <iostream>

int main()
{
	const auto source = std::vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto destination = std::vector<int>{};

	source
		>>= pipes::filter([](const int i) { return i % 2 == 0; })
		>>= pipes::transform([](const int i) { return i * 2; })
		>>= pipes::push_back(destination);

	for (const auto &v : destination)
		std::cout << v << ' ';
}
