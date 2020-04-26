#include <iostream>

// taking params by value, and copying into lambda
template <typename Callable, typename ...Param>
auto bindValues(Callable callable, Param ...params)
{
	/*return [=]()
	{
		return callable(params...);
	};*/

	//return [
	//	callable = std::move(callable),

	//	// syntax error : unexpected token '...', expected ','
	//	params = std::move(params)...
	//]()
	//{
	//	return callable(params...);
	//};

	return [
		cb = std::move(callable),
		...arg = std::move(params)
	]()
	{
		return cb(arg...);
	};
}

int add(int lhs, int rhs)
{
	return lhs + rhs;
}

int main()
{
	const auto bound = bindValues(add, 1, 3);
	std::cout << bound() << '\n';
}
