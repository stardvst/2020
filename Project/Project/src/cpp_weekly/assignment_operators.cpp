#include <utility>

struct S
{
	// usual ones
	S &operator=(const S &) & = default;
	S &operator=(S &&) & = default;

	S &operator=(const S &&) & = delete; // move from const && has no meaning
	S &operator=(S &) & = default;

	// reference-qualified
	S &operator=(const S &) && = delete;
	S &operator=(S &&) && = delete;
	S &operator=(const S &&) && = delete;
	S &operator=(S &) && = delete;

	// const reference qualified, not allowed (cannot assign to const)
	S &operator=(const S &) const & = delete;
	S &operator=(S &&) const & = delete;
	S &operator=(const S &&) const & = delete;
	S &operator=(S &) const & = delete;
	S &operator=(const S &) const && = delete;
	S &operator=(S &&) const && = delete;
	S &operator=(const S &&) const && = delete;
	S &operator=(S &) const && = delete;
};

int main()
{
	//S{} = S{};

	S s1{};
	S s2{};
	s1 = s2;
	s1 = std::move(s2);

	// cannot move from const
	//const S s3;
	//s1 = std::move(s3);
}
