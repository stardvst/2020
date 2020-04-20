#include <cstdio>

struct S
{
	S(const bool b)
		: value(b)
	{
	}

	bool value;
};

bool getBool(const bool b)
{
	puts("getBool()");
	return b;
}

S makeS(const bool b)
{
	puts("makeS()");
	return S(b);
}

bool operator||(const S &lhs, const S &rhs)
{
	return lhs.value || rhs.value;
}

bool operator&&(const S &lhs, const S &rhs)
{
	return lhs.value && rhs.value;
}

int main()
{
	// only first is called
	getBool(true) || getBool(false);
	puts("---");

	// both are called - weird!
	makeS(true) || makeS(false);
	puts("---");

	// only 1st and 2nd are called!
	getBool(true) && (getBool(true) || getBool(false));
	puts("---");

	// all are called - weird!
	makeS(true) && (makeS(true) || makeS(false));
}
