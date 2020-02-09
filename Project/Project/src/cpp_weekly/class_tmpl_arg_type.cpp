#include <tuple>
#include <functional>

void test()
{
}

int main()
{
	// pre-c++17
	std::tuple<int, int> t1(1, 2);
	const auto t2 = std::make_tuple(3, 4);

	// c++17
	std::tuple t3(5, 6);
	std::tuple t4([](){}, [](){});

	// compile error: mismatched set of types
	//return t3 == t4;

	std::function f(&test);
}