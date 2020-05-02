#include <algorithm>
#include <vector>
#include <memory>
#include <array>

// 1. auto

template <typename T>
void countThings(const T &vec, int value)
{
	// don't care what the return type is
	const auto count = std::count(begin(vec), end(vec));
}

// 2. ranged-for loop

void doThings(const std::vector<int> &vec, int value)
{
	// c++98
	for (std::vector<int>::const_iterator it = vec.begin();
		it != vec.end();
		++it)
	{
		// do things with *it
	}

	// c++11
	for (const auto &elem : vec)
	{
		// do things with *it
	}
}

// 3. lambdas (limited)

template <typename T>
void countThingsLessThan3(const T &vec, int value)
{
	const auto count = std::count(begin(vec), end(vec),
		[](int i)
	{
		return i < 3;
	});
}

// 4. variadic templates (limited)

template <typename Func, typename ...T>
void call(const Func &func, const T &...params)
{
	func(params...);
}

// 5. unique_ptr

void allocMemory()
{
	std::unique_ptr<int> ptr(new int(5)); // RAII
} // ptr is destroyed, memory is freed

// 6. constexpr (limited)

constexpr int getValue()
{
	return 5 * 3;
}

int main()
{
	constexpr auto value = getValue();
	std::array<int, value> values;
}
