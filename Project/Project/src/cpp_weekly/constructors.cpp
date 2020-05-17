struct S
{
	// any ctor can be explicit
	/*explicit*/ S() = default;

	explicit S(int, int)
	{
	}

	S(int)
	{
	}
};

void f(const S &)
{
}

S get()
{
	// cannot do if default ctor is explicit
	//return {};
	return S{};
}

S getOther()
{
	// cannot do if S(int, int) is explicit
	//return { 2, 3 };
	return S{ 2, 3 };
}

int main()
{
	//f(10);

	f(S{ 10 });
	f(static_cast<S>(10));

	// default construct the parameter, but if default ctor is explicit, we'll get an error:
	// 'void f(const S &)': cannot convert argument 1 from 'initializer list' to 'const S &'
	f({});
}
