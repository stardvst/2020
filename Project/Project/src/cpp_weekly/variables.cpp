#include <iostream>

int f(int param)
{
	int i = param;
	int sum = 0;

	// define new variable
	for (int i = param; i > 0; --i)
	{
		int sum = 5; // define new variable
		sum += i; // adds i to sum local to for loop, oops
	}

	return sum;
}

int main()
{
	std::cout << f(5) << '\n'; // 0
}
