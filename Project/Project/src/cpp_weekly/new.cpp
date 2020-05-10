#include <vector>
#include <string>

// we can allocate with new
// we must free allocated memory in constexpr context
// we must not access freed memory

constexpr auto get1()
{
	return new int;
}

constexpr auto get2()
{
	auto i = new int{ 5 };
	delete i;
	return 4;
}

constexpr auto get3()
{
	auto i = new int{ 5 };
	return *i;
}

constexpr auto getPtr()
{
	auto i = new int{ 5 };
	return i;
}

constexpr auto dereferenceDelete()
{
	auto ptr = getPtr();
	auto value = *ptr;
	delete ptr;
	return value;
}

constexpr auto dereferenceDeleteFMR()
{
	auto ptr = getPtr();
	delete ptr;
	auto value = *ptr;
	return value;
}

// 'std::vector<int>' is not literal, yet
//constexpr auto getVector()
//{
//    return std::vector<int>{};
//}

int main()
{
	auto value1 = get1();

	// can do new/delete in constexpr context, BUT
	// cannot have constexpr with get1() because cannot let pointer
	// escape from compile time context
	constexpr auto value2 = get2();

	// error: 'get3()' is not a constant expression because
	// allocated storage has not been deallocated
	// constexpr auto value3 = get3();

	constexpr auto value4 = dereferenceDelete();

	// compile time FMR detection!
	// use of allocated storage after deallocation in a constant expression
	//constexpr auto value5 = dereferenceDeleteFMR();
}
