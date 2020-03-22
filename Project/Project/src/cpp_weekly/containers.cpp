#include <iostream>
#include <vector>

struct S
{
	S() { puts("S()"); }
	S(int) { puts("S(int)"); }
	~S() { puts("~S()"); }

	S(const S &) { puts("S(const S &)"); }
	S(S &&) noexcept { puts("S(S &&)"); }

	S &operator=(const S &)
	{
		puts("S &operator=(const S &)"); return *this;
	}

	S &operator=(S &&) noexcept
	{
		puts("S &operator=(S &&)"); return *this;
	}
};

int main()
{
	std::vector<S> vec;
	std::cout << "initial capacity: " << vec.capacity() << '\n';

	// S(int), S(&&), ~S(), ~S()
	// while moves are cheap, they're not as cheap as creating object in-place!
	//vec.push_back(S(1));

	// S(int), ~S()
	vec.emplace_back(3);
	std::cout << "capacity after emplace_back: " << vec.capacity() << '\n';

	// without noexcept, these will result in COPIES,
	// but with noexcept we're telling that objects can be moved
	// while maintaining strong exception guarantee!
	vec.emplace_back(3);
	std::cout << "capacity after emplace_back: " << vec.capacity() << '\n';
	vec.emplace_back(3);
	std::cout << "capacity after emplace_back: " << vec.capacity() << '\n';
	vec.emplace_back(3);
	std::cout << "capacity after emplace_back: " << vec.capacity() << '\n';
	vec.emplace_back(3);
	std::cout << "capacity after emplace_back: " << vec.capacity() << '\n';
}
