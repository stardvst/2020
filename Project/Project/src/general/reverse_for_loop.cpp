#include <iostream>
#include <vector>

template <typename T>
class reverse
{
public:
	explicit reverse(T &it)
		: iterable(it)
	{
	}

	auto begin() const
	{
		return std::rbegin(iterable);
	}

	auto end() const
	{
		return std::rend(iterable);
	}

private:
	T &iterable;
};

template <typename T>
class reverse_move
{
public:
	explicit reverse_move(T &&it)
		: iterable(std::move(it))
	{
	}

	auto begin() const
	{
		return std::rbegin(iterable);
	}

	auto end() const
	{
		return std::rend(iterable);
	}

private:
	T iterable;
};

auto createRange()
{
	return std::vector{ 3, 5, 7, 8 };
}

int main()
{
	std::vector vec{ 3, 5, 7, 8 };
	for (const auto &v : reverse(vec))
		std::cout << v << ' ';

	std::cout << '\n';
	for (const auto &v : reverse_move(createRange()))
		std::cout << v << ' ';
}