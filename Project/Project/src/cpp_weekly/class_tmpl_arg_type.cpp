#include <tuple>
#include <functional>

namespace std
{
	template <typename Ret, typename Class, typename ...Args>
	function(Ret(Class::*)(Args...))->function<Ret(Class &, Args...)>;

	template <typename Ret, typename Class, typename ...Args>
	function(Ret(Class:: *)(Args...) const)->function<Ret(const Class &, Args...)>;
}

void test()
{
}

void test2(int, char)
{
}

struct myClass
{
	void member()
	{
	}

	void constMember() const
	{
	}
};

int main()
{
	// no deduction guide needed as standard provides one
	std::function f(&test);
	std::function f2(&test2);
	f2(1, 'a');

	// need custom deduction guides
	std::function m(&myClass::member);
	std::function cm(&myClass::constMember);
}