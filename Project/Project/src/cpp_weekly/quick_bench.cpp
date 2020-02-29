#include <string>

void f(int val)
{
	std::string str;

	switch (val)
	{
		case 0:
			str = "0";
			break;
		case 1:
			str = "1";
			break;
		case 2:
			str = "2";
			break;
		default:
			str = "other";
			break;
	}
}

void g(int val)
{
	const std::string str = [&]() -> std::string // will make faster
	{
		switch (val)
		{
			case 0:
				return "0";
				return "a rather long strong, not small"; // slower
			case 1:
				return "1";
				return "a rather long strong, not small"; // slower
			case 2:
				return "2";
				return "a rather long strong, not small"; // slower
			default:
				return "other";
		}
	}();
}

int main()
{
}