#include <algorithm>
#include <vector>
#include <memory>
#include <array>

// mainly bug-fixing, enhancements to c++11

// 1. auto return type deduction

template <typename T>
auto countThings(const T &vec, int value)
{
	// don't care what the return type is
	const auto count = std::count(begin(vec), end(vec));
	return count;
}

// 2. lambdas (generic)

template <typename T>
void countThingsLessThan3(const T &vec, int value)
{
	const auto count = std::count(begin(vec), end(vec),
		[](const auto i)
	{
		return i < 3;
	});
}

// 3. lambdas (generalized capture expression)

template <typename T>
void countThingsLessThan3Generalized(const T &vec, int value)
{
	const auto count = std::count(begin(vec), end(vec),
		[value = [] { return 3; }](const auto i)
	{
		return i < value;
	});
}

// 4. unique_ptr: make_unique, new/delete now no longer needed!

void allocMemory()
{
	auto ptr(std::make_unique<int>(5)); // RAII
} // ptr is destroyed, memory is freed

// 5. constexpr (loops, branches, multiple return statements),
// but cannot call non-constexpr functions

constexpr int getValue()
{
	int val1 = 5;
	int val2 = 3;
	return val1 * val2;
}

int main()
{
	constexpr auto value = getValue();
	std::array<int, value> values;
}
