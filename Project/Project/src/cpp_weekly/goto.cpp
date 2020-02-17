#include <iostream>

int sumValsCont(const int num)
{
	int sum = 0;
	for (int i = 0; i <= num; ++i)
	{
		if (i == 0)
			continue;
		sum += i;
	}
	return sum;
}

// continue is defined in terms of goto...

int sumValsGoto(const int num)
{
	int sum = 0;
	for (int i = 0; i <= num; ++i)
	{
		{
			if (i == 0)
				goto contin;
			sum += i;
		}
	contin:
		;
	}
	return sum;
}

// for loops are defined in terms of while...

int sumValsWhile(const int num)
{
	int sum = 0;
	{
		int i = 0;
		while (i <= num)
		{
			{
				if (i == 0)
					goto contin;
				sum += i;
			}
		contin:
			++i;
		}
	}
	return sum;
}

// while loops are defined in terms of goto...

int sumValsWhileAsGoto(const int num)
{
	int sum = 0;

	{
		int i = 0;
	startWhile:
		{
			if (i <= num)
			{
				if (i == 0)
					goto contin;
				sum += i;
			contin:
				++i;
				goto startWhile;
			}
		}
	}
	return sum;
}

int main()
{
	std::cout << sumValsCont(100) << '\n';
	std::cout << sumValsGoto(100) << '\n';
	std::cout << sumValsWhile(100) << '\n';
	std::cout << sumValsWhileAsGoto(100) << '\n';
}