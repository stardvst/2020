// functions
[[nodiscard]] int f()
{
	return 1;
}

// structs
struct [[nodiscard]] errorObj
{
};

errorObj g()
{
	return {};
}

// enums
enum [[nodiscard]] someEnum
{
	val1,
	val2
};

someEnum h()
{
	return {};
}

int main()
{
	f();
	g();
	h();
}