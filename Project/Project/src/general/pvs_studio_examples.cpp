// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>

int *get()
{
	return nullptr;
}

int main()
{
	// V547 Expression 'p' is always false.
	auto p = get();
	if (p)
	{

	}

	const auto width = 860, height = 640;
	for (auto i = 0; i < width; ++i)
	{
		// V654 The condition 'j < height' of loop is always true.
		// V533 It is likely that a wrong variable is being incremented inside the
		// 'for' operator. Consider reviewing 'i'.
		for (auto j = 0; j < height; ++i)
		{

		}
	}

	// V575 The 'memcpy' function doesn't copy the whole string.
	// Use 'strcpy / strcpy_s' function to preserve terminal null.
	const char *str = "Hello";
	auto arr = new char[strlen(str)];
	memcpy(arr, str, strlen(str));
}
