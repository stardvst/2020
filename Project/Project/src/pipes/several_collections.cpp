#include <pipes/pipes.hpp>
#include <iostream>

int main()
{
	const auto input1 = std::vector<int>{ 1, 2, 3, 4, 5 };
	const auto input2 = std::vector<int>{ 10, 20, 30, 40, 50 };

	auto results = std::vector<int>{};

	pipes::mux(input1, input2)
		>>= pipes::filter([](const int a, const int b) { return a + b < 40; })
		>>= pipes::transform([](const int a, const int b) { return a * b; })
		>>= pipes::push_back(results);

	for (const auto &v : results)
		std::cout << v << ' ';
}
