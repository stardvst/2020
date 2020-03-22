#include <iostream>

#include "app.h"

int main(int argc, char **argv)
{
	std::vector<std::string> args(argv + 1, argv + argc);
	if (args.empty())
		args.emplace_back("db.txt");
	try
	{
		FileDB database;
		database.setStore(args[0]);
		FileDBAdapter databaseAdapter{ database };

		App app(databaseAdapter);
		app.launch();
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what() << '\n';
	}
}