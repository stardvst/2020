#include <memory>

// if ctor acquires resources, make it nodiscard

struct [[nodiscard]] S
{
	[[nodiscard]] S(int)
	{
	}
};

S get()
{
	return S{ 5 };
}

int main()
{
	//S{ 5 };

	// warning C4834: discarding return value of function with 'nodiscard' attribute
	get(); // no warning if type itself isn't 'nodiscard'

	// warning C4834: discarding return value of function with 'nodiscard' attribute
	std::make_unique<int>( 5 );
}
