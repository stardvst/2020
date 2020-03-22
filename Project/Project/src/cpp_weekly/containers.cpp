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

	// S(int), S(&&), ~S(), ~S()
	// while moves are cheap, they're not as cheap as creating object in-place!
	//vec.push_back(S(1));

	// S(int), ~S()
	vec.emplace_back(3);
}
