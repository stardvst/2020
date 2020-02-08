struct Lambda
{
	auto operator()() const
	{
		return 5;
	}
};

int main()
{
	// without -Ox, clang generates more code than gcc
	return[]
	{
		return 5;
	}();

	// return Lambda()();
}