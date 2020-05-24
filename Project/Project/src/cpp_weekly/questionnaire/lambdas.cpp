#include <vector>

// #1. reasons for wanting lambda to function pointer conversion

// 1. use in place of c function pointer
extern "C" {
	void useCallback(int (*)(int))
	{
	}
}

void func()
{
	useCallback([](int i)
	{
		return i + 2;
	});
}

// 2. avoid overhead of std::function
void useFunctions()
{
	std::vector<int(*)(int, int)> vec;
	vec.push_back([](int i, int j)
	{
		return i + j;
	});
	vec.push_back([](int i, int j)
	{
		return i * j;
	});
}

// #2. practical applications of inheriting from lambdas

// 1. direct access to operator()()

// #3. implement this in c++98:
// [n0 = 0, n1 = 1]() mutable { n0 = std::exchange(n1, n0 + n1); return n0; }

struct Fib
{
	int n0;
	int n1;

	int operator()() /*const*/
	{
		//n0 = std::exchange(n1, n0 + n1);
		const int oldN1 = n1;
		n1 = n0 + n1;
		n0 = oldN1;
		return n0;
	}
};

int main()
{
}
