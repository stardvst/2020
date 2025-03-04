#include <chaiscript/chaiscript.hpp>

std::string helloWorld(const std::string &t_name)
{
	return "Hello " + t_name + "!";
}

int main()
{
	chaiscript::ChaiScript chai;
	chai.add(chaiscript::fun(&helloWorld), "helloWorld");

	(void)chai.eval(R"(
		puts(helloWorld("World"));
	)");
}
