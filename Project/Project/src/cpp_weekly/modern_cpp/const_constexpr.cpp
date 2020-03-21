#include <memory>

struct Type
{
	// use a trailing return type for this function
	//int f() { return data + 4; }
	[[nodiscard]] constexpr auto f() const -> int { return data + 4; }

private:
	int data{};
};

auto main(int argc, const char * /*argv*/[]) -> int
{
	Type obj;

	// if with identical then and else branches
	if (argc > 1)
	{
		if (obj.f() == 0)
		{
			return -1;
		}
	}
	//else
		//obj.f();

	// consider replacing 'long' with 'int32'
	//if constexpr (sizeof(long) > 4)
	if constexpr (sizeof(int32_t) > 4)
	{
		return 0;
	}
}
