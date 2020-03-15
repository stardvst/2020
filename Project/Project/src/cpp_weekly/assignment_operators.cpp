struct S
{
	// usual ones
	S &operator=(const S &) & = default;
	S &operator=(S &&) & = default;

	S &operator=(const S &&) & = delete; // move from const && has no meaning
	S &operator=(S &) & = default;

	// reference-qualified
	S &operator=(const S &) && = default;
	S &operator=(S &&) && = default;
	S &operator=(const S &&) && = delete;
	S &operator=(S &) && = default;

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
}
