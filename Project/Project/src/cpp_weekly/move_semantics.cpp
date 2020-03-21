#include <iostream>

struct S
{
	S() = default;

	// delete this constructor!
	S(const S &&) = delete;
	S &operator=(const S &&) = delete;
};

int main()
{
	S s1;

	S s2 = std::move(s1); // copy instead of move, so disable

	S s3;
	s3 = std::move(s1);
}
