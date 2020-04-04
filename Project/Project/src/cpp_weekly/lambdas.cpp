#include <iostream>
#include <array>

int main()
{
	auto l = [i = 10]{ return i; };
	std::cout << l() << '\n';

	// lambda capture can be any expression
	// lambda is expression => capture can be lambda
	auto l2 = [i = [] { return 10; }]
	{
		return i;
	};

	// invoke lambda returned from lambda
	std::cout << l2()() << '\n';

	// capture type
	auto l3 = [i = []
	{
		struct S
		{
			int val = 10;
			S()
			{
				puts("S()");
			}
			S(const S &)
			{
				puts("S(const S &)");
			}
			~S()
			{
				puts("~S()");
			}
		};
		return S{};
	}()]
	{
		return i;
	};

	// lambda returns object
	//std::cout << l3().val << '\n';

	// lambdas are objects with lifetimes
	// copying lambda => copies all of its captures
	//auto l4 = l3;
}
