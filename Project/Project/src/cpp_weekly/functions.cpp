#include <iostream>

template <typename Func>
auto useFunc(Func obj)
{
	return obj();
}

// is a function, callable thing, but not a function object,
// which is an abject having operator()
int func()
{
	return 0;
}

// requires requires: define ad-hoc concept
template <typename FuncObj>
auto useFuncObj(FuncObj obj) requires requires { &FuncObj::operator(); }
{
	return obj();
}

// or, better
template <typename T>
concept hasCallOperator = requires { &T::operator(); };

template <typename FuncObj>
auto useFuncObjCon(FuncObj obj) requires hasCallOperator<FuncObj>
{
	return obj();
}

int main()
{
	useFunc([]() {});
	useFunc(func);

	useFuncObj([]() {});
	//useFuncObj(func);
	useFuncObjCon([]() {});
	//useFuncObjCon(func);
}
