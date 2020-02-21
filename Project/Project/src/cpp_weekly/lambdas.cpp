#include <iostream>
#include <utility>

int main()
{
	auto fib = [a = 0, b = 1]() mutable
	{
		struct Results
		{
			int &a;
			int &b;

			Results next(int times = 1)
			{
				while (times--)
				{
					a = std::exchange(b, a + b);
					return *this;
				}
			}

			operator int()
			{
				return a;
			}
		};

		return Results{ a, b }.next();
	};

	std::cout << fib()/*.a*/ << '\n';
	std::cout << fib()/*.a*/ << '\n';
	std::cout << fib()/*.a*/ << '\n';
	std::cout << fib()/*.a*/ << '\n';

	// ++
	std::cout << fib().next()/*.a*/ << '\n';

	std::cout << fib().next(3)/*.a*/ << '\n';
}
