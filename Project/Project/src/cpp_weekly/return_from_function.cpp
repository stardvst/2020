#include <iostream>

// wrong
std::string val1(const bool b)
{
	// constructs default
	std::string ret;

	// assigns to that
	if (b)
		ret = "Hello";
	else
		ret = "World";

	// returns it... not so optimal
	return ret;
}

// wrong
std::string val2(const bool b)
{
	// compiler needs to decide the length of const char *,
	// which will be used to init the returned string and also
	// set the length of string. if sizes differ, calls strlen()
	//return b ? "Hello" : "World";

	// better, returning string and compiler doesn't have to deduce
	// the length of const char *
	return b ? std::string("Hello") : std::string("World");
}

// correct!
std::string val3(const bool b)
{
	// compiler knows this is 5 character string which will be
	// used to init the returned string.
	// we now see the "Hello" encoded as 64-bit value in return
	// instead of string literal in binary!
	if (b)
		return "Hello";

	// this will have size 6
	return "World";
}

// wrong (in this case)
// if we know it's going to end up in string, return string.
// this call will again call memcpy, strlen, etc.
const char *val4(const bool b)
{
	if (b)
		return "Hello";
	return "World";
}

// wrong
// need to convert return value to string (no implicit conversion)
std::string_view val5(const bool b)
{
	if (b)
		return "Hello";
	return "World";
}

std::string getString(const bool b)
{
	return val4(b);
}

int main()
{
}
