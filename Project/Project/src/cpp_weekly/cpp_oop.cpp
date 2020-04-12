#include <iostream>

struct S
{
	int data_uninit;
	int data_init{};

	int get_uninit()
	{
		return data_uninit;
	}

	int get_init()
	{
		return data_init;
	}
};

// feature of procedural programming languages
int add_free(const int i, const int j)
{
	return i + j;
}

// feature of generic programming languages
template <typename T>
T add_template(const T i, const T j)
{
	return i + j;
}

// feature of functional programming languages
auto add_lambda = [](const int i, const int j)
{
	return i + j;
};

// can pass functions around
template <typename T>
auto call(const T &func)
{
	return func(1, 2);
}

int main()
{
	std::cout << call(add_lambda) << '\n';

	S s;
	// main is not returning any value, since it is un-inited
	//return s.get_uninit();
	// okay
	return s.get_init();
}
